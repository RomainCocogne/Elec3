@description: somme des val >0 dans un tableau
@for (i=0; i<10; i++)     if (X[i]>0)  S = S + X[i] ; 
							@ directives de compilation ------------- 
  		.text
  		.align 4
  		.global _start
							@ Section de données --------------------------
	S:	.word	0
	X:	.word	0, 1, -2, 3, -4, 5, -6, 7, -8, 9

							@ Section de code --------------------------

_start:

		ADR		r2, X
		LDR		r5, S
		MOV		r0, #0
LOOP:	LDR		r6, [r2], #4
		CMP		r6, #0
		ADDGT	r5, r5, r6
		ADD		r0, r0, #1
		CMP 	r0, #10
		BLT 	LOOP 
EXIT:	STR 	r5, S

		BX LR		@fin du programme
