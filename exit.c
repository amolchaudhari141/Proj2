#include<stdio.h>
#include<proc.h>
#include<signal.h>

int usec;
void xthread_exit(int status)
{
	struct xentry *xptr;
	int i=0,xid;
	usec=ualarm(0,0);    // timer diabled
	if(!(xtab[currxid].front > xtab[currxid].rear))  //checking for non-empty waitqueue
	{
		for(i=xtab[currxid].front;i<xtab[currxid].rear;i++) 
		{
			xid=xtab[currxid].waitqueue[i];     
			xtab[xid].xstate=XREADY;   //change xstate of threads from waitqueue of current thread to XREADY
			xtab[xid].joinval=status;  // we will save the status(lastword) value into joinval of all threads who are in waitqueue. 
		
		}
		xtab[currxid].xstate=XFREE;    // make current thread free , terminate the execution.     
		resched();  
		// The thread will go to rescheduler and will look for next runnable thread(XREADY) and context switching will take place. 
		//it will store old threads data into stack and execute new runnable thread.
	}
	else
	{
		xtab[currxid].lastword=status;   
		xtab[currxid].xstate=XZOMBIE; // if queue is empty then state will changed to XZOMBIE
	}
	ualarm(usec,0);    // timer enabled
	
}




