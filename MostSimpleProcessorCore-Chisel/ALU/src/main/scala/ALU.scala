package test
import chisel3._
import chisel3.experimental._

class ALU extends Module{
    val io = IO(new Bundle{
        val DataInA = Input(UInt(64.W))
        val DataInB = Input(UInt(64.W))
        val OperateCode = Input(UInt(4.W))
        val ComputeResult = Output(UInt(64.W))
        val CompareResult = Output(Bool(1.W))
    })
}