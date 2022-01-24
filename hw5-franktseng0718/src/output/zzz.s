	.file "zzz.p"
	.option nopic
.text
	.align 2
	.global main
	.type main, @function
main:
	addi sp, sp, -64
	sd ra, 56(sp)
	sd s0, 48(s0)
	addi s0, sp, 64
	ld ra, 56(sp)
	ld s0, 48(sp)
	addi sp, sp, 64
	jr ra
	.size main, .-main
