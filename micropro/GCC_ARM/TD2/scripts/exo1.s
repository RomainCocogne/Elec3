							@ directives de compilation -------------
 
  		.text
  		.align 4 
  
  		.global _start

							@ Section de données --------------------------

	A:	.word	1
	B:	.word	2
	C:	.word	3

							@ Section de code --------------------------

_start:
			@if (a==b) c=a else c=b*8
			LDR	r0, A
			LDR	r1, B
			CMP	r0, r1
			BEQ	EGAL
			MOV	r2, r1, LSL #3	@c=b*8
			B	END_IF
	EGAL:	MOV r2, r0
	END_IF:	STR	r2, C
			BX LR		@fin du programme

