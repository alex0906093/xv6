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

__asm__("restorer:\n\t"
		//	""
			"ret\n\t");
