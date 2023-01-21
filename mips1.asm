.data
str10:	.asciiz	"no"
str0:	.asciiz	"yes"
str1:	.asciiz	"no"
str2:	.asciiz	"no"
str3:	.asciiz	"yes"
str4:	.asciiz	"17"
str5:	.asciiz	"42"
str6:	.asciiz	"yes"
str7:	.asciiz	"no"
str8:	.asciiz	"abc"
str9:	.asciiz	"yes"
__TEMP__1:   .word 0
__TEMP__2:   .word 0
__TEMP__3:   .word 0

.text
main:
LABEL1 : 
addr1 : 
li $t2, 17
li $t3, 42
ble $t2, $t3, ELSE3001
	li $s1, 0
sw $s1, __TEMP__1
j EXIT3001
	ELSE3001 : 	li $s1, 1
sw $s1, __TEMP__1
EXIT3001 :
LABEL2 : 
	li $t4, 1
bne $s1, $t4, LABEL7
j LABEL4
LABEL3 : 
LABEL4 : 
LABEL5 : 
	la $a0, str0
	li $v0, 4
	syscall
LABEL6 : 
j EXIT1
LABEL7 : 
LABEL8 : 
	la $a0, str1
	li $v0, 4
	syscall
LABEL9 : 
EXIT1 :
LABEL10 : 
LABEL11 : 
addr11 : 
li $t5, 17
li $t6, 42
beq $t5, $t6, ELSE3002
li $s2, 0
sw $s2, __TEMP__2
j EXIT3002
	ELSE3002 : 	li $s2, 1
sw $s2, __TEMP__2
EXIT3002 :
LABEL12 : 
	li $t0, 1
bne $s2, $t0, LABEL17
j LABEL14
LABEL13 : 
LABEL14 : 
LABEL15 : 
	la $a0, str2
	li $v0, 4
	syscall
LABEL16 : 
j EXIT2
LABEL17 : 
LABEL18 : 
	la $a0, str3
	li $v0, 4
	syscall
LABEL19 : 
EXIT2 :
LABEL20 : 
LABEL21 : 
addr21 : 
li $t8, 17
move $t1, $t8
li $t8, 42
move $t2, $t8
bne $t1, $t2, ELSE3003
	li $s3, 0
sw $s3, __TEMP__3
j EXIT3003
	ELSE3003 : 	li $s3, 1
sw $s3, __TEMP__3
EXIT3003 :
LABEL22 : 
	li $t3, 1
bne $s3, $t3, LABEL27
j LABEL24
LABEL23 : 
LABEL24 : 
LABEL25 : 
	la $a0, str6
	li $v0, 4
	syscall
LABEL26 : 
j EXIT3
LABEL27 : 
LABEL28 : 
	la $a0, str7
	li $v0, 4
	syscall
LABEL29 : 
EXIT3 :
LABEL30 : 
LABEL31 : 
LABEL32 : 
	li $t4, 1
bne $s4, $t4, LABEL37
j LABEL34
LABEL33 : 
LABEL34 : 
LABEL35 : 
	la $a0, str8
	li $v0, 4
	syscall
LABEL36 : 
j EXIT4
LABEL37 : 
LABEL38 : 
	la $a0, str9
	li $v0, 4
	syscall
LABEL39 : 
EXIT4 :
LABEL40 : 
LABEL41 : 
	li $v1, 0
	li $v0, 10
	syscall
