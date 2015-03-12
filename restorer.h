// You must define an inline asm function here to solve stage3.


/*dealing with volatile registers, gonna put notes from class here to hopefully make this easier*/
/*NOTES:
 * *(int*)$esp dereference and print esp in debugger, works with all registers.
 *
 *
 *
 *
 *
 */
void restorer(void);
/*
void restorer(void){
	printf(1,"getting here\n");
}
*/
/*
int dummyfunc(void){
	printf(1, "hi \n");
	return 1;
}*/

__asm__("restorer:\n\t"
		        "pop %edx\n\t"
			"pop %edx\n\t"
			"pop %ecx\n\t"
			"pop %eax\n\t"
			"ret\n\t");

