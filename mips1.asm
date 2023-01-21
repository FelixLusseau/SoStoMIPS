.data
x:  	.word	0
__TEMP__1:   .word 0
__TEMP__2:  	.word	0
__TEMP__3:   .word 0
__TEMP__4:  	.word	0
__TEMP__5:  	.word	0
__TEMP__6:  	.word	0

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
bne $s1, $t4, LABEL18
j LABEL6
LABEL5 : 
LABEL6 : 
	lw $t5, x
	li $t6, 2
	div $t5, $t6
	mfhi $s2
	sw $s2, __TEMP__2
LABEL7 : 
addr7 : 
lw $t0, __TEMP__2
li $t1, 0
beq $t0, $t1, ELSE3003
li $s3, 0
sw $s3, __TEMP__3
j EXIT3003
	ELSE3003 : 	li $s3, 1
sw $s3, __TEMP__3
EXIT3003 :
LABEL8 : 
	li $t2, 1
bne $s3, $t2, LABEL13
j LABEL10
LABEL9 : 
LABEL10 : 
	lw $t3, x
	div $s4, $t3, 2
	sw $s4, __TEMP__4
LABEL11 : 
	lw $t7, __TEMP__4
	sw $t7, x
LABEL12 : 
j EXIT3
LABEL13 : 
	lw $t4, x
	mul $s5, $t4, 3
	sw $s5, __TEMP__5
LABEL14 : 
	lw $t5, __TEMP__5
	addi $s6, $t5, 1
	sw $s6, __TEMP__6
LABEL15 : 
	lw $t7, __TEMP__6
	sw $t7, x
LABEL16 : 
EXIT3 :
LABEL17 : 
j EXIT1
EXIT1 :
j addr3
LABEL18 : 
LABEL19 : 
	li $v1, 0
	li $v0, 10
	syscall
