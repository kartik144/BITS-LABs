.data
newline: .asciiz "\n"
.text
main:
li $v0,6
syscall
mov.s $f1,$f0

li $v0,6
syscall
mov.s $f2,$f0

add.s $f12,$f1,$f2
li $v0,2
syscall

la $a0,newline
li $v0,4
syscall

sub.s $f12,$f2,$f1
li $v0,2
syscall

la $a0,newline
li $v0,4
syscall

neg.s $f3,$f1
add.s $f12,$f2,$f3
li $v0,2
syscall

la $a0,newline
li $v0,4
syscall

li $v0,10
syscall
