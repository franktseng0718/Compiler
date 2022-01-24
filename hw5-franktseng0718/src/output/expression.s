.file "expression.p"
.option nopic
.bss
gv:
.word 0
.text
gc:
.word 2
.text
.align 2
.global main
.type main, @function
main:
addi sp, sp, -64
sd ra, 56(sp)
sd s0, 48(sp)
addi s0, sp, 64
li t0, 2
sw t0, -24(s0)
li t0, 2
la t1, gv
sw t0, 0(t1)
li t0, 2
sw t0, -20(s0)
lw t0, -24(s0)
sw t0, 0(sp)
addi sp, sp, -4
la t0, gv
lw t1, 0(t0)
mv t0, t1
addi sp, sp, 4
lw t1, 0(sp)
addw t0, t1, t0
addi sp, sp, 4
lw t1, 0(sp)
subw t0, t1, t0
sw t0, 0(sp)
addi sp, sp, -4
la t0, gc
lw t1, 0(t0)
mv t0, t1
addi sp, sp, 4
lw t1, 0(sp)
addw t0, t1, t0
addi sp, sp, 4
lw t1, 0(sp)
subw t0, t1, t0
sw t0, 0(sp)
addi sp, sp, -4
lw t0, -20(s0)
addi sp, sp, 4
lw t1, 0(sp)
addw t0, t1, t0
addi sp, sp, 4
lw t1, 0(sp)
subw t0, t1, t0
la t1, gv
sw t0, 0(t1)
lw t0, -24(s0)
sw t0, 0(sp)
addi sp, sp, -4
la t0, gv
lw t1, 0(t0)
mv t0, t1
addi sp, sp, 4
lw t1, 0(sp)
mulw t0, t1, t0
sw t0, 0(sp)
addi sp, sp, -4
la t0, gc
lw t1, 0(t0)
mv t0, t1
addi sp, sp, 4
lw t1, 0(sp)
mulw t0, t1, t0
sw t0, 0(sp)
addi sp, sp, -4
lw t0, -20(s0)
addi sp, sp, 4
lw t1, 0(sp)
mulw t0, t1, t0
sw t0, -20(s0)
la t0, gv
lw t1, 0(t0)
mv t0, t1
mv a0, t0
jal ra, print
lw t0, -20(s0)
mv a0, t0
jal ra, print
lw t0, -24(s0)
sw t0, 0(sp)
addi sp, sp, -4
la t0, gv
lw t1, 0(t0)
mv t0, t1
sw t0, 0(sp)
addi sp, sp, -4
la t0, gc
lw t1, 0(t0)
mv t0, t1
addi sp, sp, 4
lw t1, 0(sp)
addw t0, t1, t0
addi sp, sp, 4
lw t1, 0(sp)
subw t0, t1, t0
sw t0, 0(sp)
addi sp, sp, -4
lw t0, -20(s0)
addi sp, sp, 4
lw t1, 0(sp)
mulw t0, t1, t0
addi sp, sp, 4
lw t1, 0(sp)
addw t0, t1, t0
addi sp, sp, 4
lw t1, 0(sp)
subw t0, t1, t0
la t1, gv
sw t0, 0(t1)
lw t0, -24(s0)
sw t0, 0(sp)
addi sp, sp, -4
la t0, gv
lw t1, 0(t0)
mv t0, t1
sw t0, 0(sp)
addi sp, sp, -4
la t0, gc
lw t1, 0(t0)
mv t0, t1
sw t0, 0(sp)
addi sp, sp, -4
lw t0, -20(s0)
sw t0, 0(sp)
addi sp, sp, -4
lw t0, -24(s0)
sw t0, 0(sp)
addi sp, sp, -4
la t0, gv
lw t1, 0(t0)
mv t0, t1
sw t0, 0(sp)
addi sp, sp, -4
la t0, gc
lw t1, 0(t0)
mv t0, t1
sw t0, 0(sp)
addi sp, sp, -4
lw t0, -20(s0)
sw t0, 0(sp)
addi sp, sp, -4
lw t0, -24(s0)
addi sp, sp, 4
lw t1, 0(sp)
addw t0, t1, t0
addi sp, sp, 4
lw t1, 0(sp)
subw t0, t1, t0
addi sp, sp, 4
lw t1, 0(sp)
addw t0, t1, t0
addi sp, sp, 4
lw t1, 0(sp)
subw t0, t1, t0
addi sp, sp, 4
lw t1, 0(sp)
addw t0, t1, t0
addi sp, sp, 4
lw t1, 0(sp)
subw t0, t1, t0
addi sp, sp, 4
lw t1, 0(sp)
addw t0, t1, t0
addi sp, sp, 4
lw t1, 0(sp)
subw t0, t1, t0
addi sp, sp, 4
lw t1, 0(sp)
addw t0, t1, t0
addi sp, sp, 4
lw t1, 0(sp)
subw t0, t1, t0
addi sp, sp, 4
lw t1, 0(sp)
addw t0, t1, t0
addi sp, sp, 4
lw t1, 0(sp)
subw t0, t1, t0
addi sp, sp, 4
lw t1, 0(sp)
addw t0, t1, t0
addi sp, sp, 4
lw t1, 0(sp)
subw t0, t1, t0
addi sp, sp, 4
lw t1, 0(sp)
addw t0, t1, t0
addi sp, sp, 4
lw t1, 0(sp)
subw t0, t1, t0
sw t0, -20(s0)
la t0, gv
lw t1, 0(t0)
mv t0, t1
mv a0, t0
jal ra, print
lw t0, -20(s0)
mv a0, t0
jal ra, print
ld ra, 56(sp)
ld s0, 48(sp)
addi sp, sp, 64
jr ra
.size main, .-main
