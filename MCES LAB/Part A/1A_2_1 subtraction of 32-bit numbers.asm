; this program is to subtract 32-bit numbers from memory because immediate mode only supports 8-bits
	AREA RESET,CODE
	ENTRY
	
	LDR R0,=NUM1
	LDR R1,[R0]
	LDR R2,[R0,#4]
	;LDR R2,[R0]
	SUB R1,R1,R2
	LDR R0,=RESULT
	STR R1,[R0]
	
STOP B STOP

NUM1 DCD &CCCCCCCC,&AAAAAAAA
	
	AREA MEMORY,DATA
RESULT SPACE 4
	END
