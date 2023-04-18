package Passthrough

import chisel3._
import chisel3.util._
import chisel3.tester._
import chisel3.tester.RawTester.test
import dotvisualizer._
import chisel3.stage.ChiselGeneratorAnnotation

class Passthrough extends Module{
    val io = IO(new Bundle{
        val in = Input(UInt(4.W))
        val out = Output(UInt(4.W))
    })
    io.out := io.in
}

/*println(getVerilog(new Passthrough))

test(new Passthrough()){ c =>
    c.io.in.poke(0.U)
    c.io.out.expect(0.U)
    c.io.in.poke(1.U)
    c.io.out.expect(1.U)
    c.io.in.poke(2.U)
    c.io.out.expect(2.U)
    c.io.in.poke(3.U)
    c.io.out.expect(4.U)
}

println("SUCCESS!!")*/

object PassthroughMain extends App{
    (new chisel3.stage.ChiselStage).emitVerilog(new Passthrough, args)
}