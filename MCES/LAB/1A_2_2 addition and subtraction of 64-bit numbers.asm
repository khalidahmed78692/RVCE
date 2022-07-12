; addition and subtraction of 64-bit numbers using 32-bit registers
	AREA RESET,CODE
	ENTRY
	
	;LSB,MSB
	;R1,R2 --> FIRST NUMBER
	;R3,R4 --> SECOND NUMBER
	;R5,R6 --> TO STORE RESULT
	;R0 --> TO STORE LOCATION
	
	LDR R0,=NUM1
	LDR R1,[R0]
	LDR R2,[R0,#4]
	LDR R3,[R0,#8]
	LDR R4,[R0,#12]
	ADDS R6,R2,R4
	ADC R5,R1,R3
	LDR R0,=addition
	STR R5,[R0]
	STR R6,[R0,#4]
	SUBS R6,R2,R4
	SBC R5,R1,R3
	LDR R0,=subtraction
	STR R5,[R0]
	STR R6,[R0,#4]
	
STOP B STOP

NUM1 DCD &12345678,&87654321,&ABCDEFAC,&FEDCBAAB
	
	AREA MEMORY,DATA
addition SPACE 8
subtraction SPACE 8
	END
