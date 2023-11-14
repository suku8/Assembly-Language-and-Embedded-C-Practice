	MOV TMOD,#20H
	MOV TH1,#-9
	MOV SCON,#50H
	SETB TR1
	MOV A,#"t"
	ACALL TR
	MOV A,#"h"
	ACALL TR
	MOV A,#"i"
	ACALL TR
	MOV A,#"s"
	ACALL TR
	MOV A,#" "
	ACALL TR
	MOV A,#"i"
	ACALL TR
	MOV A,#"s"
	ACALL TR
	MOV A,#" "
	ACALL TR
	MOV A,#"d"
	ACALL TR
	MOV A,#"e"
	ACALL TR
	MOV A,#"m"
	ACALL TR
	MOV A,#"o"
	ACALL TR
	SJMP L2
TR:	MOV SBUF,A
L1: JNB TI,L1
	CLR TI
	RET
L2: NOP
END
	