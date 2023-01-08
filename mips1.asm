.data
i:   .space 4
k:   .space 4
TABLE_TO_PRINT : .space 4

.text

main:
li $t7, 2
sw $t7, i
li $t7, 2
sw $t7, k
lw $t2, i
lw $t3, k
beq $t2, $t3, ELSE3001
li $s1, 0
j EXIT3001
ELSE3001 : li $s1, 1
EXIT3001 :
li $t4, 1
bne $s1, $t4, ELSE1
li $t7, 3
sw $t7, i
j EXIT1
ELSE1 :
li $t7, 4
sw $t7, k
EXIT1 :
lw $t5, i
sw $t5, TABLE_TO_PRINT
li $t6, 0
li $v0, 1
lw $a0, TABLE_TO_PRINT($t6)
syscall








