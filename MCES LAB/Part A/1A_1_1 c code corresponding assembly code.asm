; this program is to convert the given c code to assembly code
	AREA RESET,CODE
	ENTRY
	
	MOV R0,#00; -->A
	MOV R1,#20; -->B
	MOV R2,#14; -->C
	MOV R3,#27; -->D
	
	;Arithematic operations (Addition and Subtraction)
	ADD R0,R1,R2
	SUB R0,R0,R3
STOP B STOP
	END ; This end is not necessary, if you don't write this you'll get a warning that END directive is missing, but it is not an error. Without END directive 
	    ; your code runs fine.
