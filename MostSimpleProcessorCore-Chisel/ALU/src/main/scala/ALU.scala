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
        val ValidOutput = Output(Bool(1.W))
    })
    io.ValidOutput := true.B
    io.ComputeResult := Mux(
        OperateCode(3),
        Mux(OperateCode(2),
            Mux(OperateCode(1),
                Mux(OperateCode(0), io.ValidOutput := false.B , io.ValidOutput := false.B),
                Mux(OperateCode(0), io.ValidOutput := false.B, io.ComputeResult := io.DataInA.S >> io.DataInB)),
            Mux(OperateCode(1),
                Mux(OperateCode(0), io.ComputeResult := io.DataInA.S << io.DataInB, io.ComputeResult := io.DataInA.U >> io.DataInB),
                Mux(OperateCode(0), io.ValidOutput := false.B, io.ValidOutput := false.B))),
        Mux(OperateCode(2),
            Mux(OperateCode(1),
                Mux(OperateCode(0), io.CompareResult := io.DataInA===io.DataInB, io.CompareResult := io.DataInA < io.DataInB),
                Mux(OperateCode(0), io.ComputeResult := io.DataInA ^ io.DataInB, io.ComputeResult := io.DataInA | io.DataInB)),
            Mux(OperateCode(1),
                Mux(OperateCode(0), io.CompareResult := io.DataInA & io.DataInB, io.ComputeResult := ~ io.DataInA),
                Mux(OperateCode(0), io.ComputeResult := io.DataInA - io.DataInB, io.ComputeResult := io.DataInA + io.DataInB))))
    io.CompareResult := Mux()
}