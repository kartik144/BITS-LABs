.data
str: .space 7
rev: .space 7
newLine: .asciiz "\n"

.text
main:
		lb $t4,newLine
		la $a0,str
		li $a1,7
		li $v0,8
		syscall
		add $t2,$a0,$zero
		la $t0,rev
		la $t6,rev
		li $t8,0
		
get_end:
		lb $t3,($t2)
		addi $t2,$t2,1
		addi $t8,$t8,1
		beq $t3,$t4,rev_util
		bne $t3,$zero,get_end
		
rev_util:
		addi $t2,$t2,-2
		#addi $t8,$t8,-1
		#move $a0,$t8
		#li $v0,1
		#syscall
reverse:
		beq $t8,$zero,print
		lb $t7,0($t2)
		sb $t7,0($t0)
		sb $t4,1($t0)
		sb $zero,2($t0)
		addi $t2,$t2,-1
		addi $t0,$t0,1
		addi $t8,$t8,-1
		j reverse
		
fillnewLine:
		addi $t0,$t0,1
		sb $t4,0($t0)
		addi $t0,$t0,1
		sb $zero,0($t0)
		j print
		
print:
		la $a0,rev
		li $v0,4
		syscall
		li $v0,10
		syscall
