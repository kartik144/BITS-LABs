.data
str:		.asciiz "Kartik"
str2:		.asciiz "Srivastava"
vowels: 	.asciiz "aeiouAEIOU"
newline:	.asciiz "\n"
size:		.word 10
mod: 		.space 50
msg1:		.asciiz "The number of vowels is "
msg2:		.asciiz "The string after removal of vowels is "

.text
main:
	lw $a0,size
	la $a1,str2
	la $a2,vowels
	
	jal remove_and_count
	
	la $a0,msg2
	li $v0,4
	syscall
	
	la $a0,mod
	li $v0,4
	syscall
	
	la $a0,newline
	li $v0,4
	syscall
	
	li $v0,10
	syscall
	
remove_and_count:
	addi $sp,$sp,-12
	sw $a0,($sp)
	sw $a1,4($sp)
	sw $a2,8($sp)
	
	lw $t0,0($sp)
	li $t1,0
	lw $t2,4($sp)
	lb $t4,($t2)
	la $t8,mod
	
	loop:
		beq $t4,$zero,exit_loop
		lw $t3,8($sp)
		lb $t5,($t3)
		li $t7,1
		loop2:
			beq $t5,$zero,exit_loop2
			bne $t5,$t4,skip
			addi $t1,$t1,1
			li $t7,0
			j exit_loop2
			skip:
			addi $t3,$t3,1
			lb $t5,($t3)
			j loop2
		exit_loop2:
		beq $t7,$zero,skip2
		sb $t4,($t8)
		sb $zero,1($t8)
		addi $t8,$t8,1
		skip2:
		addi $t2,$t2,1
		lb $t4,($t2)
		j loop
		
	exit_loop:
	
	la $a0,msg1
	li $v0,4
	syscall
	
	move $a0,$t1
	li $v0,1
	syscall
	
	la $a0,newline
	li $v0,4
	syscall
	
	lw $a0,0($sp)
	lw $a1,4($sp)
	lw $a2,8($sp)
	
	addi $sp,$sp,12
	j $ra
