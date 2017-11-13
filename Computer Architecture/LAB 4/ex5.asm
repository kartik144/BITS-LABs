.data
str0: .asciiz "Mul Integers:"
str1: .asciiz "\nMul Float:"
str2: .asciiz "\nMul Double:"
str3: .asciiz "\nMul diff(Double-Float):"
w1: .word 1500
w2: .word 8945

.text
main:
lw $t1,w1
lw $t2,w2

la $a0, str0
li $v0, 4
syscall

mul $t6,$t1,$t2 # t6 reg has int*int
move $a0,$t6
li $v0,1
syscall

mtc1 $t1,$f0
cvt.s.w $f1,$f0
mtc1 $t2,$f0
cvt.s.w $f2,$f0
mul.s $f3,$f1,$f2
cvt.w.s $f4,$f3
mfc1 $t7,$f4 # t7 has (float*float)


mtc1 $t1,$f0
cvt.d.w $f2,$f0
mtc1 $t2,$f0
cvt.d.w $f4,$f0
mul.d $f6,$f2,$f4
cvt.w.d $f8,$f6
mfc1 $t8,$f8 # t8 has (double*double)


la $a0, str1
li $v0, 4
syscall

move $a0,$t7
li $v0,1
syscall

la $a0, str2
li $v0, 4
syscall

move $a0,$t8
li $v0,1
syscall

la $a0, str3
li $v0, 4
syscall

sub $t9,$t8,$t7
move $a0,$t9
li $v0,1
syscall


li $v0,10
syscall
