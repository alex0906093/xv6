#include "types.h"
#include "user.h"
#include "signal.h"
int *p;

void handler(int signum, siginfo_t info)
{
	printf(1,"Handler called, error address is 0x%x type is %d, signum is %d\n", info.addr, info.type, signum);
	if(info.type == PROT_READ)
	{
		printf(1,"ERROR: Writing to a page with insufficient permission.\n");
		mprotect((void *) info.addr, sizeof(int), PROT_READ | PROT_WRITE);
		//printf(1, "[handler] completed second mprotect call [Val: %d | Addr: 0x%x]\n",*((int *)info.addr),info.addr);
	}
	else
	{
		printf(1, "ERROR: Didn't get proper exception, this should not happen.\n");
		exit();
	}
} 
int main(void)
{
	signal(SIGSEGV, (sighandler_t)handler);
 	p = (int *) sbrk(1);
 	//printf(1, "[main] allocated p [Val: %d | Addr: 0x%x]\n",p,&p);
 	mprotect((void *)p, sizeof(int), PROT_READ);
 	//printf(1, "[main] completed first mprotect call [Val: %d | Addr: 0x%x]\n",p,&p);
 	*p=100;
 	printf(1, "COMPLETED: value is %d, expecting 100!\n", *p);
 	
 	exit();
}
