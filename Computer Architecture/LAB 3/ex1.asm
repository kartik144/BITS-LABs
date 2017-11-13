.data
odd 	: .asciiz "The number is odd"
even 	: .asciiz "The number is even"

.text
main:

li $v0,5
syscall

move $t0,$v0
andi $t0, $t0,1
bne $t0,$zero, odd_label

la $a0,even
li $v0,4
syscall

j exit_label

odd_label:

la $a0,odd
li $v0,4
syscall

exit_label:

li $v0,10
syscall
