      .data
c:   .space 4
i:   .space 4
j:   .space 4
p:   .space 4
v:   .space 4
w:   .space 4

.text

main:
li $t7, 8
sw $t7, i
li $t7, 4
sw $t7, c
lw $t2, i
lw $t3, c
sub $t1, $t2, $t3
sw $t1, j
lw $t3, j
lw $t4, j
add $t2, $t3, $t4
sw $t2, v
lw $t4, v
lw $t5, i
add $t3, $t4, $t5
sw $t3, p
lw $t5, v
lw $t6, p
sub $t4, $t5, $t6
sw $t4, w
