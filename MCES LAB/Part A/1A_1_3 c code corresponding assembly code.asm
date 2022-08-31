; this program is to convert the given code to assembly code
	AREA RESET,CODE
	ENTRY
	
	;3X+4Y+9Z,where X=2,Y=3 and Z=4
	MOV R1,#2 ; Let X=R1 <- 2
	MOV R2,#3 ; Let Y=R2 <- 3
	MOV R3,#4 ; Let Z=R3 <- 4
	ADD R1,R1,R1,LSL #1 ; R1 = R1+2*R1
	MOV R2,R2, LSL #2 ; R2 <- 4*R2
	ADD R3,R3,R3, LSL #3 ; R3 = R3 + 8*R3
	ADD R1,R1,R2 ; R1 = R1 + R2
	ADD R1,R1,R3 ; R1 = R1 +R3
STOP B STOP
	END
