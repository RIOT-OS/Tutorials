#include <stdio.h>
#include <string.h>

#include "shell.h"

int echo(int argc, char **argv)
{
    /* ... */
}

static const shell_command_t shell_commands[] = {
    { NULL, NULL, NULL }
};

int main(void)
{
    puts("This is Task-02");

    char line_buf[SHELL_DEFAULT_BUFSIZE];
    shell_run(NULL, line_buf, SHELL_DEFAULT_BUFSIZE);

    return 0;
}
