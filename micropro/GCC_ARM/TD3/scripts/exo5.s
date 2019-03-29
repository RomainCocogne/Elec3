@description: converti un nombre hexa en ASCII
							@ directives de compilation ------------- 
  		.text
  		.align 4
  		.global _start
							@ Section de données --------------------------
	TABASCII:	.byte	0,0,0,0,0,0,0,0
	VALEUR:		.word	0xA76E2FF1
	TABCODE:	.byte	48,49,50,51,52,53,54,55,56,57,65,66,67,68,69,70


							@ Section de code --------------------------

_start:
		MOV		R0, #7				@init le for
		LDR		R1, VALEUR			@charge la val en hexa
		ADR 	R2, TABASCII		@charge l'adresse du resultat

LOOP:	
		ADR 	R4, TABCODE			@charge la table ASCII
		AND		R3, R1, #0xF 		@selectionne 4 bits de poid faible de la valeur
		LDRB 	R5, [R4, R3]		@charge la valeur ASCII correspondant aux 4bits
		STRB	R5,[R2, R0]			@la met dans le tableau resultat
		MOV 	R1, R1, LSR#4		@decalage de la valeur pour recuperer toutes les valeurs
@pour la boucle		
		SUB		R0,#1		
		CMP 	R0,#0	
		BGE		LOOP

		BX 		LR		@fin du programme
