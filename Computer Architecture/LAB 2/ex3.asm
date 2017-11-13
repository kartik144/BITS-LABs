.data
msg: .asciiz "Enter number:\t"
Sum: .asciiz "The sum is: \t"
Diff: .asciiz "\nThe difference is: \t"

.text
main:

la $a0,msg
li $v0,4
syscall

li $v0,5
syscall

ori $t0,$v0,0
li $v0,4
syscall

li $v0,5
syscall

ori $t1,$v0,0

la $a0,Sum
li $v0,4
syscall

add $a0,$t0,$t1
li $v0,1
syscall

la $a0,Diff
li $v0,4
syscall

sub $a0,$t0,$t1
li $v0,1
syscall

li $v0,10
syscall

