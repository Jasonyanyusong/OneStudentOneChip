package Passthrough

import chisel3._
import chisel3.util._
import chisel3.tester._
import chisel3.tester.RawTester.test
import dotvisualizer._

class Passthrough extends Module{
    val io = IO(new Bundle{
        val in = Input(UInt(4.W))
        val out = Output(UInt(4.W))
    })
    io.out := io.in
}

object Main{
    def main(args: Array[String]) : Unit = {
        println("Generating Passthrough")
        chisel3.Driver.execute(Array("--target-dir", "generated"), () => new Passthrough)
    }
}