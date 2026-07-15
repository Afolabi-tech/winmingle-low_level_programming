global main
extern printf

section .data
    fmt db "Hello, WINMINGLE", 10, 0

section .text
main:
    push rbp
    mov rbp, rsp

    mov rdi, fmt
    xor eax, eax
    call printf

    mov eax, 0
    pop rbp
    ret
