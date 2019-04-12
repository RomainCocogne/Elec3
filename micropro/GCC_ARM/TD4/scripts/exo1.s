@description: passage de parametres
@			  fonction max qui calcul le max de 2 nombres

							@ directives de compilation ------------- 
  		.text		
  		.align 4
  		.global _start
 							@ Section de données --------------------------
	A:	.word	0
	X: 	.word 	56
	Y: 	.word 	49

							@ Section de code --------------------------

_start:
		ldr 	r0, X
		str 	r0, [sp, #-4]!
		ldr 	r0, Y
		str 	r0, [sp, #-4]!
		bl 		max
		add 	sp, sp, #8
		str 	r0, A


		BX LR		@fin du programme


max: 	
		stmfd 	sp!, {r1, r2, lr}
		ldr 	r1, [sp, #16]
		ldr 	r2, [sp, #12]
		cmp 	r1, r2
		movgt 	r0, r1
		movle 	r0, r2
		ldmfd 	sp!, {r1, r2, lr}
		mov 	pc, lr
		