#include "types.h"
#include "stat.h"
#include "user.h"
#include "signal.h"

void handle_signal(int signum)
{
	static int count = 0;

	if (count == 100000) {
		printf(1, "count == %d\n", count);
		exit();
	}
	count++;

	__asm__ ("movl %ebp, %esp\n\t"		// pretend we are exiting the function already
			 "popl %ebp\n\t"		//
	 		 "popl %ecx\n\t"		// pop return address into ecx
     		 "popl %edx\n\t"		// pop arg into edx (throw away)
 			 "pushl %ecx\n\t"		// push return address back
	 		 "pushl %ebp\n\t"		// restore things so that leave can undo it again
	 		 "movl %esp, %ebp\n\t");
}

int main(int argc, char *argv[])
{
	int x = 5;
	int y = 0;

	signal(SIGFPE, handle_signal);
	
	x = x / y;

	printf(1, "Traps Performed: XXXX\n");
	printf(1, "Total Elapsed Time: XXXX\n");
	printf(1, "Average Time Per Trap: XXXXX\n");
	
	exit();
}