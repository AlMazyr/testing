.data

hello_str:
    .string "Hello, world!\n"

    .set hello_str_length, . - hello_str - 1

.text

.globl main
.type main, @function

main:
    movl    $4, %eax /* 4 - system call write*/
    movl    $1, %ebx /* stdout */
    movl    $hello_str, %ecx
    movl    $hello_str_length, %edx
    int     $0x80
    movl    $1, %eax /* 1 - system call exit */
    movl    $0, %ebx 
    int     $0x80

    .size   main, . - main /* main size */
