; this program is to convert the given c code to assembly code
	AREA RESET,CODE
	ENTRY
	
	MOV R1,#4
	MOV R2,#5
	ADD R1,R2,R1,LSL #1
STOP B STOP
	END
