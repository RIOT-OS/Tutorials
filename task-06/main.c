#include <stdio.h>
#include <string.h>

#include "shell.h"

extern int udp_send(int argc, char **argv);
extern int udp_server(int argc, char **argv);

static const shell_command_t shell_commands[] = {
    { "udp", "send udp packets", udp_send },
    { "udps", "start udp server", udp_server },
    { NULL, NULL, NULL }
};

int main(void)
{
    puts("This is Task-06");

    char line_buf[SHELL_DEFAULT_BUFSIZE];
    shell_run(shell_commands, line_buf, SHELL_DEFAULT_BUFSIZE);

    return 0;
}
