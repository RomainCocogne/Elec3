@ Fichier arith.s  
@ arm-none-eabi-as -g -o arith.o arith.s
@ arm-none-eabi-ld -o appli.elf arith.o
@ export PATH=/home/bilavarn/GCC_ARM/insight/bin:$PATH
@ export TCL_LIBRARY=/home/bilavarn/cours_micropro/GCC_ARM/insight/share/tcl8.4/ 
@ arm-none-eabi-insight appli.elf

@ Programme de vérification des exercices du TD1
@ Parametres: R0, R1, R2, R3 
@ Variables locales: R4, R5, R6, R7, R8, R9

							@ directives de compilation --------------------------
 
  		.text
  		.align 4 
  
  		.global _start

							@ Section de données --------------------------


							@ Section de code --------------------------

_start:
							@ DECALAGES
		mov 	r0, #222  
		mov 	r0, r0, LSR#2  

		mov 	r0, #222  
		mov 	r0, r0, ASR#2  		@ sur 32 bits

		mov 	r0, #222  
		mov 	r0, r0, LSL#2  

		mov 	r0, #222  
		mov 	r0, r0, ASL#2  	
			
		mov 	r0, #996  
		mov 	r0, r0, LSR#2  

		mov 	r0, #996  
		mov 	r0, r0, ASR#2  		@ sur 32 bits

		mov 	r0, #996  
		mov 	r0, r0, LSL#3  
		mov 	r0, #996  
		mov 	r0, r0, ROR#3		@ sur 32 bits  

						@ ADDITIONS
		mov 	r1, #0x08000000  
		mov 	r2, #0x07000000  
		adds	r0, r1, R2
			
		mov 	r1, #0x08000000  
		mov 	r2, #0x08000000  
		adds	r0, r1, R2
			
		mov 	r1, #0x40000000  
		mov 	r2, #0x30000000  
		adds	r0, r1, R2
			
		mov 	r1, #0x40000000  
		mov 	r2, #0x40000000  
		adds	r0, r1, R2
			
		mov 	r1, #0x08000000  
		mov 	r2, #0xFFFFFFFF  
		adds	r0, r1, R2
			
		mov 	r1, #0xF0000000  
		mov 	r2, #0xFFFFFFFF  
		adds	r0, r1, R2
			
		mov 	r1, #0x80000000  
		mov 	r2, #0xFFFFFFFF  
		adds	r0, r1, R2

		mov 	r1, #0x80000000  
		mov 	r2, #0x80000000  
		adds	r0, r1, R2
		
						@ SOUSTRACTIONS
		mov 	r1, #0x08000000  
		mov 	r2, #0x04000000  
		subs	r0, r1, R2

		mov 	r1, #0x04000000  
		mov 	r2, #0x08000000  
		subs	r0, r1, R2

		mov 	r1, #0x08000000  
		mov 	r2, #0x08000000  
		subs	r0, r1, R2

		mov 	r1, #0xF0000000  
		mov 	r2, #0x7F000000  
		subs	r0, r1, R2

		mov 	r1, #0x7F000000  
		mov 	r2, #0xF0000000  
		subs	r0, r1, R2
			
		BX	LR			@ Fin du programme

