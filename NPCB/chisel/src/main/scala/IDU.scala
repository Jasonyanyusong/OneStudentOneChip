package npcb
import chisel3._
import chisel3.util._

class IDU extends Module{
    val io = IO(new Bundle{
        val IDU_Inst = Input(UInt(32.W))
        val IDU_EXUopcode = Output(UInt(32.W))
        val IDU_EXUorLSUswitch = Output(Bool())
        val IDU_RD = Output(UInt(5.W))
        val IDU_RS1 = Output(UInt(5.W))
        val IDU_RS2 = Output(UInt(5.W))
    })

    val IDU_Rtype_Bundle = new Bundle{
        val IDU_Rtype_funct7 = UInt(7.W)
        val IDU_Rtype_rs2 = UInt(5.W)
        val IDU_Rtype_rs1 = UInt(5.W)
        val IDU_Rtype_funct3 = UInt(3.W)
        val IDU_Rtype_rd = UInt(5.W)
        val IDU_Rtype_opcode = UInt(7.W)
    }

    val IDU_Itype_Bundle = new Bundle{
        val IDU_Itype_imm11_00 = UInt(12.W)
        val IDU_Itype_rs1 = UInt(5.W)
        val IDU_Itype_funct3 = UInt(3.W)
        val IDU_Itype_rd = UInt(5.W)
        val IDU_Itype_opcode = UInt(7.W)
    }

    val IDU_Stype_Bundle = new Bundle{
        val IDU_Stype_imm11_05 = UInt(7.W)
        val IDU_Stype_rs2 = UInt(5.W)
        val IDU_Stype_rs1 = UInt(5.W)
        val IDU_Stype_funct3 = UInt(3.W)
        val IDU_Stype_imm04_00 = UInt(5.W)
        val IDU_Stype_opcode = UInt(7.W)
    }

    val IDU_Btype_Bundle = new Bundle{
        val IDU_Btype_imm12_12 = UInt(1.W)
        val IDU_Btype_imm10_05 = UInt(6.W)
        val IDU_Btype_rs2 = UInt(5.W)
        val IDU_Btype_rs1 = UInt(5.W)
        val IDU_Btype_funct3 = UInt(3.W)
        val IDU_Btype_imm04_01 = UInt(4.W)
        val IDU_Btype_imm11_11 = UInt(1.W)
        val IDU_Btype_opcode = UInt(7.W)
    }

    val IDU_Utype_Bundle = new Bundle{
        val IDU_Utype_imm31_12 = UInt(20.W)
        val IDU_Utype_rd = UInt(5.W)
        val IDU_Utype_opcode = UInt(7.W)
    }

    val IDU_Jtype_Bundle = new Bundle{
        val IDU_Jtype_imm20_20 = UInt(1.W)
        val IDU_Jtype_imm10_01 = UInt(10.W)
        val IDU_Jtype_imm11_11 = UInt(1.W)
        val IDU_Jtype_imm19_12 = UInt(8.W)
        val IDU_Jtype_rd = UInt(5.W)
        val IDU_Jtype_opcode = UInt(7.W)
    }
}