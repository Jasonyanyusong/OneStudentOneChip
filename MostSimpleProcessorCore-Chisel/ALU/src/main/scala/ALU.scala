package test
import chisel3._
import chisel3.util._
import chisel3.experimental._
class ALU extends Module{
    val io = IO(new Bundle{
        val DataInA = Input(UInt(64.W))
        val DataInB = Input(UInt(64.W))
        val OperateCode = Input(UInt(4.W))
        val ALUResult = Output(UInt(64.W))
    })
    io.ALUResult := chisel3.util.PriorityMux(Seq(
        io.OperateCode("b0000".U) -> (io.DataInA + io.DataInB),
        io.OperateCode("b0001".U) -> (io.DataInA - io.DataInB),
        io.OperateCode("b0010".U) -> (~ io.DataInA),
        io.OperateCode("b0011".U) -> (io.DataInA & io.DataInB),
        io.OperateCode("b0100".U) -> (io.DataInA | io.DataInB),
        io.OperateCode("b0101".U) -> (io.DataInA ^ io.DataInB),
        io.OperateCode("b0110".U) -> ((io.DataInA < io.DataInB).asUInt),
        io.OperateCode("b0111".U) -> ((io.DataInA===io.DataInB).asUInt),

        io.OperateCode("b1000".U) -> io.DataInA,
        io.OperateCode("b1001".U) -> io.DataInB,
        io.OperateCode("b1010".U) -> (io.DataInA.asUInt >> io.DataInB(5, 0)).asUInt,
        io.OperateCode("b1011".U) -> (io.DataInA.asSInt << io.DataInB(5, 0)).asUInt,
        io.OperateCode("b1100".U) -> (io.DataInA.asSInt >> io.DataInB(5, 0)).asUInt,
        io.OperateCode("b1101".U) -> 0.U(64.W),
        io.OperateCode("b1110".U) -> io.DataInA,
        io.OperateCode("b1111".U) -> io.DataInB,
    ))
}