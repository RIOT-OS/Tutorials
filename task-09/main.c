/*
 * Copyright (C) 2015-18 Freie Universität Berlin
 * Copyright (C) 2016 Hochschule für Angewandte Wissenschaften Hamburg
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     examples
 * @{
 *
 * @file
 * @brief       Example application for demonstrating the RIOT network stack
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 * @author      Martine Lenders <m.lenders@fu-berlin.de>
 * @author      Peter Kietzmann <peter.kietzmann@haw-hamburg.de>
 *
 * @}
 */

#include <stdio.h>

#include "shell.h"
#include "msg.h"
#include "thread.h"

#include "net/gnrc.h"
#include "net/gnrc/netif.h"
#include "net/gnrc/ipv6.h"

#define MAIN_QUEUE_SIZE     (8)
static msg_t _main_msg_queue[MAIN_QUEUE_SIZE];

extern int udp_cmd(int argc, char **argv);

static const shell_command_t shell_commands[] = {
    { "udp", "send data over UDP and listen on UDP ports", udp_cmd },
    { NULL, NULL, NULL }
};

#ifdef MODULE_GNRC_SIXLOWPAN
static char _stack[THREAD_STACKSIZE_MAIN];

static void *_ipv6_fwd_eventloop(void *arg)
{
    (void)arg;

    msg_t msg, msg_q[8];
    gnrc_netreg_entry_t me_reg = GNRC_NETREG_ENTRY_INIT_PID(GNRC_NETREG_DEMUX_CTX_ALL,
                                                            thread_getpid());

    msg_init_queue(msg_q, 8);

    gnrc_netreg_register(GNRC_NETTYPE_SIXLOWPAN, &me_reg);

    while(1) {
        msg_receive(&msg);
        gnrc_pktsnip_t *pkt = msg.content.ptr;
        if(msg.type == GNRC_NETAPI_MSG_TYPE_SND) {
            gnrc_pktsnip_t *ipv6 = gnrc_pktsnip_search_type(pkt, GNRC_NETTYPE_IPV6);
            ipv6_addr_t addrs[GNRC_NETIF_IPV6_ADDRS_NUMOF];
            int res;
            ipv6 = ipv6->data;

            ipv6_hdr_t *ipv6_hdr =(ipv6_hdr_t *)ipv6;

            /* get the first IPv6 interface and prints its address */
            gnrc_netif_t *netif = gnrc_netif_iter(NULL);
            res = gnrc_netif_ipv6_addrs_get(netif, addrs, sizeof(addrs));
            if (res < 0) {
                /* an error occurred, just continue */
                continue;
            }
            for (unsigned i = 0; i < (res / sizeof(ipv6_addr_t)); i++) {
                if ((!ipv6_addr_is_link_local(&addrs[i])) &&
                    (!ipv6_addr_is_link_local(&ipv6_hdr->src)) &&
                    (!ipv6_addr_is_link_local(&ipv6_hdr->dst)) &&
                    (!ipv6_addr_equal(&addrs[i], &(ipv6_hdr->src)))) {
                    char addr_str[IPV6_ADDR_MAX_STR_LEN];
                    printf("IPv6 ROUTER: forward from src = %s ",
                           ipv6_addr_to_str(addr_str, &(ipv6_hdr->src),
                                            sizeof(addr_str)) );
                    printf("to dst = %s\n",
                           ipv6_addr_to_str(addr_str, &(ipv6_hdr->dst),
                                            sizeof(addr_str)));
                }
            }
        }
        gnrc_pktbuf_release(pkt);
    }
    /* never reached */
    return NULL;
}
#endif

int main(void)
{
    /* we need a message queue for the thread running the shell in order to
     * receive potentially fast incoming networking packets */
    msg_init_queue(_main_msg_queue, MAIN_QUEUE_SIZE);
    puts("RIOT network stack example application");

#ifdef MODULE_GNRC_SIXLOWPAN
    thread_create(_stack, sizeof(_stack), (THREAD_PRIORITY_MAIN - 4),
                         THREAD_CREATE_STACKTEST, _ipv6_fwd_eventloop, NULL, "ipv6_fwd");
#endif
    /* start shell */
    puts("All up, running the shell now");
    char line_buf[SHELL_DEFAULT_BUFSIZE];
    shell_run(shell_commands, line_buf, SHELL_DEFAULT_BUFSIZE);

    /* should be never reached */
    return 0;
}
