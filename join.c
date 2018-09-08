 #include<stdio.h>
#include <proc.h>
#include<signal.h>

int usec;
int xthread_join(int tid,int *tid_retval)
{
	int i=0;
	usec=ualarm(0,0);
        if(currxid==tid)                      // The Calling thread tries to join itself
        	return -1;
        if(xtab[tid].xstate==XFREE)           // Calling thread tring to join exited or nonexist thread.
        	return -2;
	
//case 1 currxid want's to join tid the tid executes first
    if(xtab[tid].xstate==XZOMBIE) 
    {
		*tid_retval=xtab[tid].lastword;   //this value can be obtained from status value (22)from exit function
		xtab[tid].xstate=XFREE;   
    }
//case 2 
    else
    {  
	    if(xtab[currxid].xstate==XRUN)    // Checking for run state
	    {
            	xtab[currxid].xstate=XJOIN;   // to suspend the execution of the thread tid and make currxid's state to XJOIN
            	xtab[tid].waitqueue[xtab[tid].rear] = currxid; //adding currxid to the waitqueue of tid
	    	xtab[tid].rear+=1;
            	resched();    
	    	// The thread will go to rescheduler and will look for next runnable thread(XREADY) and context switching will take place. 
		//it will store old threads data into stack and execute new runnable thread.
	
	    }
    }
    ualarm(usec,0);
    return 0;

}

