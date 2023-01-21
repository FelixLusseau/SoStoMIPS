.data
str0:	.asciiz	"abc"
str1:	.asciiz	"no abc"
str2:	.asciiz	"def"
str3:	.asciiz	"yes"
str4:	.asciiz	"ghij"
str5:	.asciiz	"no ghij"
str6:	.asciiz	"no *"
s:  	.asciiz	"def"
__TEMP__1:   .word 0
__TEMP__2:   .word 0
__TEMP__3:   .word 0

.text
main:
LABEL1 : 
LABEL2 : 
LABEL3 : 
addr3 : 
lw $t2, s
li $t3, "abc"
beq $t2, $t3, ELSE3001
li $s1, 0
sw $s1, __TEMP__1
j EXIT3001
	ELSE3001 : 	li $s1, 1
sw $s1, __TEMP__1
EXIT3001 :
LABEL4 : 
	li $t4, 1
bne $s1, $t4, LABEL9
j LABEL6
LABEL5 : 
LABEL6 : 
LABEL7 : 
	la $a0, str0
	li $v0, 4
	syscall
LABEL8 : 
j EXIT1
LABEL9 : 
addr9 : 
lw $t5, s
li $t6, "def"
beq $t5, $t6, ELSE3002
li $s2, 0
sw $s2, __TEMP__2
j EXIT3002
	ELSE3002 : 	li $s2, 1
sw $s2, __TEMP__2
EXIT3002 :
LABEL10 : 
	li $t0, 1
bne $s2, $t0, LABEL15
j LABEL12
LABEL11 : 
LABEL12 : 
LABEL13 : 
	la $a0, str1
	li $v0, 4
	syscall
LABEL14 : 
j EXIT2
LABEL15 : 
addr15 : 
lw $t1, s
li $t2, "ghij"
beq $t1, $t2, ELSE3003
li $s3, 0
sw $s3, __TEMP__3
j EXIT3003
	ELSE3003 : 	li $s3, 1
sw $s3, __TEMP__3
EXIT3003 :
LABEL16 : 
	li $t3, 1
bne $s3, $t3, LABEL21
j LABEL18
LABEL17 : 
LABEL18 : 
LABEL19 : 
	la $a0, str2
	li $v0, 4
	syscall
LABEL20 : 
j EXIT3
LABEL21 : 
LABEL22 : 
	la $a0, str3
	li $v0, 4
	syscall
LABEL23 : 
EXIT3 :
LABEL24 : 
LABEL25 : 
	li $v1, 0
	li $v0, 10
	syscall
