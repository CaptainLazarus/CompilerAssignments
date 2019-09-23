# Name: Aditya Sujith Gudimetla
# Roll No: 17009
# Reg No: 207

.file "what.c"
.text
.globl what 
.type what, @function 
what:
.LFB0:
    pushq %rbp              # This saves current stack pointer
    movq %rsp, %rbp         # rbp = rsp (Base pointer is shifted)
    movq %rdi, -24(%rbp)    # 1st function parameter being saved. (Memory address of array)
    movl %esi, -28(%rbp)    # 2nd function parameter being saved. (Number of elements in array)
                            # Since it's an integer only 4 bytes are allocated.
    movl $1, -12(%rbp)      # Loads the value of 1 into a position in the stack (i=1)
    jmp .L2                 # Jumping to L2
.L8:
    movl -12(%rbp), %eax    # eax = i   
    cltq                    # rax = eax = i
    leaq 0(,%rax,4), %rdx   # rdx = 4*rax = 4*i
    movq -24(%rbp), %rax    # rax = data[0] 
    addq %rdx, %rax         # rax = &data[0] + rdx = data[i]
    # ------------------------------------------------------------  rax = data[i] 
    movl (%rax), %eax       # eax = rax
    movl %eax, -4(%rbp)     # temp = data[i]
    movl -12(%rbp), %eax    # eax = i
    subl $1, %eax           # eax = eax - 1 = i-1;    
    movl %eax, -8(%rbp)     # j = i-1 ; Initialisation of j for inner loop.
    jmp .L3                 # jump to L3
.L7:
    movl -8(%rbp), %eax     # eax = j
    cltq                    # rax = eax
    leaq 0(,%rax,4), %rdx   # rdx = 4*j
    movq -24(%rbp), %rax    # rax =  data[0]
    addq %rdx, %rax         # rax = 4*j + rax = data[j] 
    movl (%rax), %eax       # eax = rax = data[j]
    # ----------------------------------------------------------- eax = data[j]
    cmpl %eax, -4(%rbp)     # if ( data[j] >= data[i] )
    jle .L9                 # jump to L9
    movl -8(%rbp), %eax     # else : eax = j
    cltq                    # rax = j
    leaq 0(,%rax,4), %rdx   # rdx = 4*j
    movq -24(%rbp), %rax    # rax = data[0]
    addq %rdx, %rax         # rax = data[j]
    movl -8(%rbp), %edx     # edx = j
    movslq %edx, %rdx       # rdx = edx = j
    addq $1, %rdx           # rdx = rdx + 1 
    leaq 0(,%rdx,4), %rcx   # rcx = 4*(j+1)
    movq -24(%rbp), %rdx    # rdx = data[0]
    addq %rcx, %rdx         # rdx = data[j+1]
    # --------------------------------------------------- rdx = data[j+1]
    movl (%rax), %eax       # eax = data[j]
    movl %eax, (%rdx)       # data[j+1] = data[j]
    subl $1, -8(%rbp)       # j = j-1   (Dcrement)
.L3:
    cmpl $0, -8(%rbp)       # while ( j >= 0)   (Inner loop starts)
    jns .L7                 #  jump to L7       
    jmp .L6                 # else jump to L6   
.L9:
    nop
.L6:
    movl -8(%rbp), %eax     # eax = j
    cltq                    # rax = eax
    addq $1, %rax           # rax=j+1;
    leaq 0(,%rax,4), %rdx   # rdx = 4*j+1;
    movq -24(%rbp), %rax    # rax = &data[0]
    addq %rax, %rdx         # rdx = data[j+1]
    # ----------------------------------------------------- rdx = data[j+1] 
    movl -4(%rbp), %eax     # eax = temp
    movl %eax, (%rdx)       # data[j+1] = temp
    addl $1, -12(%rbp)      # i++ (Outer loop ends here as it goes back to the loop condition below)
.L2:
    movl -12(%rbp), %eax    # eax = i (Main loop variable)
    cmpl -28(%rbp), %eax    # if (no > i):  (Main Loop)
    jl .L8                  # Jump L8     
    nop                     # else: No operation
    popq %rbp               # Pop the base register ( Function completed )
    ret                     # Return 
.LFE0:
    .size what, .-what
    .ident "GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
    .section .note.GNU-stack,"",@progbits