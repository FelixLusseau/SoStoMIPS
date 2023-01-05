.data
i:   .space 4
TABLE_TO_PRINT: .space 200

.text


main:
li $t7, 2
sw $t7, i

.data
STRING_TO_PRINT:   .asciiz "test"
.text

li $v0, 4
la $a0, STRING_TO_PRINT
syscall

li $t2, 0
li $v0, 1
lw $a0, ($t2)
syscall

lw $t3, i
sw $t3, TABLE_TO_PRINT
li $t4, 0
li $v0, 1
lw $a0, TABLE_TO_PRINT($t4)
syscall

li $a0, 0
li $v0, 10
syscall

