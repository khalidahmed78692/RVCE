; this program is to add and subtract 32-bit numbers from memory because immediate mode supports only 8-bits
	AREA RESET,CODE
	ENTRY
	
	LDR R0,=NUM
	LDR R1,[R0]
	LDR R2,[R0,#4]
	
	ADD R3,R1,R2
	LDR R0,=addition
	STR R3,[R0]
	
	SUB R3,R1,R2
	LDR R0,=Subtraction
	STR R3,[R0]
	
STOP B STOP

NUM DCD &CCCCCCCC,&BBBBBBBB
	
	AREA MEMORY,DATA
addition SPACE 4
Subtraction SPACE 4
	END
