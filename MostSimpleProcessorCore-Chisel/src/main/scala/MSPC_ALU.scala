package MSPC_ALU

import chisel3._
import chisel3.util._
import chisel3.tester._
import chisel3.tester.RawTester.test
import dotvisualizer_

/*
MSPC_ALU: Arthmetic and Logic Processer of the NPC

*/

class MSPC_ALU extends Module{
    val io = IO(new Bundle {
        val inputA   = Input(UInt(64.W))
        val inputB   = Input(UInt(64.W))
        val sel      = Input(UInt(4.W))

        val sum      = Output(UInt(64.W))
        val out      = Output(UInt(64.W))
    })

    val compute_sum = 
}