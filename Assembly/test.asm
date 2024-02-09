section data
    a db 09h
    b db 02h
    c dw ?
section data ends

section code
    assume cs:code, ds:data
start:
    mov ax, data
    mov ds, ax

    mov al, a   ; Load value of a into AL
    mov bl, b   ; Load value of b into BL
    add al, bl  ; Add values of a and b
    mov c, ax   ; Store the result in c

    ; Display the result (c) - using DOS interrupt 21h
    mov ah, 9    ; DOS function for printing a string
    lea dx, c    ; Load effective address of c into DX
    int 21h      ; Make DOS system call

    ; Exit the program
    mov ah, 4Ch  ; DOS function for exit with return code
    int 21h      ; Make DOS system call

code ends
end start
