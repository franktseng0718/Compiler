.file "specExample.p"
.option nopic
.bss
a:
.word 0
.text
d:
.word 4
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
sw t0, 0(sp)
addi sp, sp, -4
lw t0, -24(s0)
addi sp, sp, 4
lw t1, 0(sp)
addw t0, t1, t0
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
.global main
.type main, @function
main:
addi sp, sp, -64
sd ra, 56(sp)
sd s0, 48(sp)
addi s0, sp, 64
li t0, 4
li t1, -1
mulw t0, t0, t1
sw t0, -20(s0)
li t0, 6
sw t0, -24(s0)
jal ra, read
la t0, a
sw a0, 0(t0)
la t0, a
lw t1, 0(t0)
mv t0, t1
mv a0, t0
jal ra, print
lw t0, -20(s0)
sw t0, 0(sp)
addi sp, sp, -4
la t0, d
lw t1, 0(t0)
mv t0, t1
sw t0, 0(sp)
addi sp, sp, -4
addi sp, sp, 4
lw a1, 0(sp)
addi sp, sp, 4
lw a0, 0(sp)
jal ra, sum
mv t0, a0
la t1, a
sw t0, 0(t1)
la t0, a
lw t1, 0(t0)
mv t0, t1
mv a0, t0
jal ra, print
lw t0, -20(s0)
sw t0, 0(sp)
addi sp, sp, -4
lw t0, -24(s0)
addi sp, sp, 4
lw t1, 0(sp)
addw t0, t1, t0
sw t0, 0(sp)
addi sp, sp, -4
la t0, d
lw t1, 0(t0)
mv t0, t1
addi sp, sp, 4
lw t1, 0(sp)
mulw t0, t1, t0
la t1, a
sw t0, 0(t1)
la t0, a
lw t1, 0(t0)
mv t0, t1
mv a0, t0
jal ra, print
la t0, a
lw t1, 0(t0)
mv t0, t1
sw t0, 0(sp)
addi sp, sp, -4
li t0, 40
addi sp, sp, 4
mv t1, t0
lw t0, 0(sp)
bgt t0, t1, L1
L0:
la t0, a
lw t1, 0(t0)
mv t0, t1
li t1, -1
mulw t0, t0, t1
mv a0, t0
jal ra, print
j L2
L1:
lw t0, -20(s0)
mv a0, t0
jal ra, print
L2:
j L4
L3:
lw t0, -20(s0)
mv a0, t0
jal ra, print
lw t0, -20(s0)
sw t0, 0(sp)
addi sp, sp, -4
li t0, 1
addi sp, sp, 4
lw t1, 0(sp)
addw t0, t1, t0
sw t0, -20(s0)
L4:
lw t0, -20(s0)
sw t0, 0(sp)
addi sp, sp, -4
li t0, 8
addi sp, sp, 4
mv t1, t0
lw t0, 0(sp)
blt t0, t1, L3
ld ra, 56(sp)
ld s0, 48(sp)
addi sp, sp, 64
jr ra
.size main, .-main
