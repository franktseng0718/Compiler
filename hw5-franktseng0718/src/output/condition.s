.file "condition.p"
.option nopic
.bss
gv:
.word 0
.text
gc:
.word 2
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
.global main
.type main, @function
main:
addi sp, sp, -64
sd ra, 56(sp)
sd s0, 48(sp)
addi s0, sp, 64
li t0, 4
sw t0, -24(s0)
li t0, 1
la t1, gv
sw t0, 0(t1)
li t0, 3
sw t0, -20(s0)
la t0, gv
lw t1, 0(t0)
mv t0, t1
li t1, 1
bne t0, t1, L1
L0:
la t0, gv
lw t1, 0(t0)
mv t0, t1
mv a0, t0
jal ra, print
j L2
L1:
lw t0, -20(s0)
mv a0, t0
jal ra, print
L2:
la t0, gv
lw t1, 0(t0)
mv t0, t1
mv a0, t0
la t0, gc
lw t1, 0(t0)
mv t0, t1
mv a1, t0
jal ra, sum
mv t0, a0
li t1, 4
ble t0, t1, L4
L3:
la t0, gv
lw t1, 0(t0)
mv t0, t1
mv a0, t0
jal ra, print
j L5
L4:
lw t0, -20(s0)
mv a0, t0
jal ra, print
L5:
ld ra, 56(sp)
ld s0, 48(sp)
addi sp, sp, 64
jr ra
.size main, .-main
