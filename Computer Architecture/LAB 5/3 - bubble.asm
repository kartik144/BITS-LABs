.data
list: .word 17 5 92 87 41 10 23 55 72 36
space: .asciiz " "

.text
main:

li $s7,10
addi $s3,$s7,-1
li $t8,4
la $t7,list

outer_loop:
ble $s3,$zero,exit
li $t0,0

	inner_loop:
		bge $t0,$s3,break_inner
		addi $t1,$t0,1
		mul $t4,$t0,$t8
		mul $t5,$t1,$t8
		add $t4,$t4,$t7
		add $t5,$t5,$t7
		lw $t2,($t4)
		lw $t3,($t5)
		ble $t2,$t3,dont_swap
			sw $t2,($t5)
			sw $t3,($t4)
		dont_swap:
		addi $t0,$t0,1
		j inner_loop
		
break_inner:
addi $s3,$s3,-1
j outer_loop


exit:

la $t0,list
li $t2,0

print:

lw $a0,($t0)

li $v0,1
syscall
la $a0,space
li $v0,4
syscall
addi $t0,$t0,4
addi $t2,$t2,1
blt $t2,$s7,print

li $v0,10
syscall
