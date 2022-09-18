; this program is to convert the given c code to assembly code
	AREA RESET,CODE
	ENTRY
	
	MOV R1,#4
	MOV R2,#5
	ADD R1,R2,R1,LSL #1
STOP B STOP
	END

;Using MUL directive

;	AREA RESET,CODE
;	ENTRY
	
;	MOV R0,#3; -->A
;	MOV R1,#2; -->B
;	MOV R2,#2; MULTIPLIER
;	;ADD R0,R1,R0,LSL #1;
;	MLA R3,R0,R2,R1
	
;STOP B STOP
;	END
