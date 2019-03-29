							@ directives de compilation ------------- 
  		.text
  		.align 4
  		.global _start
							@ Section de données --------------------------
	A:	.word	9
	B:	.word	2
	C:	.word	1

							@ Section de code --------------------------

_start:
			LDR	r0, A
			LDR	r1, B
			LDR	r2, C

			CMP	r0, r1
			BGT	R0SUPR1
			CMP	r1, r2
			BGT	R1SUPR2
			MOV	r3, r2
			B	END_IF
R0SUPR1:	CMP	r0, r2
			BGT	R0SUPR2
			MOV	r3,r2
			B END_IF
R0SUPR2		MOV	r3, r0
			B	END_IF
R1SUPR2:	MOV	r3, r1

END_IF:		BX LR		@fin du programme

