.data
i:   .word 0
j:   .word 0
s:   .word 0


addr7 : 
lw $t2, j
lw $t3, i
ble $t2, $t3, ELSE3001
li $s1, 0
j EXIT3001
ELSE3001 : li $s1, 1
EXIT3001 :
li $t4, 1
bne $s1, $t4, ELSE1
lw $t5, s
lw $t6, j
add $s2, $t5, $t6
sw $s2, s
lw $t0, j
addi $s3, $t0, 1
sw $s3, j
j EXIT1
ELSE1 :
EXIT1 :
j addr7
li $v1, 0
li $v0, 10
syscall
