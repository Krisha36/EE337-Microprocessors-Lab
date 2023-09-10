ORG 0H
LJMP MAIN
ORG 100H
MAIN:


CALL TAK_INP
HERE: SJMP HERE
ORG 130H
// ***


    MOV A, #0FH
	
TAK_INP:
	MOV A, P1
	ANL A, #0FH
    MOV R1, A
	
	
FUNC:
    
	MOV A, R1
    SUBB A, #00000001b
	JZ loop_sa
	MOV A,R1
	
	SUBB A, #00000011b
	JZ loop_re
	MOV A,R1
	
	SUBB A, #00000111b
	JZ loop_ga
	MOV A, R1
	
	
	SUBB A, #00001111b
	JZ loop_ma
    MOV A, R1
	//MOV P1,A

     loop_sa: lcall delay_sa
	       cpl p0.7
	       ljmp TAK_INP
		delay_sa:
			push 00h
			mov r0, #39
			h2: acall delay_50us
			djnz r0, h2
			pop 00h
			ret
		
		loop_re: lcall delay_re
	       cpl p0.7
	       ljmp TAK_INP
			
		delay_re:
			push 00h
			mov r0, #35
			h3: acall delay_50us
			djnz r0, h2
			
			pop 00h
			ret
			
	
       loop_ga: lcall delay_ga
	       cpl p0.7
	       ljmp TAK_INP	
		delay_ga:
			push 00h
			mov r0, #31
			h4: acall delay_50us
			djnz r0, h2
			pop 00h
			ret
		
          loop_ma: lcall delay_ma
			cpl p0.7
			ljmp TAK_INP		
		delay_ma:
			push 00h
			mov r0, #29
			h5: acall delay_50us
			djnz r0, h2
			pop 00h
			ret
			
			
		delay_50us:
		push 00h
		mov r0, #44
		h1: djnz r0, h1
		pop 00h
        RET
		
		
	
RET	
END