.data
myMsg: .asciiz "Enter a number:"
Msg: .asciiz "The number entered is: "

.text
main:
la $a0,myMsg
li $v0,4
syscall

li $v0,5
syscall

ori $t0,$v0,0
la $a0,Msg
li $v0,4
syscall

ori $a0,$t0,0

li $v0,1
syscall

li $v0,10
syscall
