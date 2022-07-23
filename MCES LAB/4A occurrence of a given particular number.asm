; 4th program, to find the number of occurences of a given number in a list

	AREA RESET,CODE
	ENTRY
	
	LDR R0,=ARR; Pointer to list
	MOV R1,#0; Register to count the number of elements in a list visited
	MOV R2,#0; particular number, how many times it has came across
	LDR R3,OCC; number to be checked in a list as to how many times it has occured
	LDR R5,N; load the size of the list
LOOP
	LDR R4,[R0]; load the number to register R4 pointed by the register R0
	CMP R3,R4; compare current number and the number to be checked
	BNE SKIP; if both are not equal then go to SKIP check point else execute the next statement
	ADD R2,R2,#1; if above condition fails then increment the R2, which means we have found the number in a list
	
SKIP
	ADD R1,R1,#1; increment the Register R1, which means we have checked this many numbers in a list
	ADD R0,R0,#4; increment the pointer to point to the next number in a list
	CMP R5,R1; compare if all the numbers of a list a checked, if all the numbers are checked then exit from the LOOP else go to LOOP check point
	BNE LOOP ; if above condition leads to non-negative number then go to LOOP check point
	LDR R0,=NUM; finally load the address of result variable NUM to register R0
	STR R2,[R0]; and store the result in a memory pointed by the register R0
STOP B STOP; stop the program

ARR DCD 0,1,1,9,1,1,6,1,10,1; list of numbers
OCC DCD 1;number to be checked as to how many times it has occured in the given list
N DCD 10;size of the list
	AREA MEMORY,DATA;for storing the data to the memory, this statement is written
NUM SPACE 4;allocating 4 bytes of free memory to the varible NUM
	END;finally end the program
