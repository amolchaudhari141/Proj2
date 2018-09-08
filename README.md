# Proj2
Thread 
# PART-I
 In this project we are making this thread package preemptive so we will not be using yield
function .
 We have first tried to implement timesharing in this project for which we need to provide
handler routine . We have used signal &amp; ualarm to provide the interrupt in the program .
 signals are generated when any event occurs and it requires attention. It is a kind of interrupt.
Handler():-
 We have created handler function in which we have added the different inbuilt functions like
 sigemptyset () – which initializes the signal set pointed to by set
 sigaddset() - This adds the signal to the set of signals already recorded in set.
 sigpromask() - Allows the calling process to change the signal mask of the calling thread
 Above functions are used to enable same SIGALRM to be delivered.
 We have used the logic which will change the state of current (running) thread to
“XREADY” state then we have called reschedule to run another process.
 We have initialized ualarm in all necessary files where we have given interrupt using
ualarm before context switching.
 We created delay function in xmain file and used in foo(), bar() function to add some delay
which will help to get correct output because it helps in timesharing.
# PART –II
As we have tried to run the thread package using alarm and interrupt handler. Now we are going to
implement threads which will show the execution of thread execution state cycle.
State Transition Diagram:-
Following diagram shows the thread execution lifecycle.

 First when thread is created using create function it goes into XREADY state and starts its
execution once it goes into XRUN state.
 Thread goes into XRUN state once we call reschedule() which finds the next runable thread.
 When Thread is in running state there are several possibilities which can happen. The current
thread might get into XZOMBIE state or it gets free.
 We have created “join” to show the XJOIN state in thread lifecycle. When another thread
wants join running thread it goes into XJOIN state.
 XZMOBIE is the state where once running thread calls exit() function it goes into this state.
This is the state where thread “foo” gets exited but it will not get deleted from process table as
there are some other threads (bar, oof) which are using recourses of thread “foo”.
 XFREE is the state where once threads complete its execution.
exit.c:
The aim of this file creation is to implement the xthread_exit function.
This xthread_exit() function terminates the execution of calling thread.In this function we have
first passed the parameter “status” which is termination value of the exiting thread (here we
have taken it as 22).
We have diabled the ualarm to avoid inconsistancy
When a thread terminates its recourses (stack) are not released until another thread perform
xthread_join on it. This condition we have implemented as follows
Join.c:-
The aim of this file is to implement the function which will execute the JOIN state. This is the state
where the runable thread (bar) joins the current running thread (foo).Then The current running
thread(foo) will wait till the runable threads goes into running state and (bar) completes its execution.
There can be two cases
# Thread A wants to join thread B
Case I) Thread B will first get execute completely and if it is in XZOMBIE state we will store its last
word and we will recycle the thread.

Case II) It will suspend the execution of thread B and Thread A will go to XJOIN state.
