import chisel3._
import chisel3.util._

class MSPCC extends Module{

    val io = IO(new Bundle{ val halt = Output(Bool())})
    val R = Mem(32, UInt(64.W))
    val PC = RegInit(0.U(64.W))
    val M = Mem (1024 / 4, UInt(32.W))
    def Rread(index: UInt) = Mux(idex === 0, 0.U(64.W), R(index))

    val Inst_Bundle = new Bundle{
        val Inst_DifferentAmongTypes = UInt(25.W)
        val Inst_OpCode = UInt(7.W)
    }

    val Rtype_Bundle = new Bundle{
        val Rtype_funct7 = UInt(7.W)
        val Rtype_rs2 = UInt(5.W)
        val Rtype_rs1 = UInt(5.W)
        val Rtype_funct3 = UInt(3.W)
        val Rtype_rd = UInt(5.W)
        val Rtype_opcode = UInt(7.W)
    }

    val Itype_Bundle = new Bundle{
        val Itype_imm11_0 = UInt(12.W)
        val Itype_rs1 = UInt(5.W)
        val Itype_funct3 = UInt(3.W)
        val Itype_rd = UInt(5.W)
        val Itype_opcode = UInt(7.W)
    }
    def Itype_SignExtent(Itype_imm11_0: UInt) = Cat(Fill(52, Itype_imm11_0(11)), Itype_imm11_0)

    val Stype_Bundle = new Bundle{
        val Stype_imm11_5 = UInt(7.W)
        val Rtype_rs2 = UInt(5.W)
        val Stype_rs1 = UInt(5.W)
        val Stype_funct3 = UInt(3.W)
        val Stype_imm5_0 = UInt(5.W)
        val Stype_opcode = UInt(7.W)
    }
    def Stype_SignExtent(Stype_imm11_5: UInt, Stype_imm5_0: UInt) = Cat(Fill(52, Stype_imm11_5(6)), Stype_imm11_5, Stype_imm5_0)
    
    val Btype_Bundle = new Bundle{
        // TODO
    }
    // def Btype_SignExtent TODO

    val Utype_Bundle = new Bundle{
        val Utype_imm31_12 = UInt(20.W)
        val Utype_rd = UInt(5.W)
        val Utype_opcode = UInt(7.W)
    }
    def Utype_SignExtent(Utype_imm31_12: UInt) = Cat(Fill(32, Utype_imm31_12(19)), Utype_imm31_12, Fill(12, 0))

    val Jtype_Bundle = new Bundle{
        // TODO
    }
    // def Jtype_SignExtent TODO

    val inst = M(PC(63, 2)).asTypeOf(Inst_Bundle)
    val isRtype = // TODO
    val isItype = // TODO
    val isStype = // TODO
    val isBtype = // TODO
    val isUtype = // TODO
    val isJtype = // TODO

    PC := PC + 4.U
}