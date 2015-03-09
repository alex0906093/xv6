// You must define an inline asm function here to solve stage3.

void restorer(void);

__asm__("restorer:\n\t"
		//	"some inline asm\n\t"
			"ret\n\t");
