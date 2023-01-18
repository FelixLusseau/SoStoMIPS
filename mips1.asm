.data
r:  	.word	0
x:  	.word	0
__TEMP__1:   .word 0
__TEMP__3:   .word 0
__TEMP__5:   .word 0

.text
main:
LABEL1 : 
	li $t7, 17
	sw $t7, x
LABEL2 : 
LABEL3 : 
addr3 : 
lw $t2, x
li $t3, 1
bne $t2, $t3, ELSE3001
	li $s1, 0
sw $s1, __TEMP__1
j EXIT3001
	ELSE3001 : 	li $s1, 1
sw $s1, __TEMP__1
EXIT3001 :
LABEL4 : 
	li $t4, 1
bne $s1, $t4, LABEL23
j LABEL6
LABEL5 : 
LABEL6 : 
	lw $t5, x
	li $t6, 2
	div $t5, $t6
	mfhi $s2
LABEL7 : 
	sw $s2, r
LABEL8 : 
LABEL9 : 
addr9 : 
lw $t0, r
li $t1, 0
beq $t0, $t1, ELSE3003
li $s3, 0
sw $s3, __TEMP__3
j EXIT3003
	ELSE3003 : 	li $s3, 1
sw $s3, __TEMP__3
EXIT3003 :
LABEL10 : 
	li $t2, 1
bne $s3, $t2, LABEL15
j LABEL12
LABEL11 : 
LABEL12 : 
	lw $t3, x
	div $s4, $t3, 2
LABEL13 : 
	sw $s4, x
LABEL14 : 
j EXIT3
LABEL15 : 
addr15 : 
lw $t4, r
li $t5, 1
beq $t4, $t5, ELSE3005
li $s5, 0
sw $s5, __TEMP__5
j EXIT3005
	ELSE3005 : 	li $s5, 1
sw $s5, __TEMP__5
EXIT3005 :
LABEL16 : 
	li $t6, 1
bne $s5, $t6, LABEL22
j LABEL18
LABEL17 : 
LABEL18 : 
	lw $t0, x
	mul $s6, $t0, 3
LABEL19 : 
	lw $t1, __TEMP__6
	addi $s0, $t1, 1
LABEL20 : 
	sw $s0, x
LABEL21 : 
j EXIT5
EXIT5 :
LABEL22 : 
EXIT3 :
j addr3
LABEL23 : 
LABEL24 : 
	li $v1, 0
	li $v0, 10
	syscall
LABEL25 : 
LABEL26 : 
	li $v1, 0
	li $v0, 10
	syscall
