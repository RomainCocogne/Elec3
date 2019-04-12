@description: somme des carres d 'un tableau
@			  utilise le systeme de sous programmes

							@ directives de compilation ------------- 
  		.text		
  		.align 4
  		.global _start
 							@ Section de données --------------------------
	X: 	.word	1,2,3,4,5,6,7,8,9,10
	N:	.word	10
	R: 	.word	0
	
							@ Section de code --------------------------

_start:
			adr 	r0, X			
			bl 		somme_carre 
			str 	r1, R
			BX LR		@fin du programme

carre: 		
			stmfd 	sp!, {r1,lr}
			ldr		r1, [sp, #8]
			mul 	r0, r1, r1
			ldmfd 	sp!, {r1,lr}
			mov 	pc, lr

somme_carre:
			stmfd 	sp!, {r0,r2,r3,r4, lr}
			mov 	r1, #0
			mov 	r3, #0
	loop:
			ldr 	r2,	[r0], #4
			str 	r2, [sp, #-4]!
			mov 	r4, r0
			bl 		carre
			add 	sp, sp, #4
			add 	r1, r1, r0
			mov 	r0, r4
			add 	r3, r3, #1
			cmp 	r3, #10
			blt 	loop
			ldmfd 	sp!, {r0,r2, r3,r4, lr}
			mov 	pc, lr

