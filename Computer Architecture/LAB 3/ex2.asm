.data
str: .asciiz "Nigga is a lil' bitch"

.text
main:

la $t0,str
li $a0,-1

slen:

lb $t1, ($t0)
addi $t0,$t0,1
addi $a0,$a0,1
beq $t1,$zero,exit
j slen

exit:
li $v0,1
syscall

li $v0,10
syscall

