@description: matrices lecure/ecriture

							@ directives de compilation ------------- 
  		.text		
  		.align 4
  		.global _start
 							@ Section de données --------------------------
	mat:	.word	1,2,3,4,5,6,7,8,9 
	m:		.word	3
	
							@ Section de code --------------------------

_start:
			adr 	r0, mat
			str 	r0,[sp,#-4]!
			ldr 	r0, m
			str 	r0,[sp,#-4]!
			mov		r0, #2
			str 	r0,[sp,#-4]!
			mov 	r0, #0
			str 	r0,[sp,#-4]!
			bl 		get
			add 	sp, sp,#16

			adr 	r0, mat
			str 	r0,[sp,#-4]!
			ldr 	r0, m
			str 	r0,[sp,#-4]!
			mov		r0, #2
			str 	r0,[sp,#-4]!
			mov 	r0, #0
			str 	r0,[sp,#-4]!
			mov 	r0, #0xf
			str 	r0,[sp,#-4]!
			bl 		set
			add 	sp, sp,#20


			BX 		LR		@fin du programme




get:	
			stmfd 	sp!, {r1,r2,r3,r4,r5,lr}
			@lire param ds pile
			ldr		r1, [sp, #36] @mat
			ldr 	r2, [sp, #32] @m
			ldr 	r3, [sp, #28] @i
			ldr 	r4, [sp, #24] @j

			@calcul adresse
			mul 	r5, r4,r2
			add 	r5,r5,r3
			add 	r5,r1,r5,lsl #2
			@lecture ds matrice
			ldr 	r0,[r5]
			ldmfd 	sp!, {r1,r2,r3,r4,r5,lr}
			mov 	pc, lr


set:	
			stmfd 	sp!, {r0,r1,r2,r3,r4,r5,lr}
			@lire param
			ldr		r1, [sp, #44] @mat
			ldr 	r2, [sp, #40] @m
			ldr 	r3, [sp, #36] @i
			ldr 	r4, [sp, #32] @j
			ldr 	r0, [sp, #28] @x
			@calcul adresse
			mul 	r5, r4,r2
			add 	r5,r5,r3
			add 	r5,r1,r5,lsl #2
			@ecriture ds matrice
			str 	r0, [r5]
			ldmfd 	sp!, {r0,r1,r2,r3,r4,r5,lr}
			mov 	pc, lr






