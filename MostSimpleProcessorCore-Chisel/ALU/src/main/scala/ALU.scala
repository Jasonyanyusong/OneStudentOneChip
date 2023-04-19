package test
import chisel3._
import chisel3.experimental._

/*
The Operate Code has 4 digits.
The highest digit is used for distinguishing Computing / Shifting.
The last 3 digits are used for specifing what should the ALU do.
*/

/*
For Computing part of ALU, we set the OperateCode as:
    000, Add, A + B
    001, Sub, A - B
    010, Not, ~ A
    011, And, A & B
    100, Or,  A | B
    101, Xor, A ^ B
    110, Cmp, A < B
    111, Beq, A ==B
*/

/*
For Shifting part of ALU, we set the OperateCode as:
    000, Preserved
    001, Preserved
    010, Shift Right Logic
    011, Shift Left Logic
    100, Shift Right Arithmetic
    101, Preserved
    110, Shift Right Cycle
    111, Shift Left Cycle
*/

class ALU extends Module{
    val io = IO(new Bundle{
        val DataInA = Input(UInt(64.W))
        val DataInB = Input(UInt(64.W))
        val OperateCode = Input(UInt(4.W))
        val ComputeResult = Output(UInt(64.W))
        val CompareResult = Output(Bool(1.W))
    }) // Define ALU's IO

    // Define Operate-Code for Computing Part
    val ALU_C_ADD = "b0_000".U
    val ALU_C_SUB = "b0_001".U
    val ALU_C_NOT = "b0_010".U
    val ALU_C_AND = "b0_011".U
    val ALU_C_OR  = "b0_100".U
    val ALU_C_XOR = "b0_101".U
    val ALU_C_CMP = "b0_110".U
    val ALU_C_BEQ = "b0_111".U

    // Define Operate-Code for Shifting Part
    val ALU_S_SLR = "b0_010".U
    val ALU_S_SLL = "b0_011".U
    val ALU_S_SRA = "b0_100".U
    val ALU_S_SRC = "b0_110".U
    val ALU_S_SLC = "b0_111".U

    
}