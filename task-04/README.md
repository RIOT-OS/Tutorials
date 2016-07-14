[previous task](../task-03)

# Task 4: Timers
[`xtimer`](http://doc.riot-os.org/group__sys__xtimer.html) is the high level API of RIOT to multiplex hardware timers.
For this task we need only the following functions

    - `xtimer_now()` to get current system time in microseconds
    - `xtimer_sleep(sec)` to sleep `sec` seconds
    - `xtimer_usleep(usec)` to sleep `usec` microseconds

## Task 4.1: Use `xtimer`
* Note the inclusion of `xtimer` in the [Makefile](Makefile)
```Makefile
USEMODULE += xtimer
```
* Create a thread in [`main.c`](main.c#L12) that prints the current system time every 2 seconds
* Check the existence of the thread with `ps` shell command

[Read the doc](http://doc.riot-os.org/group__sys__xtimer.html)

[next task](../task-05)
