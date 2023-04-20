package test
import chisel3._
import chisel3.experimental._
class ALU extends Module{
    val io = IO(new Bundle{
        val DataInA = Input(UInt(64.W))
        val DataInB = Input(UInt(64.W))
        val OperateCode = Input(UInt(4.W))
        val ComputeResult = Output(UInt(64.W))
        val CompareResult = Output(Bool())
    })

    io.ComputeResult := Mux(
        io.OperateCode(3),
        Mux(io.OperateCode(2),
            Mux(io.OperateCode(1),
                Mux(io.OperateCode(0), 0.U(64.W), 0.U(64.W)),
                Mux(io.OperateCode(0), 0.U(64.W), io.DataInA.asSInt >> io.DataInB)),
            Mux(io.OperateCode(1),
                Mux(io.OperateCode(0), io.DataInA.asSInt << io.DataInB, io.DataInA.asUInt >> io.DataInB),
                Mux(io.OperateCode(0), 0.U(64.W), 0.U(64.W)))),
        Mux(io.OperateCode(2),
            Mux(io.OperateCode(1),
                Mux(io.OperateCode(0), 0.U(64.W), 0.U(64.W)),
                Mux(io.OperateCode(0), io.DataInA ^ io.DataInB, io.DataInA | io.DataInB)),
            Mux(io.OperateCode(1),
                Mux(io.OperateCode(0), io.DataInA & io.DataInB, ~ io.DataInA),
                Mux(io.OperateCode(0), io.DataInA - io.DataInB, io.DataInA + io.DataInB))))

    io.CompareResult := Mux(
        io.OperateCode(3),
        Mux(io.OperateCode(2),
            Mux(io.OperateCode(1),
                Mux(io.OperateCode(0), 0.U.asBool, 0.U.asBool),
                Mux(io.OperateCode(0), 0.U.asBool, 0.U.asBool)),
            Mux(io.OperateCode(1),
                Mux(io.OperateCode(0), 0.U.asBool, 0.U.asBool),
                Mux(io.OperateCode(0), 0.U.asBool, 0.U.asBool))),
        Mux(io.OperateCode(2),
            Mux(io.OperateCode(1),
                Mux(io.OperateCode(0), io.DataInA===io.DataInB, io.DataInA < io.DataInB),
                Mux(io.OperateCode(0), 0.U.asBool, 0.U.asBool)),
            Mux(io.OperateCode(1),
                Mux(io.OperateCode(0), 0.U.asBool, 0.U.asBool),
                Mux(io.OperateCode(0), 0.U.asBool, 0.U.asBool))))
}