#include <stdio.h>
#include <string.h>

#include "shell.h"
#include "thread.h"

char stack[THREAD_STACKSIZE_MAIN];

void *thread_handler(void *arg)
{
    puts("I'm in \"thread\" now");
    return NULL;
}

int main(void)
{
    puts("This is Task-03");

    /* ... */

    char line_buf[SHELL_DEFAULT_BUFSIZE];
    shell_run(NULL, line_buf, SHELL_DEFAULT_BUFSIZE);

    return 0;
}
