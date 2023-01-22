.data
i:  	.word	0
p:  	.word	0
__TEMP__1:   .word 0
__TEMP__2:  	.word	0
__TEMP__3:  	.word	0
str0:  	.asciiz	"haha "
str2:  	.asciiz	"=120"

.text
main:
LABEL1 : 
LABEL23 : 
LABEL24 : 
LABEL25 : 
	addi $t9, $zero,40
	sub $sp,$sp,$t9
	sw $s0,0($sp)
	sw $s1,4($sp)
	sw $s2,8($sp)
	sw $s3,12($sp)
	sw $s4,16($sp)
	sw $s5,20($sp)
	sw $s6,24($sp)
	sw $s7,28($sp)
	sw $ra,32($sp)
	sw $fp,36($sp)
	jal fact
	lw $s0,0($sp)
	lw $s1,4($sp)
	lw $s2,8($sp)
	lw $s3,12($sp)
	lw $s4,16($sp)
	lw $s5,20($sp)
	lw $s6,24($sp)
	lw $s7,28($sp)
	lw $ra,32($sp)
	lw $fp,36($sp)
	addi $sp,$sp,40
LABEL26 : 
LABEL27 : 
LABEL28 : 
	la $a0, 5
	li $v0, 4
	syscall
	la $a0, str2
	li $v0, 4
	syscall
LABEL29 : 
LABEL30 :
LABEL31 : 
	li $v1, 0
	li $v0, 10
	syscall
	
fact:
LABEL2 : 
	li $t7, 1
	sw $t7, p
LABEL3 : 
	li $t7, 2
	sw $t7, i
LABEL4 : 
addr4 : 
lw $t2, i
li $t3, 5
ble $t2, $t3, ELSE3001
	li $s1, 0
sw $s1, __TEMP__1
j EXIT3001
	ELSE3001 : 	li $s1, 1
sw $s1, __TEMP__1
EXIT3001 :
LABEL5 : 
	li $t4, 1
bne $s1, $t4, LABEL19
j LABEL7
LABEL6 : 
LABEL7 : 
	lw $t5, p
	lw $t6, i
	mul $s2, $t5, $t6
	sw $s2, __TEMP__2
LABEL8 : 
	lw $t7, __TEMP__2
	sw $t7, p
LABEL9 : 
LABEL10 : 
	lw $t0, i
	addi $s3, $t0, 1
	sw $s3, __TEMP__3
LABEL11 : 
	lw $t7, __TEMP__3
	sw $t7, i
LABEL12 : 
LABEL13 : 
LABEL14 : 
	lw $a0, i
	li $v0, 1
	syscall
LABEL15 : 
LABEL16 : 
LABEL17 : 
	la $a0, str0
	li $v0, 4
	syscall
LABEL18 : 
j EXIT1
EXIT1 :
j addr4
LABEL19 : 
LABEL20 : 
LABEL21 : 
	lw $a0, p
	li $v0, 1
	syscall
LABEL22 : 
	jr $ra
