package MSPC_ALU

object MSPC_ALU_Gen extends App{
    chisel3.Driver.execute(args, () => new MSPC_ALU)
}