@description: algo a bulle
							@ directives de compilation ------------- 
  		.text
  		.align 4
  		.global _start
							@ Section de données --------------------------
	TAB:	.word	3, 107, 27, 12, 322, 155, 63   
	N:		.word	7 
							@ Section de code --------------------------

_start:  
		LDR		r2, N
MAINLOOP:
@initialise r0 au debut de tab, r2 a len(TAB) et r6 qui compte le nb de permutations a 0
		ADR		r0, TAB
		MOV 	r6, #0 
@for i=0, i<N-1, i++	
		MOV		r1, #0  @i=0
LOOP:	
		LDR		r3, [r0], #4 @load tab[i] puis i++
		LDR		r4, [r0]     @load tab[i] 
		CMP 	r3, r4       @ r3 > r4 ? si oui: 
		STRGT 	r3, [r0]	 @permutations
		STRGT 	r4, [r0, #-4]
		ADDGT 	r6, r6, #1	 @ajout d'une permutation ds r6
@pour le for
		ADD		r1, r1, #1
		CMP 	r1, r2
		BLT 	LOOP
EXIT:
		CMP 	r6, #0 @si il n'y a plus de permutations, finir l'algo
		BGT 	MAINLOOP
		BX 		LR		@fin du programme
