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

Shell commands need to be added manually to the shell on initialization,
usually this is done with the macro command `SHELL_COMMAND()`.
Please note that the command name is *not* written in quotes and can not have
any whitespaces!
```c
#include "shell.h"

SHELL_COMMAND(command_name, "command description", cmd_handler);

/* ... */
    shell_run(NULL, line_buf, SHELL_DEFAULT_BUFSIZE)
/* ... */
```

Please note, that the list of shell commands must be terminated with an empty entry.

## Task 2.2: Control the hardware
1.  Include the [`led.h`](https://api.riot-os.org/led_8h.html) file to get access
    to the `LED0_TOGGLE` macro.
2.  Write a command handler `toggle` in [`main.c`](main.c) that toggles the
    primary LED on the board using the `LED0_TOGGLE` macro.

[Read the Doc](https://api.riot-os.org/group__sys__shell.html)

[next task](../task-03)
