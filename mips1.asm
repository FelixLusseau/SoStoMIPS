.data
i:   .word 0
k:   .word 0
u:   .word 0
v:   .word 0

.text
main:
li $t7, 2
sw $t7, i
li $t7, 2
sw $t7, k
li $t7, 5
sw $t7, u
li $t7, 8
sw $t7, v
beq $t0, $t1, ELSE3001
li $s1, 0
j EXIT3001
ELSE3001 : li $s1, 1
EXIT3001 :
li $t2, 1
bne $s1, $t2, ELSE1
bne $t1, $t2, ELSE3002
li $s2, 0
j EXIT3002
ELSE3002 : li $s2, 1
EXIT3002 :
li $t3, 1
bne $s2, $t3, ELSE2
beq $t2, $t3, ELSE3003
li $s3, 0
j EXIT3003
ELSE3003 : li $s3, 1
EXIT3003 :
li $t4, 1
bne $s3, $t4, ELSE3
li $t7, 10
sw $t7, u
j EXIT3
ELSE3 :
li $t7, 10
sw $t7, v
EXIT3 :
li $t7, 10
sw $t7, u
j EXIT2
ELSE2 :
li $t7, 10
sw $t7, v
EXIT2 :
j EXIT1
ELSE1 :
li $t7, 4
sw $t7, k
EXIT1 :
blt $t3, $t4, ELSE3004
li $s4, 0
j EXIT3004
ELSE3004 : li $s4, 1
EXIT3004 :
li $t5, 1
bne $s4, $t5, ELSE4
li $t7, 3
sw $t7, i
j EXIT4
ELSE4 :
li $t7, 4
sw $t7, k
EXIT4 :
lw $a0, k
li $v0, 1
syscall
li $v1, 0
li $v0, 10
syscall
