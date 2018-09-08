/*    proc.h    */
#include <stdio.h>
#include <stdlib.h>

typedef int WORD;
int eq;
#define PNREGS 5

#define NPROC 10

#define SP     0

/* state */
#define XFREE    0
#define XREADY   1
#define XRUN     2
#define XZOMBIE  3               //new states added for implementation//
#define XJOIN     4

struct xentry  {
       int  xid;
       WORD xregs[PNREGS];    /* save SP */
       WORD xbase;
       WORD xlimit;
       int  xstate;
       int lastword;
       int joinval;
       int waitqueue[NPROC];    //waiting queue of thread//
       int front;                
       int rear;
};

#define STKSIZE 8192 

extern struct xentry xtab[];
extern int currxid;


