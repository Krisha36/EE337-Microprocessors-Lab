ORG 0H
LJMP MAIN
ORG 100H
MAIN:
CALL FILT
HERE: SJMP HERE
ORG 130H
// *****************
FILT:
// ADD YOUR CODE HERE

MOV R2 , #8H
MOV R0 , #67H
MOV R1 , #77H
MOV 5FH, #00H
MOV 5EH, #00H
MOV 5DH, #00H

AVG:

MOV A , @R0
DEC R0
ADD A , @R0
DEC R0
ADD A , @R0
DEC R0
ADD A , @R0
MOV B , #4H
DIV AB
MOV @R1 , A
DEC R1
INC R0
INC R0
DJNZ R2 , AVG


RET
END