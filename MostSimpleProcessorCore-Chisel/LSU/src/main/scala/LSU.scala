package test
import chisel3._
import chisel3.experimental._

class LSU extends Module{
    val io = IO(new Bundle{
        val rs1 = Input(UInt(5.W))
        val rs2 = Input(UInt(5.W))
        val rd = Input(UInt(5.W))

        val optype = Input(Uint(4.W))

        val inB = Input(UInt(8.W))
        val inH = Input(UInt(16.W))
        val inW = Input(UInt(32.W))
        val inD = Input(UInt(64.W))

        val outB = Output(UInt(8.W))
        val outH = Output(UInt(16.W))
        val outW = Output(UInt(32.W))
        val outD = Output(UInt(64.W))
    })
}