							@ directives de compilation -------------
 
  		.text
  		.align 4 
  
  		.global _start

							@ Section de données --------------------------

	A:	.word	32


							@ Section de code --------------------------

_start:
			
			LDR	r0, A
			ANDS r1, r0, #7
			CMP	r1, #0
			BNE	ELSE
			MOV r3, r0, LSR #3
			B END_IF
	ELSE:	MOV r3, #0
	END_IF:	BX LR		@fin du programme

