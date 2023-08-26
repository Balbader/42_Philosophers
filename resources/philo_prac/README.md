# Processes vs Threads

+ you can have multiple threads in a process
+ Threads can share memory

+ Threads share all the file handlers
+ In Processes, file handlers are duplicated

# Race Conditions

Basically, whenever multiple threads are sharing memory and running simultaneously,<br>
if the threads proceed to have an impact on a shared variable, the order of action might be<br>
disrupted by the OS.<br>
The OS might pause one thread waiting for the other one to proceed and finish its action.<br>
Meanwhile, if both threads are supposed to run one after the other, the expected outcome will be <br>
of as one thread might have been paused longer than expected.<br>
In the case of a loop, if 2 threads are running simultaneously, once the 2nd thread has been put in pause, waiting for the process of the initial thread to run<br>
for 1 round, the waiting time might simply be prolonged as the OS might interpret the process of the 1st thread as still running and simply postpone longer<br>
the wait time of the 2nd thread.<br>

# M.U.T.E.X in C

In order to avoid the Race Condition, we can use M.U.T.E.X to lock & unlock the thread.<br>
This will allow us 
