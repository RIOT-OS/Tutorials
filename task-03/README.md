[previous task](../task-02)

# Task 3: Multithreading
Threads in RIOT are functions with signature
```C
void *thread_handler(void *arg);
```
Use [`thread_create()`](https://api.riot-os.org/group__core__thread.html#ga7e0403a9aa86ce0ec136f6b069d4434a) from
[`thread.h`](https://api.riot-os.org/group__core__thread.html) to start it
```C
thread_create(stack, sizeof(stack),
                    THREAD_PRIORITY_MAIN - 1,
                    THREAD_CREATE_STACKTEST,
                    thread_handler,
                    NULL, "thread");
```
thread_create returns a kernel_pid_t type, which can be helpful to assign to a variable (but not necessary for this lesson).

## Task 3.1: Start a thread
* Start the thread `"thread"` from within [`main()`](main.c#L15-L25)
* Run the application on `native`: `make all term`
* Check your output, it should read: `I'm in "thread" now`

[Read the doc](https://api.riot-os.org/group__core__thread.html)

[next task](../task-04)
