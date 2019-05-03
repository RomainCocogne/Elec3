@description: test des propriétés des nombres de la forme abc tq
@			  a**2+b**2+c**2=abc
							@ directives de compilation ------------- 
  		.text		
  		.align 4
  		.global _start
 							@ Section de données --------------------------
	a:			.word	3
	b:			.word 	7
	c:			.word 	1
	test_res:	.word	0
	
							@ Section de code --------------------------

_start:
				ldr 	r0, a
				str 	r0, [sp,#-4]!
				ldr 	r0, b
				str 	r0, [sp,#-4]!
				ldr 	r0, c
				str 	r0, [sp,#-4]!
				bl 		test_cube
				add 	sp, sp, #12		
					

				BX 		LR		@fin du programme

test_cube:
				stmfd 	sp!, {r1,r2,r3,r4,r5,lr}
				@lire param ds pile
				ldr 	r1, [sp, #32] @a
				ldr 	r2, [sp, #28] @b
				ldr 	r3, [sp, #24] @c
				mov 	r0, #0
				bl 		valeur_nombre
				mov 	r4, r0
				bl 		somme_cube
				mov 	r5, r0
				cmp 	r4, r0
				moveq 	r0, #1
				ldmfd 	sp!, {r1,r2,r3,r4,r5,lr}
				mov 	pc, lr



valeur_nombre:

