.data
space: .asciiz " "
label: .asciiz "List: "
label2: .asciiz "Reverse List: "
newline: .asciiz "\n"

.text
main:

	li $s0,0

	get_input:

		li $v0,5
		syscall
	
		beq $v0,$zero,break_of_loop
	
		move $a0,$v0
		move $a1,$s0
		jal insert_at_end # change to "insert_at_beg" if needed
		
		move $s0,$v0
		
		la $a0,label	# Printer code
		li $v0,4
		syscall
		
		move $a0,$s0
		jal print_list
		la $a0,newline
		li $v0,4
		syscall		# end of Printer code
		
		
		j get_input
		
	break_of_loop:
		la $a0,label	# Printer code
		li $v0,4
		syscall
		
		move $a0,$s0
		jal print_list
		la $a0,newline
		li $v0,4
		syscall		#end of printer code
		
		la $a0,label2	# Reverse Print code
		li $v0,4
		syscall
		
		move $a0,$s0
		jal print_list_reverse
		la $a0,newline
		li $v0,4
		syscall		#end of reverse print code
		
		li $v0,10
		syscall
		
	
insert_at_beg:

	move $t0,$a0
	
	li $a0,8
	li $v0,9
	syscall
	
	sw $t0,($v0)
	sw $a1,4($v0)
		
	jr $ra

insert_at_end:
	bne $a1,$zero,not_base_case
	
	base_case:
		move $t0,$a0
	
		li $a0,8
		li $v0,9
		syscall
	
		sw $t0,($v0)
		sw $zero,4($v0)
		
		jr $ra
	
	not_base_case:
	
		addi $sp,$sp,-12
		sw $ra,($sp)
		sw $a0,4($sp)
		sw $a1,8($sp)
	
		lw $a1,8($sp)
		lw $a1,4($a1)
		jal insert_at_end
	
		move $t1,$v0
		
		lw $ra,($sp)
		lw $a0,4($sp)
		lw $a1,8($sp)
		addi $sp,$sp,12
		
		sw $t1,4($a1)
		move $v0,$a1
		j $ra
	
print_list:
	beq $a0,$zero,return_printlist
	
	addi $sp,$sp,-8
	sw $ra,($sp)
	sw $a0,4($sp)
	
	lw $a0,($a0)
	li $v0,1
	syscall
	la $a0,space
	li $v0,4
	syscall
	
	lw $a0,4($sp)
	lw $a0,4($a0)
	jal print_list
	
	lw $a0,4($sp)
	lw $ra,($sp)
	addi $sp,$sp,8
	
	return_printlist:
		jr $ra
		
print_list_reverse:
	beq $a0,$zero,return_reverse_print
	
	addi $sp,$sp,-8
	sw $ra,($sp)
	sw $a0,4($sp)
	
	lw $a0,4($a0)
	jal print_list_reverse
	
	lw $ra,($sp)
	lw $a0,4($sp)
	addi $sp,$sp,8
	
	lw $a0,($a0)
	li $v0,1
	syscall
	la $a0,space
	li $v0,4
	syscall
	
	return_reverse_print:
		jr $ra
