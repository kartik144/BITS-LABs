.data
list: .double 17.45 15.001 92.5 87.0 41.78 10.01 17.47 55.95 92.6 36.12
space: .asciiz "\n"

.text
main:

li $s7,10
addi $s3,$s7,-1
li $t8,8
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
		ldc1 $f0,($t4)
		ldc1 $f2,($t5)
		c.le.d $f0,$f2
		bc1t dont_swap
			sdc1 $f0,($t5)
			sdc1 $f2,($t4)
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

ldc1 $f12,($t0)

li $v0,3
syscall
la $a0,space
li $v0,4
syscall
addi $t0,$t0,8
addi $t2,$t2,1
blt $t2,$s7,print

li $v0,10
syscall
