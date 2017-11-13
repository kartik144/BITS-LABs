.data
space: .asciiz " "

.text
main:

	li $s0,0

	get_input:

		li $v0,5
		syscall
	
		beq $v0,$zero,break_of_loop
	
		move $a0,$v0
		move $a1,$s0
		jal insert_in_tree
		
		move $s0,$v0
		j get_input
		
	break_of_loop:
		move $a0,$s0
		jal inorder_traversal
		
		li $v0,10
		syscall
		
	
insert_in_tree:

	bne $a1,$zero,not_base_case
	move $t0,$a0
	
	li $a0,12
	li $v0,9
	syscall
	
	sw $t0,($v0)
	sw $zero,4($v0)
	sw $zero,8($v0)
		
	jr $ra
	
	not_base_case:
	
		addi $sp,$sp,-12
		sw $ra,($sp)
		sw $a1,4($sp)
		sw $s0,8($sp)
		
		lw $t0,($a1)
		bge $a0,$t0,right
		
		left: addi $s0,$a1,4
			  j recurr
		right: addi $s0,$a1,8
			
		recurr:
		lw $a1,($s0)
		jal insert_in_tree
		
		sw $v0,($s0)
		lw $ra,($sp)
		lw $a1,4($sp)
		lw $s0,8($sp)
		
		addi $sp,$sp,12
		move $v0,$a1
		j $ra

inorder_traversal:
	beq $a0,$zero,return_inorder
	
	addi $sp,$sp,-8
	sw $ra,($sp)
	sw $a0,4($sp)
	
	lw $a0,4($a0)
	jal inorder_traversal
	
	lw $a0,4($sp)
	lw $a0,($a0)
	li $v0,1
	syscall
	la $a0,space
	li $v0,4
	syscall
	
	lw $a0,4($sp)
	lw $a0,8($a0)
	jal inorder_traversal
	
	lw $a0,4($sp)
	lw $ra,($sp)
	addi $sp,$sp,8
	
	return_inorder:
		jr $ra
