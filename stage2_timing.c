#include "types.h"
#include "stat.h"
#include "user.h"
#include "signal.h"

#define LIMIT 1000000
void handle_signal(int signum)
{
	int refAddress;
	static int count = 0;
	
	if (count == LIMIT) {
		//printf(1, "count == %d\n", count);
		*((&refAddress+16)) -= 0x08; 
		return;
	}
	count++;

	__asm__ (	 "movl %ebp, %esp\n\t"		// pretend we are exiting the function already
			 "popl %ebp\n\t"		//
	 		 "popl %ecx\n\t"		// pop return address into ecx
 	    		 "popl %edx\n\t"		// pop arg into edx (throw away)
 			 "pushl %ecx\n\t"		// push return address back
	 		 "pushl %ebp\n\t"		// restore things so that leave can undo it again
	 		 "movl %esp, %ebp\n\t");
}
//need to be global so stack doesnt mess with them
int ut1;
int ut2;
int main(int argc, char *argv[])
{
	
	int x = 5;
	int y = 0;
	
	signal(SIGFPE, handle_signal);
	ut1 = uptime();
	
	x = x / y;
	ut2 = uptime();
	//printf(1, "ut1 is %d, ut2 is %d\n", ut1, ut2);
	int uttotal = ut2 - ut1;
	//printf(1, "total time is %d\n", uttotal);
	float uttotalf = (float)uttotal;
	float flim = (float)LIMIT;
	float avg = uttotalf / flim;
	avg = avg * 100000;
	int newavg = (int)avg;
	//printf(1, "avg is %d\n", newavg);
	printf(1, "Traps Performed: %d\n", LIMIT);
	printf(1, "Total Elapsed Time: %d\n", uttotal);
	printf(1, "Average Time Per Trap: %d\n", newavg);
	ut1 = 0;
	ut2 = 0;
	exit();
}
