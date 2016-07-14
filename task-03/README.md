# Task 3: Multithreading
Threads in RIOT are functions with signiture
```C
void *thread_handler(void *arg);
```
Use [`thread_create()`](http://doc.riot-os.org/thread_8h.html#a87c94d383e64a09974fc8665f82a99b3) from `thread.h` to start it
```C
pid = thread_create(stack, sizeof(stack),
                    THREAD_PRIORITY_MAIN - 1,
                    THREAD_CREATE_STACKTEST,
                    thread_handler,
                    NULL, "thread");
```

## Task 3.1: Start a thread
* Start the thread `"thread"` from within `main()`
* Check the output (might need reset/reboot)
* Check the existence of the thread using `ps` shell command
