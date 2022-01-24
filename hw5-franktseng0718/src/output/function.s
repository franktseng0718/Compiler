.file "function.p"
.option nopic
.bss
gv:
.word 0
.text
gc:
.word 2
.text
.align 2
.global product
.type product, @function
product:
addi sp, sp, -64
sd ra, 56(sp)
sd s0, 48(sp)
addi s0, sp, 64
sw a0, -20(s0)
sw a1, -24(s0)
lw t0, -20(s0)
lw t1, -24(s0)
mulw t2, t1, t0
mv t0, t2
sw t0, -28(s0)
lw t0, -28(s0)
mv a0, t0
ld ra, 56(sp)
ld s0, 48(sp)
addi sp, sp, 64
jr ra
.size product, .-product
.text
.align 2
.global sum
.type sum, @function
sum:
addi sp, sp, -64
sd ra, 56(sp)
sd s0, 48(sp)
addi s0, sp, 64
sw a0, -20(s0)
sw a1, -24(s0)
lw t0, -20(s0)
lw t1, -24(s0)
addw t2, t1, t0
mv t0, t2
sw t0, -28(s0)
lw t0, -28(s0)
mv a0, t0
ld ra, 56(sp)
ld s0, 48(sp)
addi sp, sp, 64
jr ra
.size sum, .-sum
.text
.align 2
.global dot
.type dot, @function
dot:
addi sp, sp, -64
sd ra, 56(sp)
sd s0, 48(sp)
addi s0, sp, 64
sw a0, -20(s0)
sw a1, -24(s0)
sw a2, -28(s0)
sw a3, -32(s0)
lw t0, -20(s0)
sw t0, 0(sp)
lw t0, -24(s0)
sw t0, -4(sp)
lw a0, 0(sp)
lw a1, -4(sp)
jal ra, product
mv t0, a0
sw t0, 0(sp)
lw t0, -28(s0)
sw t0, 0(sp)
lw t0, -32(s0)
sw t0, -4(sp)
lw a0, 0(sp)
lw a1, -4(sp)
jal ra, product
mv t0, a0
sw t0, -4(sp)
lw a0, 0(sp)
lw a1, -4(sp)
jal ra, sum
mv t0, a0
sw t0, -36(s0)
lw t0, -36(s0)
mv a0, t0
ld ra, 56(sp)
ld s0, 48(sp)
addi sp, sp, 64
jr ra
.size dot, .-dot
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
la t0, gv
lw t1, 0(t0)
mv t0, t1
sw t0, 0(sp)
la t0, gc
lw t1, 0(t0)
mv t0, t1
sw t0, -4(sp)
lw a0, 0(sp)
lw a1, -4(sp)
jal ra, product
mv t0, a0
la t1, gv
sw t0, 0(t1)
la t0, gv
lw t1, 0(t0)
mv t0, t1
lw t1, -20(s0)
sw t1, 0(sp)
lw t1, -24(s0)
sw t1, -4(sp)
lw a0, 0(sp)
lw a1, -4(sp)
jal ra, product
mv t1, a0
addw t2, t1, t0
mv t0, t2
sw t0, -20(s0)
la t0, gv
lw t1, 0(t0)
mv t0, t1
mv a0, t0
jal ra, print
lw t0, -20(s0)
mv a0, t0
jal ra, print
la t0, gv
lw t1, 0(t0)
mv t0, t1
sw t0, 0(sp)
la t0, gc
lw t1, 0(t0)
mv t0, t1
sw t0, -4(sp)
lw t0, -20(s0)
sw t0, -8(sp)
lw t0, -24(s0)
sw t0, -12(sp)
lw a0, 0(sp)
lw a1, -4(sp)
lw a2, -8(sp)
lw a3, -12(sp)
jal ra, dot
mv t0, a0
la t1, gv
sw t0, 0(t1)
la t0, gv
lw t1, 0(t0)
mv t0, t1
mv a0, t0
jal ra, print
ld ra, 56(sp)
ld s0, 48(sp)
addi sp, sp, 64
jr ra
.size main, .-main
