.data
str: .asciiz "Enter the number: "
multip: .asciiz "The multiples less than 100 are: "
space : .asciiz " "

.text
main:

la $a0,str
li $v0,4
syscall

li $v0,5
syscall

move $t0,$v0
li $t1,1
li $t2,100

la $a0,multip
li $v0,4
syscall

loop:

mul $a0,$t0,$t1
li $v0,1
syscall
la $a0,space
li $v0,4
syscall
addi $t1,$t1,1
mul $t4,$t0,$t1
blt $t4,$t2,loop

li $v0,10
syscall

