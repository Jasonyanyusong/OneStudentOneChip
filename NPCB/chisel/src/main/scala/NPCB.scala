package npcb
import chisel3._
import chisel3.util._

class NPCB extends Module{
    val io = IO(new Bundle{
        val halt = Output((Bool()))
    })
    val GPR = Mem(32, UInt(64.W))
    val PC = RegInit(0.U(64.W))
    val Memory = Mem(1024/4, UInt(32.W))
}