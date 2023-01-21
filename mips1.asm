.data
x:  	.word	0
__TEMP__1:   .word 0

.text
main:
LABEL1 : 
	li $t7, 0
	sw $t7, x
LABEL2 : 
LABEL3 : 
addr3 : 
lw $t2, x
li $t3, 42
beq $t2, $t3, ELSE3001
li $s1, 0
sw $s1, __TEMP__1
j EXIT3001
	ELSE3001 : 	li $s1, 1
sw $s1, __TEMP__1
EXIT3001 :
LABEL4 : 
	li $t4, 1
bne $s1, $t4, LABEL6
j LABEL12
LABEL5 : 
LABEL6 : 
	lw $t5, x
	addi $s2, $t5, 7
	sw $s2, __TEMP__2
LABEL7 : 
	lw $t8, __TEMP__2
	sw $t7, x
LABEL8 : 
LABEL9 : 
LABEL10 : 
	lw $a0, x
	li $v0, 1
	syscall
LABEL11 : 
j addr3
LABEL12 : 
LABEL13 : 
	li $v1, 0
	li $v0, 10
	syscall
