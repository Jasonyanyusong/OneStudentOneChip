package MSPC_ALU

import chisel3._
import chisel3.util._

class MSPC_ALU extends Module{
    val io = IO(new Bundle {
        val inputA   = Input(UInt(64.W))
        val inputB   = Input(UInt(64.W))
        val sel      = Input(UInt(4.W))

        val out_add  = Output(UInt(64.W))
        val out_sub  = Output(UInt(64.W))
        val out_and  = Output(UInt(64.W))
     // val out_nand = Output(UInt(64.W))
        val out_or   = Output(UInt(64.W))
     // val out_nor  = Output(UInt(64.W))
        val out_xor  = Output(UInt(64.W))
     // val out_xnor = Output(UInt(64.W))
        val out_not  = Output(UInt(64.W))
        val out_blt  = Output(Bool())
        val out_beq  = Output(Bool())
        val out_sra  = Output(UInt(64.W))
        val out_sla  = Output(UInt(64.W))
        val out_sll  = Output(UInt(64.W))
    })

    io.out_add := io.inputA + io.inputB
    io.out_sub := io.inputA - io.inputB
    io.out_and := io.inputA & io.inputB
    io.out_or  := io.inputA | io.inputB
    io.out_xor := io.inputA ^ io.inputB
    io.out_not := ~ io.inputA
}