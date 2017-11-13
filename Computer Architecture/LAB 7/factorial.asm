.data
promptMessage : .asciiz "Enter a number to find it's factorial: "
resultMessage : .asciiz "\nThe factorial of the given number is: "

.text
main:
	li $v0,4
	la $a0,promptMessage
	syscall
	li $v0,5
	syscall
	move $a0,$v0
	jal findFactorial
	
	move $s0,$v0
	li $v0,4
	la $a0,resultMessage
	syscall
	li $v0,1
	move $a0,$s0
	syscall
	li $v0,10
	syscall
	
findFactorial:
	subu $sp,$sp,8
	sw $ra,0($sp)
	sw $s0,4($sp)
	
	li $v0,1
	beq $a0,0,factDone
	
	move $s0,$a0
	sub $a0,$a0,1
	jal findFactorial
	mul $v0,$s0,$v0
	
factDone:
	lw $ra,0($sp)
	lw $s0,4($sp)
	addu $sp,$sp,8
	jr $ra
