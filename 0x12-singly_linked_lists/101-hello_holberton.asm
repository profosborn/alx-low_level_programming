section .data
    message db 'Hello, Holberton', 0
    format db '%s', 0

section .text
    global main
    extern printf

main:
    ; Set up the registers for the printf function call
    mov rdi, format
    mov rsi, message
    xor rax, rax
    call printf

    ; Exit the program
    xor rax, rax
    ret
