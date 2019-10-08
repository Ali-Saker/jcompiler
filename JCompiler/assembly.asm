.text
.globl main
int_to_str:
move $t2, $a0
li $t3, 1
li $t4, 10
loop_int_to_str :
rem $t2, $t1, $t4 # $t2 %= 10
addi $t2, $t2, 48 # $t2 += '0'
div $t1, $t1, $t4 #$t1 /= 10
addi $sp, $sp, -4
sw $t2, 4($sp)
addi $t3, $t3, 1
beq $t1, $zero, end_loop_int_to_str
j loop_int_to_str
end_loop_int_to_str :
addi $t0, $t3, 1
sll $t0, $t0, 2
move $a0, $t0
li $v0, 9
syscall
move $t0, $v0
move $v1, $t3
addi $t1, $t3, 1
sw $t1, 0($t0)
loop_int_to_str_empty_stack:
lw  $t1, 4($sp)
add $sp, $sp, 4
addi $t0, $t0, 4
sw  $t1, 0($t0)
addi $t3, $t3, -1
beq $t3, $zero, end_int_to_str_empty_stack
j loop_int_to_str_empty_stack
end_int_to_str_empty_stack :
jal $ra
#float in $f12
#ref in $v0
float_to_str :
#integer part
mov.s $f0, $f12
cvt.w.s $f1, $f0
mfc1 $a0, $f1
addi $sp, $sp, -4
sw $ra, 4($sp)
jal int_to_str
lw $ra, 4($sp)
addi $sp, $sp, 4
move $t0, $v0
move $t1, $v1
#save registers
addiu $sp, $sp, -8
sw $t0, 4($sp)
sw $t1, 8($sp)
#fraction part 5 decimal digitsW
li.s $f3, 10000.0
	cvt.s.w $f1, $f1 # back to float
sub.s $f1, $f0, $f1
	mul.s $f1, $f1, $f3
cvt.w.s $f1, $f1
mfc1 $a0, $f1
addi $sp, $sp, -4
sw $ra, 4($sp)
jal int_to_str
lw $ra, 4($sp)
addi $sp, $sp, 4
move $t2, $v0
move $t3, $v1
sw $t0, 4($sp)
sw $t1, 8($sp)
addiu $sp, $sp, 8
add $a0, $t1, $t3
addi $a0, $a0, 2
addi $a0, $a0, 2
sll $a0, $a0, 2
li $v0, 9
syscall
move $t7, $v0
addi $t1, $t1, -1
li $t5, 0
add $a0, $t1, $t3
addi $a0, $a0, 1
sw $a0, 0($t7)
# $t0 + $t2
loop_fp_to_str :
beq $t5, $t1, end_loop_fp_to_str
addi $t5, $t5, 1
addi $t0, $t0, 4
addi $t7, $t7, 4
lw  $t6, 0($t0)
sw  $t6, 0($t7)
j loop_fp_to_str
end_loop_fp_to_str :
li $t6, 46
addi $t7, $t7, 4
sw  $t6, 0($t7)
li $t5, 0
loop_fp_to_str1 :
beq $t5, $t3, end_loop_fp_to_str1
addi $t5, $t5, 1
addi $t2, $t2, 4
addi $t7, $t7, 4
lw  $t6, 0($t2)
sw  $t6, 0($t7)
j loop_fp_to_str1
end_loop_fp_to_str1 :
j $ra
ali.second.ali.three.a.a0:
addi $sp,$sp,0
li $t1,4
sw $t1,0($sp)
addi $sp,$sp,-4
lw $t1,4($sp)
addiu $sp,$sp,4
sw $t1,16($s7)
endali.second.ali.three.a.a0:
addi $sp,$sp,0
jr $ra
ali.second.ali.three.b.b0:
addi $sp,$sp,0
li $t1,4
sw $t1,0($sp)
addi $sp,$sp,-4
lw $t1,4($sp)
addiu $sp,$sp,4
sw $t1,16($s7)
li $t1,2
sw $t1,0($sp)
addi $sp,$sp,-4
lw $t1,4($sp)
addiu $sp,$sp,4
sw $t1,20($s7)
endali.second.ali.three.b.b0:
addi $sp,$sp,0
jr $ra
ali.second.ali.three.c.pr:
li $a0,48
li $v0,9
syscall
move $t1,$v0
addiu $sp,$sp,-4
sw $t1,4($sp)
li $t2,11
sw $t2,0($t1)
li $t2,103
sw $t2,4($t1)
li $t2,103
sw $t2,8($t1)
li $t2,103
sw $t2,12($t1)
li $t2,103
sw $t2,16($t1)
li $t2,103
sw $t2,20($t1)
li $t2,103
sw $t2,24($t1)
li $t2,103
sw $t2,28($t1)
li $t2,103
sw $t2,32($t1)
li $t2,103
sw $t2,36($t1)
li $t2,103
sw $t2,40($t1)
li $t2,103
sw $t2,44($t1)
lw $t0 ,4($sp)
addiu $sp, $sp, 4
lw $t1,0($t0)
addiu $t0,$t0,4
loop0:
beq $t1,$zero,end0
lw $a0 ,0($t0)
li $v0, 11
syscall
addiu $t1,$t1,-1
addiu $t0,$t0,4
j loop0
end0:
endali.second.ali.three.c.pr:
move $sp,$fp
jr $ra
ali.second.ali.three.c.c0:
addi $sp,$sp,0
li $t1,4
sw $t1,0($sp)
addi $sp,$sp,-4
lw $t1,4($sp)
addiu $sp,$sp,4
sw $t1,16($s7)
li $t1,2
sw $t1,0($sp)
addi $sp,$sp,-4
lw $t1,4($sp)
addiu $sp,$sp,4
sw $t1,20($s7)
endali.second.ali.three.c.c0:
addi $sp,$sp,0
jr $ra
main :
move $fp,$sp
addiu $sp, $sp ,-12
la $t1,ali.second.ali.three.c.pr
sw $t1,0($gp)
la $t1,ali.second.ali.three.c.pr
sw $t1,-4($gp)
move $t1, $s7
li $a0,28
li $v0, 9
syscall
move $t2,$v0
sw $t1,0($t2)
sw $zero,4($t2)
li $t1,2
sw $t1,8($t2)
move $t1,$gp
addi $t1,$t1,-4
sw $t1,12($t2)
addi $sp,$sp,-16
sw $fp,4($sp)
sw $ra,8($sp)
sw $s7,12($sp)
sw $t2,16($sp)
move $s7,$t2
la $t1,ali.second.ali.three.c.pr
sw $t1,-4($gp)
jal ali.second.ali.three.d.d0
lw $fp,4($sp)
lw $ra,8($sp)
lw $s7,12($sp)
addi $sp,$sp,12
lw $t1,4($sp)
addiu $sp,$sp,4
sw $t1,-4($fp)
addiu $v0,$fp,-4
lw $t1,0($v0)
sw $t1,0($sp)
addiu $sp,$sp,-4
lw $t1,4($sp)
addi $v0,$t1,16
lw $t1,0($v0)
sw $t1,4($sp)
addiu $v0,$fp,-4
lw $t1,0($v0)
sw $t1,0($sp)
addiu $sp,$sp,-4
lw $t1,4($sp)
addi $v0,$t1,20
lw $t1,0($v0)
sw $t1,4($sp)
addiu $v0,$fp,-4
lw $t1,0($v0)
sw $t1,0($sp)
addiu $sp,$sp,-4
lw $t1,4($sp)
addi $v0,$t1,24
lw $t1,0($v0)
sw $t1,4($sp)
lw $t1,4($sp)
lw $t2,8($sp)
add $t1,$t1,$t2
sw $t1,8($sp)
addiu $sp,$sp,4
lw $t1,4($sp)
lw $t2,8($sp)
add $t1,$t1,$t2
sw $t1,8($sp)
addiu $sp,$sp,4
lw $t1,4($sp)
addiu $sp,$sp,4
sw $t1,-8($fp)
addiu $v0,$fp,-8
lw $t1,0($v0)
sw $t1,0($sp)
addiu $sp,$sp,-4
lw $a0 ,4($sp)
addi $sp, $sp, 4
li $v0, 1
syscall
addiu $v0,$fp,-4
lw $t1,0($v0)
sw $t1,0($sp)
addiu $sp,$sp,-4
lw $t1,4($sp)
addi $sp,$sp,4
addi $sp,$sp,-12
sw $fp,4($sp)
sw $ra,8($sp)
sw $s7,12($sp)
move $s5,$sp
move $s7,$t1
move $fp,$s5
lw $t1,12($s7)
lw $t1,0($t1)
jal $t1
lw $fp,4($sp)
lw $ra,8($sp)
lw $s7,12($sp)
addi $sp,$sp,12
li $v0,10
syscall
ali.second.ali.three.d.d0:
addi $sp,$sp,0
li $t1,4
sw $t1,0($sp)
addi $sp,$sp,-4
lw $t1,4($sp)
addiu $sp,$sp,4
sw $t1,16($s7)
li $t1,2
sw $t1,0($sp)
addi $sp,$sp,-4
lw $t1,4($sp)
addiu $sp,$sp,4
sw $t1,20($s7)
li $t1,1
sw $t1,0($sp)
addi $sp,$sp,-4
lw $t1,4($sp)
addiu $sp,$sp,4
sw $t1,24($s7)
endali.second.ali.three.d.d0:
addi $sp,$sp,0
jr $ra
