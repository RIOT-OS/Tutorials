[previous task](../task-06)

# Task 7: The GNRC network stack

This task is a little bit more advanced so don't be discouraged if things are
a little bit harder. With the knowledge you gathered from the previous tasks
you should be able to handle it.

It uses the [example applications in the RIOT repository](https://github.com/RIOT-OS/RIOT/tree/master/examples).

## Task 7.1: Compile the `gnrc_minimal` application
* Go to the [`gnrc_minimal` application](https://github.com/RIOT-OS/RIOT/tree/master/examples/gnrc_minimal)
* Compile and run on `native`
* Should print something like `My address is fe80::d403:24ff:fe89:2460`
* Ping RIOT instance from Linux:

```sh
ping6 <RIOT-IPv6-addr>%tapbr0
```
Note: on MAC use `bridge0` instead of `tapbr0`.

## Task 7.2: Extend `gnrc_minimal` application
* Add the `gnrc_udp` module to the application's [Makefile](Makefile)
* You can register for packets of a certain type and context (port 8888 in our
  case) using `gnrc_netreg_register()` from [`net/gnrc/netreg.h`](https://doc.riot-os.org/group__net__gnrc__netreg.html):
* The current thread can be obtained with the `sched_active_pid` variable from
  `sched.h`

```C
gnrc_netreg_entry_t server = {NULL, 8888, sched_active_pid};
gnrc_netreg_register(GNRC_NETTYPE_UDP, &server);
```

* Packets can be received using the IPC receive function [msg_receive()](https://doc.riot-os.org/group__core__msg.html#gae3e05f08bd71d6f65dc727624c4d5f7a):

```C
msg_t msg;
msg_receive(&msg);
```

Remember to remove the packet after reception (otherwise the packet buffer
will overflow)!

```C
#include "net/gnrc/pktbuf.h"

/* ... */

gnrc_pktsnip_t *pkt = (gnrc_pktsnip_t *)msg.content.ptr;
gnrc_pktbuf_release(pkt);
```


1.  Extend `gnrc_minimal` as such that it counts received UDP packets on port 8888.
2.  Use `netcat` on your host to test your application on native node.

## Task 7.3: Send your neighbor some messages again
* Go to the [`gnrc_networking` application](https://github.com/RIOT-OS/RIOT/tree/master/examples/gnrc_networking)
* Have a look in `udp.c` how packets are constructed and send
* Compile, flash, and run on the board `BOARD=samr21-xpro make all flash term`
* Type `help`
* Start UDP server on port 8888 using `udp server 8888`
* Get your IPv6 address using `ifconfig`
* Send your neighbor some messages using `udp send`

[Read the Doc](https://doc.riot-os.org/group__net__gnrc.html)

[next task](../task-08)
