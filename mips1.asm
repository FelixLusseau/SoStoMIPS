.data
str0:	.asciiz	"yes"
str1:	.asciiz	"no"
str2:	.asciiz	"yes"
str3:	.asciiz	"no"
str4:	.asciiz	"yes"
str5:	.asciiz	"no"
__TEMP__1:   .word 0
__TEMP__2:   .word 0
__TEMP__3:   .word 0
__TEMP__4:   .word 0
__TEMP__5:   .word 0
__TEMP__6:   .word 0
__TEMP__7:   .word 0

.text
main:
LABEL1 : 
addr1 : 
li $t2, 17
li $t3, 42
bgt $t2, $t3, ELSE3001
	li $s1, 0
sw $s1, __TEMP__1
j EXIT3001
	ELSE3001 : 	li $s1, 1
sw $s1, __TEMP__1
EXIT3001 :
LABEL2 : 
	li $t4, 1
bne $s1, $t4, LABEL4
j LABEL7
LABEL3 : 
LABEL4 : 
addr4 : 
li $t5, 17
li $t6, 42
ble $t5, $t6, ELSE3002
	li $s2, 0
sw $s2, __TEMP__2
j EXIT3002
	ELSE3002 : 	li $s2, 1
sw $s2, __TEMP__2
EXIT3002 :
LABEL5 : 
	li $t0, 1
bne $s2, $t0, LABEL10
j LABEL7
LABEL6 : 
LABEL7 : 
LABEL8 : 
	la $a0, str0
	li $v0, 4
	syscall
LABEL9 : 
j EXIT2
LABEL10 : 
LABEL11 : 
	la $a0, str1
	li $v0, 4
	syscall
LABEL12 : 
EXIT2 :
LABEL13 : 
LABEL14 : 
addr14 : 
li $t1, 17
li $t2, 42
blt $t1, $t2, ELSE3003
	li $s3, 0
sw $s3, __TEMP__3
j EXIT3003
	ELSE3003 : 	li $s3, 1
sw $s3, __TEMP__3
EXIT3003 :
LABEL15 : 
	li $t3, 1
bne $s3, $t3, LABEL23
j LABEL17
LABEL16 : 
LABEL17 : 
addr17 : 
li $t4, 42
li $t5, 17
bge $t4, $t5, ELSE3004
	li $s4, 0
sw $s4, __TEMP__4
j EXIT3004
	ELSE3004 : 	li $s4, 1
sw $s4, __TEMP__4
EXIT3004 :
LABEL18 : 
	li $t6, 1
bne $s4, $t6, LABEL23
j LABEL20
LABEL19 : 
LABEL20 : 
LABEL21 : 
	la $a0, str2
	li $v0, 4
	syscall
LABEL22 : 
j EXIT4
LABEL23 : 
LABEL24 : 
	la $a0, str3
	li $v0, 4
	syscall
LABEL25 : 
EXIT4 :
LABEL26 : 
LABEL27 : 
addr27 : 
li $t0, 17
li $t1, 42
bge $t0, $t1, ELSE3005
	li $s5, 0
sw $s5, __TEMP__5
j EXIT3005
	ELSE3005 : 	li $s5, 1
sw $s5, __TEMP__5
EXIT3005 :
LABEL28 : 
	li $t2, 1
bne $s5, $t2, LABEL30
j LABEL36
LABEL29 : 
LABEL30 : 
addr30 : 
li $t3, 17
li $t4, 42
ble $t3, $t4, ELSE3006
	li $s6, 0
sw $s6, __TEMP__6
j EXIT3006
	ELSE3006 : 	li $s6, 1
sw $s6, __TEMP__6
EXIT3006 :
LABEL31 : 
	li $t5, 1
bne $s6, $t5, LABEL39
j LABEL33
LABEL32 : 
LABEL33 : 
addr33 : 
li $t6, 42
li $t0, 17
bge $t6, $t0, ELSE3007
	li $s0, 0
sw $s0, __TEMP__7
j EXIT3007
	ELSE3007 : 	li $s0, 1
sw $s0, __TEMP__7
EXIT3007 :
LABEL34 : 
	li $t1, 1
bne $s0, $t1, LABEL39
j LABEL36
LABEL35 : 
LABEL36 : 
LABEL37 : 
	la $a0, str4
	li $v0, 4
	syscall
LABEL38 : 
j EXIT7
LABEL39 : 
LABEL40 : 
	la $a0, str5
	li $v0, 4
	syscall
LABEL41 : 
EXIT7 :
LABEL42 : 
LABEL43 : 
	li $v1, 0
	li $v0, 10
	syscall
