#include <stdio.h>
#include <proc.h>

/*------------------------------------------------------------------------
 * userret  --  entered when a thread exits by return
 *------------------------------------------------------------------------
 */
void userret()
{
   /*
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
		// The thread will go to rescheduler and will look for next runnable thread and context switching will take place. 
		//it will store old threads data into stack and execute new runnable thread.
	}
	else
	{
		xtab[currxid].lastword=status;   
		xtab[currxid].xstate=XZOMBIE; // if queue is empty then state will changed to XZOMBIE
	}
	ualarm(usec,0);    // timer enabled
   */ 
   xtab[currxid].xstate = XFREE;
   printf("XT: Old threads never die; they just fade away. (id:%d)\n",currxid);
   /* find the next runnable thread to trun */
   resched();
   //The thread will go to rescheduler and will look for next runnable thread but if it didn't get any runnable(XREADY) thread then it will print "no threads to run" and exit the prigram.
}

static int newxid()
{
    int i, xid;
    static int nextproc =0;
  
    for(i=0; i<NPROC; i++) { /* find a free process entry */
        xid = nextproc;
        if((++nextproc) >= NPROC)
             nextproc = 0;
        if(xtab[xid].xstate == XFREE)
             return(xid);
    }
    printf("Error: run out of process table ! \n"); 
    exit(1);
}

/*------------------------------------------------------------------------
 *  xthread_create  -  create a process to start running a procedure
 *------------------------------------------------------------------------
 */
int xthread_create(int *procaddr,int nargs, int args)
{
    WORD *saddr;              /* stack address */
    WORD *ap;  
    struct xentry *xptr;
    int xid;

    xid = newxid();

    xptr = &xtab[xid];
    xptr->xstate = XREADY;

    saddr = (WORD *) xptr->xbase;

    ap = (&args) + nargs;
    for(; nargs > 0; nargs--)
        *(--saddr) = *(--ap); /* copy args onto new process' stack */
    *(--saddr)  = (int)userret;   /* sooner or later you will be there */     
    *(--saddr)  = (int)procaddr;
    --saddr;           /* for frame ebp; it's not important !? */
    saddr -= 2;        /* 2 words for si and di */
    xptr->xregs[SP] = (int) saddr ;

    return(xid);
}
