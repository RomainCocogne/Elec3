@description: matrices lecure/ecriture

							@ directives de compilation ------------- 
  		.text		
  		.align 4
  		.global _start
 							@ Section de données --------------------------
	mat:	.word	1,2,3,4,5,6,7,8,9 
	
							@ Section de code --------------------------

_start:
			bl 		get
						

			BX LR		@fin du programme




get:	
			mov 	pc, lr
