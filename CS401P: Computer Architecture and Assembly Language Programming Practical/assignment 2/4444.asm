ORG 100h

JMP start

msg DB 13, 10, "Enter a string: $"
buffer DB 12	; buffer to store the input string (maximum length of 11 characters)
outputMsg DB 13, 10, "You entered: $"

colors DB 1Ah, 7Ch, 0Eh, 0Fh, 0Dh, 0Bh, 09h, 0Ah, 0Ch, 0Eh, 00h	; background and foreground color
start:
	MOV AH, 0
	MOV AL, 3
	INT 10h

	MOV AH, 09h
	MOV DX, msg
	INT 21h

	MOV AH, 0Ah
	MOV DX, buffer
	INT 21h

	MOV AH, 02h
	MOV BH, 00h
	MOV DH, 05h
	MOV DL, 00h
	INT 10h

	MOV AH, 09h
	MOV DX, buffer
	INT 21h

	MOV SI, buffer + 2	; start from second character (ignoring the length bytes)

	MOV CX, 11	; max length of input string
	MOV BL, 0	; index for accessing color codes

print_loop:

	MOV DL, [SI]	; load next char
	CMP DL, '$'
	JE end_print

; set background and foreground color
	MOV AH, 09h
	MOV BH, 0
	MOV BL, [colors + BX]
	AND BL, 0F7h
	MOV CX, 1
	INT 10h

; print character
	MOV AH, 02h
	INT 21h

	INC SI
	INC BL
	JMP print_loop

	end_print:

	; set background and foreground color for outputMag
	MOV AH, 09h
	MOV BH, 0
	MOV BL, 07h
	MOV CX, 11	; length of outputMag (including $ sign)
	MOV DX, outputMsg
	INT 21h

; put inputted string
	MOV AH, 09h
	MOV DX, buffer + 2
	INT 21h

; terminate program
	MOV AH, 4Ch
	MOV AL, 0
	INT 21h
	
END