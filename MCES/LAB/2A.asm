; Program to find the smallest and largest element in a list

	AREA RESET,CODE
	ENTRY
	
	LDR R0,=LIST ; R0 <-- Pointer to the list
	LDR R6,N ; List size is stored in R6
	LDR R1,=RES ; Location where the smallest element is to be stored
	LDR R2,[R0],#4 ; First element is loaded to register R2
	LDR R3,[R0],#4 ; Second element is loaded to register R3, here pre-increment is done before fetching the second element
	CMP R2,R3 ; Comparing if first or second element is larger
	BGT MORE ; If R2 is greater than R3 then this BGT statement is executed
	MOV R4,R3 ; else this statement
	MOV R5,R2 ; R5 holds smallest element
LOOP
	CMP R6,#2
	BEQ EXIT
	LDR R2,[R0],#4
	SUB R6,R6,#1; Decrement the size of the list
	CMP R2,R4
	BGT MORE1
	CMP R2,R5
	BLS LESS
	B LOOP
	
LESS
	MOV R5,R2
	B LOOP

MORE
	MOV R4,R2 ; Move R2,which is greater to R4, here R4 is storing greatest element
	MOV R5,R3; smaller element is moved to R5
	B LOOP
	
MORE1
	MOV R4,R2
	B LOOP
	
EXIT
	STR R4,[R1] ; Largest element is stored at memory location specified by R1
	ADD R1,R1,#4
	STR R5,[R1] ; Smallest element is stored at memory location specified by R1, but in the previous step memory location is incremented by 4
STOP B STOP
LIST DCD &64,&05,&96,&10,&65
N DCD 5
	
	AREA MEMORY,DATA
RES SPACE 8
	END