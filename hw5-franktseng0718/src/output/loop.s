.file "loop.p"
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
j L1
L0:
la t0, gv
lw t1, 0(t0)
mv t0, t1
mv a0, t0
jal ra, print
la t0, gv
lw t1, 0(t0)
mv t0, t1
li t1, 1
addw t2, t1, t0
mv t0, t2
la t1, gv
sw t0, 0(t1)
L1:
la t0, gv
lw t1, 0(t0)
mv t0, t1
li t1, 3
ble t0, t1, L0
li t0, 10
sw t0, -28(s0)
j L3
L2:
la t0, gv
lw t1, 0(t0)
mv t0, t1
mv a0, t0
jal ra, print
L3:
li t1, 13
lw t0, -28(s0)
addi t2, t0, 1
mv t0, t2
ble t0, t1, L2
ld ra, 56(sp)
ld s0, 48(sp)
addi sp, sp, 64
jr ra
.size main, .-main
