// You must define an inline asm function here to solve stage3.


/*dealing with volatile registers, gonna put notes from class here to hopefully make this easier*/
/*NOTES:
 *
 *
 *
 *
 *
 */
void restorer(void);

__asm__("restorer:\n\t"
		//	"some inline asm\n\t"
			"ret\n\t");
