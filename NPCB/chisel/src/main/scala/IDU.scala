package npcb
import chisel3._
import chisel3.util._

class IDU extends Module{

    val io = IO(new Bundle{
        val IDU_InstIn = Input(UInt(32.W))
        val IDU_isJump = Output(Bool())
        val IDU_getRS1 = Output(UInt(5.W))
        val IDU_getRS2 = Output(UInt(5.W))
        val IDU_getRD = Output(UInt(5.W))
        val IDU_ALUEnable = Output(Bool())
        val IDU_LSUEnable = Output(Bool())
        val IDU_EXUOperateCode = Output(UInt(4.W))
        val IDU_EXUTreatUnsigned = Output(Bool())
        val IDU_EXUTreatSigned = Output(Bool())
        val IDU_EXULSUModuleHaveWriteBack = Output(Bool())
    })

  //    Inst Name          funct7   rs2   rs1 func3  rd   opcode
    def LUI     = BitPat("b???????_?????_?????_???_?????_0110111")
    def AUIPC   = BitPat("b???????_?????_?????_???_?????_0010111")
    def JAL     = BitPat("b???????_?????_?????_???_?????_1101111")
    def JALR    = BitPat("b???????_?????_?????_000_?????_1100111")
    def BEQ     = BitPat("b???????_?????_?????_000_?????_1100011")
    def BNE     = BitPat("b???????_?????_?????_001_?????_1100011")
    def BLT     = BitPat("b???????_?????_?????_100_?????_1100011")
    def BGE     = BitPat("b???????_?????_?????_101_?????_1100011")
    def BLTU    = BitPat("b???????_?????_?????_110_?????_1100011")
    def BGEU    = BitPat("b???????_?????_?????_111_?????_1100011")
    def LB      = BitPat("b???????_?????_?????_000_?????_0000011")
    def LH      = BitPat("b???????_?????_?????_001_?????_0000011")
    def LW      = BitPat("b???????_?????_?????_010_?????_0000011")
    def LBU     = BitPat("b???????_?????_?????_100_?????_0000011")
    def LHU     = BitPat("b???????_?????_?????_101_?????_0000011")
    def SB      = BitPat("b???????_?????_?????_000_?????_0100011")
    def SH      = BitPat("b???????_?????_?????_001_?????_0100011")
    def SW      = BitPat("b???????_?????_?????_010_?????_0100011")
    def ADDI    = BitPat("b???????_?????_?????_000_?????_0010011")
    def SLTI    = BitPat("b???????_?????_?????_010_?????_0010011")
    def SLTIU   = BitPat("b???????_?????_?????_011_?????_0010011")
    def XORI    = BitPat("b???????_?????_?????_100_?????_0010011")
    def ORI     = BitPat("b???????_?????_?????_110_?????_0010011")
    def ANDI    = BitPat("b???????_?????_?????_111_?????_0010011")
    def SLLI    = BitPat("b000000?_?????_?????_001_?????_0010011")
    def SRLI    = BitPat("b000000?_?????_?????_101_?????_0010011")
    def SRAI    = BitPat("b010000?_?????_?????_101_?????_0010011")
    def ADD     = BitPat("b0000000_?????_?????_000_?????_0110011")
    def SUB     = BitPat("b0100000_?????_?????_000_?????_0110011")
    def SLL     = BitPat("b0000000_?????_?????_001_?????_0110011")
    def SLT     = BitPat("b0000000_?????_?????_010_?????_0110011")
    def SLTU    = BitPat("b0000000_?????_?????_011_?????_0110011")
    def XOR     = BitPat("b0000000_?????_?????_100_?????_0110011")
    def SRL     = BitPat("b0000000_?????_?????_101_?????_0110011")
    def SRA     = BitPat("b0100000_?????_?????_101_?????_0110011")
    def OR      = BitPat("b0000000_?????_?????_110_?????_0110011")
    def AND     = BitPat("b0000000_?????_?????_111_?????_0110011")
    def PAUSE   = BitPat("b0000000_10000_00000_000_00000_0001111")
    def ECALL   = BitPat("b0000000_00000_00000_000_00000_1110011")
    def EBREAK  = BitPat("b0000000_00001_00000_000_00000_1110011")
    def LWU     = BitPat("b???????_?????_?????_110_?????_0000011")
    def LD      = BitPat("b???????_?????_?????_011_?????_0000011")
    def SD      = BitPat("b???????_?????_?????_011_?????_0100011")
    def ADDIW   = BitPat("b???????_?????_?????_000_?????_0011011")
    def SLLIW   = BitPat("b0000000_?????_?????_001_?????_0011011")
    def SRLIW   = BitPat("b0000000_?????_?????_101_?????_0011011")
    def SRAIW   = BitPat("b0100000_?????_?????_101_?????_0011011")
    def ADDW    = BitPat("b0000000_?????_?????_000_?????_0111011")
    def SUBW    = BitPat("b0100000_?????_?????_000_?????_0111011")
    def SLLW    = BitPat("b0000000_?????_?????_001_?????_0111011")
    def SRLW    = BitPat("b0000000_?????_?????_101_?????_0111011")
    def SRAW    = BitPat("b0100000_?????_?????_101_?????_0111011")
    def MUL     = BitPat("b0000001_?????_?????_000_?????_0110011")
    def MULH    = BitPat("b0000001_?????_?????_001_?????_0110011")
    def MULHSU  = BitPat("b0000001_?????_?????_010_?????_0110011")
    def MULHU   = BitPat("b0000001_?????_?????_011_?????_0110011")
    def DIV     = BitPat("b0000001_?????_?????_100_?????_0110011")
    def DIVU    = BitPat("b0000001_?????_?????_101_?????_0110011")
    def REM     = BitPat("b0000001_?????_?????_110_?????_0110011")
    def REMU    = BitPat("b0000001_?????_?????_111_?????_0110011")
    def MULW    = BitPat("b0000001_?????_?????_000_?????_0111011")
    def DIVW    = BitPat("b0000001_?????_?????_100_?????_0111011")
    def DIVUW   = BitPat("b0000001_?????_?????_101_?????_0111011")
    def REMW    = BitPat("b0000001_?????_?????_110_?????_0111011")
    def REMUW   = BitPat("b0000001_?????_?????_111_?????_0111011")
    def INV     = BitPat("b???????_?????_?????_???_?????_???????")
}