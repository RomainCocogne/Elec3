@description: exercice sur la parite (ex3 dans l'archive)
							@ directives de compilation ------------- 
  		.text
  		.align 4
  		.global _start
							@ Section de données --------------------------
		TAB:	.word	7,8,9,6,5,4,3,4,5,6
		N:		.word	10

							@ Section de code --------------------------

_start:

			ADR		R2, TAB
			BL 		NB_PAIRS
			

			BX 		LR		@fin du programme


NB_PAIRS:	
			STR 	LR, [SP, #-4]!
			MOV		R3, #0
			MOV		R4, #0
			LDR		R5, N
	LOOP:	LDR 	R1, [R2], #4
			BL		PARITE
			CMP 	R0,#0
			ADDEQ	R3, R3, #1
			ADD 	R4, R4, #1
			CMP 	R4, R5
			BLT 	LOOP
			MOV 	R0, R3
			LDR 	LR, [SP], #4
			MOV		PC, LR

PARITE: 	
			AND		R0, R1, #0x1
			MOV		PC, LR
