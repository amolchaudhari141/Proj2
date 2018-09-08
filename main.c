
#include <stdio.h>
#include <proc.h>
#include<signal.h>
#include<stdbool.h>

int usec;

extern void xmain();

struct xentry xtab[10];
int currxid;
void handler()
{

	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set,SIGALRM);
	sigprocmask(SIG_UNBLOCK,&set,NULL);
	xtab[currxid].xstate=XREADY;

	resched();
   
}
    
main(int argc, char *argv[])
{
   register struct xentry *xptr;
   struct xentry m;
   int i;
   int xidxmain;
   signal(SIGALRM,handler);
   usec=ualarm(0,0);
   for(i=0 ; i < NPROC; i++)
   {
      xptr = &xtab[i];
      xptr->xid = i;
      xptr->xlimit =  (WORD) malloc(STKSIZE);
      xptr->xbase = xptr->xlimit + STKSIZE - sizeof(WORD);
      xptr->xstate = XFREE;
      xptr->front=0;
      xptr->rear=0;
   }

   /* the first thread runs user's xmain with id 0*/
   xidxmain = xthread_create(xmain, 2, argc, argv);
   ualarm(2000000,0);
   ctxsw(m.xregs, xtab[xidxmain].xregs);
   /* never be here */
  ualarm(usec,0);
}

