// -- DO NOT CHANGE ANYTHING UNTIL THE **** LINE--//
ORG 0H
LJMP MAIN
ORG 100H
MAIN:
ACALL DET
HERE: SJMP HERE
ORG 130H
// *****************
DET:
// ADD YOUR CODE HERE
MOV A, 61H
MOV B, 62H
MUL AB
MOV R1, A
MOV R2, B
MOV A, 60H
MOV B, 63H
MUL AB
SUBB A, R1
MOV 71H, A
MOV A, B
SUBB A, R2
MOV 70H, A
RET
END