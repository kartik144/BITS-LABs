.data
theStr: .space 6
isPal: .asciiz "It's a Palindrome"
notPal: .asciiz "Not a Palindrome"
newLine: .asciiz "\n"

.text
main:
		lb $t4,newLine
		li $v0,8
		la $a0,theStr
		li $a1,6
		syscall
		add $t2,$a0,$zero

slen_0:
		lb $t3,($t2)
		addi $t2,$t2,1
		beq $t3,$t4,next
		bne $t3,$zero,slen_0
		
next:	
		add $t1,$a0,$zero
		addi $t2,$t2,-2
		
test_loop:
		bge $t1,$t2,is_palin
		lb $t3,0($t1)
		lb $t4,0($t2)
		bne $t3,$t4,not_palin
		addi $t1,$t1,1
		addi $t2,$t2,-1
		j test_loop
		
is_palin:
		li $v0,4
		la $a0,isPal
		syscall
		j exit
		
not_palin:
		li $v0,4
		la $a0,notPal
		syscall
		j exit
		
exit:
		li $v0,10
		syscall
