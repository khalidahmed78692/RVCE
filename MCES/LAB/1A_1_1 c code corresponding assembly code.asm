; this program is to convert the given c code to assembly code
	AREA RESET,CODE
	ENTRY
	
	MOV R0,#00
	MOV R1,#20
	MOV R2,#14
	MOV R3,#27
	
	;Arithematic operations (Addition and Subtraction)
	ADD R0,R1,R2
	SUB R0,R0,R3
STOP B STOP
	END
