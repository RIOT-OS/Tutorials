[previous task](../task-01)

# Task 2: Custom shell handlers
## Task 2.1: A simple echo command handler
Extend the `echo()` function in [`main.c`](main.c#L8) to print the first argument to the command handler
```c
int cmd_handler(int argc, char **argv);
```
Any parameters following the shell command in the RIOT shell are accessible
from the `argv` variable. `argc` contains the number of parameters used to call
this shell command plus one for the name of the command.

Your function must return `0` if it runs successfully and or anything else if
an error occurs.

Shell commands need to be added manually to the shell on initialization
```c
#include "shell.h"

static const shell_command_t shell_commands[] = {
    { "command name", "command description", cmd_handler },
    { NULL, NULL, NULL }
};

/* ... */
    shell_run(commands, line_buf, SHELL_DEFAULT_BUFSIZE)
/* ... */
```

Please note, that the list of shell commands must be terminated with an empty entry.

## Task 2.2: Control the hardware
1.  Include the [`led.h`](https://doc.riot-os.org/led_8h.html) file to get access
    to the `LED0_TOGGLE` macro.
2.  Write a command handler `toggle` in [`main.c`](main.c) that toggles the
    primary LED on the board using the `LED0_TOGGLE` macro.

[Read the Doc](https://doc.riot-os.org/group__sys__shell.html)

[next task](../task-03)
