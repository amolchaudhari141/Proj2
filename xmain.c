

#include <stdio.h>
#include<proc.h>
extern void xthread_exit();
extern int xthread_join();
 
int xidfoo, xidbar, xidoof;
int *ptr;
int x=0;
delay(int k)
{
    int s;
    for (s=0;s<k*1000000;s++);

}

int foo(int f)
{
   int i,j,retval;
	//retval=xthread_join(xidbar,&ptr);
	
	if(retval==-1 || retval==-2)
	{
		 printf("\n error= %d\n",retval);	
		return;
	}
   //retval=xthread_join(xidbar,22);   // foo tries to join foo
		 //printf("\n foo tries to join bar which is not exist, returnvalue of join is %d\n",retval);
	for(i=0;i<100;i++)
	{
		printf("This is foo %d, %d\n", f, x++);
		//xthread_exit(22);
	    delay(100);	
		//xthread_join(xidbar,22);
	}
	xthread_exit(22);
}
int bar(int p, int q)
{  
	int j,i,retval;
	//retval=xthread_join(xidfoo,&ptr);

	if(retval==-1 || retval==-2)
	{
		printf("\n error= %d\n",retval);	
		return;
	}
   	for(j=0;j<100;j++)
	{
	      	printf("This is bar %d, %d\n", p-q, x++);
		//xthread_exit(22); 
    		delay(100);
		//xthread_join(xidoof,22); 
    	}
xthread_exit(22);
}

int oof(int c)
{
	int l,retval;
	//retval=xthread_join(xidfoo,&ptr);
	if(retval==-1 || retval==-2)
	{
		printf("\n error= %d\n",retval);		
		return;
	}   	
	for(l=0;l<100;l++)
	{
		printf("This is oof %d, %d\n", c, x++);
	
		delay(100);
    	}
xthread_exit(22);
}
xmain(int argc, char* argv[])
{
	   xidfoo = xthread_create(foo, 1, 7);	

	   xidbar = xthread_create(bar, 2, 32, 12);
	
	   //xidoof = xthread_create(oof, 1,8);
	   
}





