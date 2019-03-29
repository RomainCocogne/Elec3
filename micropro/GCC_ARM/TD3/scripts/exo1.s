@description: operations sur tableau: somme de tout les termes entre 2 tableaux
@for (i=0; i<10; i++)     S = S + X[i] + Y[i];  
							@ directives de compilation ------------- 
  		.text
  		.align 4
  		.global _start
							@ Section de données --------------------------
	S:          .word       0
	X:          .word       0, 1, 2, 3, 4, 5, 6, 7, 8, 9
	Y:          .word       0, 1, 2, 3, 4, 5, 6, 7, 8, 9

							@ Section de code --------------------------

_start:
		ADR	r2, X                   
		ADR	r4, Y                   
		LDR	r5, S                   
		MOV	r0, #0                  
LOOP:	LDR	r6,[r2],#4 
		LDR	r7,[r4],#4 
		ADD	r8,r7,r6
		ADD	r5,r5,r8
		ADD	r0,r0,#1
		CMP	r0,#10
		BLT	LOOP
EXIT:	STR	r5, S
		BX LR		@fin du programme
