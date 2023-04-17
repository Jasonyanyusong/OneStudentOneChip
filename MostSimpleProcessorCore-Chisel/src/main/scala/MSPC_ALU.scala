package MSPC_ALU

import chisel3._
import chisel3.util._

class MSPC_ALU extends Module{
    val io = IO(new Bundle {
        val inputA = Input(UInt(64.W))
        val inputB = Input(UInt(64.W))
        val sel = Input(UInt(4.W))
        val outputAns = Output(UInt(64.W))
        val outputBool = Output(Bool)
    })
}