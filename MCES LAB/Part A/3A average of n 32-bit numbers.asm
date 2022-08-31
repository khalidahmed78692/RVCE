; Program to find average of n 32-bit numbers

	AREA RESET,CODE
	ENTRY
	
	LDR R0,=LIST; R0--> Pointer to the list
	LDR R1,N; R1--> holds number of numbers
	MOV R3,#0; R3--> holds sum of all the numbers and here it is initialized to 0, which means it is cleared
	LDR R4,[R0],#4; --> load first number to R4 and increment the pointer to point to the next number
LOOP              ; this is the check point where in below code if conditions are met then will be back to this check point
	ADD R3,R3,R4; R3 one by one adds all the numbers and stores in it
	SUB R1,R1,#1; if one number is fetched then decrement the number of numbers by one, so that loop get end after conditions get false
	LDR R4,[R0],#4; load the next number in to R4 so that in the next iteration this number can be added
	CMP R1,#0; since every time R1 is decremented by one so we check if all the numbers are read, if it so then come out of the loop
	BNE LOOP; this condition checks if zero flag is not set, if it is not set then it goes back to the LOOP check point, if zero flag is set then this 
			; instruction is not executed
	MOV R0,#0; clear the R0, so that quotent can be handled by R0
	LDR R1,N; load number of numbers in R1, so that it helps in division (basically subtraction here because subtraction logic is used for division)
LOOP2       ; this is second check point, which constitutes the loop
	SUBS R3,R3,R1; here subtraction is performed and flag is set, if this subtraction set the negative flag then, immediate next and next-to-next is not executed
	ADDPL R0,R0,#1 ; if above subtraction leads to positive result then quotient is incremented by one
	BPL LOOP2 ; if the flag is 0 or positive then this instruction gets executed, which points the PC to LOOP2 check point
	
	ADD R3,R3,R1 ; once the above branch instruction fails, then this instruction gets executed, which basically is the remainder after division
	LDR R2,=Q; load the address of the quotient to the register R2
	STR R0,[R2]; and store it
	LDR R2,=R; load the address of the remainder to the register R2
	STR R3,[R2]; and store it
STOP B STOP; finally stop the execution

LIST DCD 1,2,3,4,5,6,7,8,9,10,11;this is the list of first n natural numbers
N DCD &B; this tells how many numbers are there in the list
	AREA MEMORY,DATA
Q SPACE 4; 4 bytes space is allocated to store the quotient
R SPACE 4; 4 bytes space is allocated to store the remainder
	END; end the program
	
	
	;output is stored usually in 0x40000000 and 0x40000004 memory addresses
	;first address to store quotient and second to store the remainder
