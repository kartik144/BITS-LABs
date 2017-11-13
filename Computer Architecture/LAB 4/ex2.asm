.data
val1: .float 0.001

.text
main:
l.s $f0,val1
cvt.d.s $f12,$f0
#l.d $f12,val1
li $v0,3
syscall

li $v0,7
syscall

cvt.s.d $f2,$f0
mov.s $f12,$f2
li $v0,2
syscall

li $v0,10
syscall
