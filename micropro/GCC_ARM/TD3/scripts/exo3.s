@description: for (i=1; i<=9; i++)   Y[i-1] = X[i] + X[i-1]; 

							@ directives de compilation ------------- 
  		.text
  		.align 4
  		.global _start
							@ Section de données --------------------------
	X:	.word	0, 1, 2, 3, 4, 5, 6, 7, 8, 9    
	Y:	.word	0, 0, 0, 0, 0, 0, 0, 0, 0

							@ Section de code --------------------------

_start:
		ADR 	r2, X
		ADR 	r4, Y
		MOV 	r0, #1
LOOP:	
		LDR 	r6, [r2]
		LDR 	r7, [r2,#4]!
		ADD 	r8, r6, r7 
		STR 	r8, [r4], #4
		ADD		r0, r0, #1
		CMP 	r0, #10
		BLT 	LOOP
			
EXIT:	
		BX LR		@fin du programme
