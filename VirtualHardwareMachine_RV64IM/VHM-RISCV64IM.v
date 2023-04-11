module RV64IM_VHM(riscv_32bits_instruction, clk);
    input clk; // This is the clock of the VHM.

    input [31:0] riscv_32bits_instruction; // This is the only input of RV64IM_VHM, this is the port that the processor receive instruction from simulation and simulator.

    reg [6:0] opcode; // This is used for storing the opcode, the last 7 digit of instruction.

    reg [4:0] rd, rs1, rs2, rs3; // They are the VHM's 5 bit register indicator (the 5 bit value indicates which register to modify).

    reg [6:0] funct7; // This is the VHM's funct7 for R-type instructions.
    reg [2:0] funct3; // This is the VHM's funct3 for R-type, I-type, S-type, B-type and R4-type instructions.
    reg [1:0] funct2; // This is the VHM's funct2 for R4-type instructions.

    reg [11:0] imm_I; // This is the VHM's immediate number for I-type instructions
    reg [11:0] imm_S; // This is the VHM's immediate number for S-type instructions
    reg [12:0] imm_B; // This is the VHM's immediate number for B-type instructions
    reg [31:0] imm_U; // This is the VHM's immediate number for U-type instructions
    reg [20:0] imm_J; // This is the VHM's immediate number for J-type instructions

    reg [63:0] vhm_pc, vhm_dnpc, vhm_snpc; // They are VHM's Program Counter, Dynamic Next Program Counter, Static Next Program Counter.

    reg [63:0] intreg_x00, intreg_x01, intreg_x02, intreg_x03, intreg_x04, intreg_x05, intreg_x06, intreg_x07;    // Register x00 to x07, XLEN = 64.
    reg [63:0] intreg_x08, intreg_x09, intreg_x10, intreg_x11, intreg_x12, intreg_x13, intreg_x14, intreg_x15;    // Register x08 to x15, XLEN = 64.
    reg [63:0] intreg_x16, intreg_x17, intreg_x18, intreg_x19, intreg_x20, intreg_x21, intreg_x22, intreg_x23;    // Register x16 to x23, XLEN = 64.
    reg [63:0] intreg_x24, intreg_x25, intreg_x26, intreg_x27, intreg_x28, intreg_x29, intreg_x30, intreg_x31;    // Register x24 to x31, XLEN = 64.

    reg [63:0] sim_integer_register[0:31]; // Registers with XLEN = 64, After executiion, copy sim_integer_register to intreg.

    reg [7:0] sim_memory[0:268435455]; // Memory size is 0x10000000.

    always @(posedge clk)
    // We will first read the last 7 digit of the instruction, then determine the type of the instruction.
    // For differnt type of instruction, we will create another case model for dealing with the specific function.
    begin
        // Before the execution of the instruction, we first get the opcode, then we get the register indicators and last we get the immediate values.
        opcode = riscv_32bits_instruction[6:0];
        rd = riscv_32bits_instruction[11:7];
        rs1 = riscv_32bits_instruction[19:15];
        rs2 = riscv_32bits_instruction[24:20];
        rs3 = riscv_32bits_instruction[31:27];
        imm_I = riscv_32bits_instruction[31:20];
        imm_S[11:5] = riscv_32bits_instruction[31:25]; imm_S[4:0] = riscv_32bits_instruction[11:7];
        imm_B[12:12] = riscv_32bits_instruction[31:31]; imm_B[11:11] = riscv_32bits_instruction[7:7]; imm_B[10:5] = riscv_32bits_instruction[30:25]; imm_B[4:1] = riscv_32bits_instruction[11:8]; imm_B[0] = 1'b0;
        imm_U[31:12] = riscv_32bits_instruction[31:12]; imm_U[11:0] = 12'b000000000000;
        imm_J[20] = riscv_32bits_instruction[31]; imm_J[19:12] = riscv_32bits_instruction[19:12]; imm_J[11] = riscv_32bits_instruction[20]; imm_J[10:1] = riscv_32bits_instruction[30:21]; imm_J[0] = 1'b0;


        case (opcode)
            // TODO: the opcode is initialized, for some opcode, we may need another case structure.
        endcase

        sim_integer_register[0] = 64'b0000000000000000000000000000000000000000000000000000000000000000; // Register x0($0) is always 0.
        
        // Copy each register's value from sim_integer_register to intreg (This can make later observation easier)
        intreg_x00 = sim_integer_register[0];
        intreg_x01 = sim_integer_register[1];
        intreg_x02 = sim_integer_register[2];
        intreg_x03 = sim_integer_register[3];
        intreg_x04 = sim_integer_register[4];
        intreg_x05 = sim_integer_register[5];
        intreg_x06 = sim_integer_register[6];
        intreg_x07 = sim_integer_register[7];
        intreg_x08 = sim_integer_register[8];
        intreg_x09 = sim_integer_register[9];
        intreg_x10 = sim_integer_register[10];
        intreg_x11 = sim_integer_register[11];
        intreg_x12 = sim_integer_register[12];
        intreg_x13 = sim_integer_register[13];
        intreg_x14 = sim_integer_register[14];
        intreg_x15 = sim_integer_register[15];
        intreg_x16 = sim_integer_register[16];
        intreg_x17 = sim_integer_register[17];
        intreg_x18 = sim_integer_register[18];
        intreg_x19 = sim_integer_register[19];
        intreg_x20 = sim_integer_register[20];
        intreg_x21 = sim_integer_register[21];
        intreg_x22 = sim_integer_register[22];
        intreg_x23 = sim_integer_register[23];
        intreg_x24 = sim_integer_register[24];
        intreg_x25 = sim_integer_register[25];
        intreg_x26 = sim_integer_register[26];
        intreg_x27 = sim_integer_register[27];
        intreg_x28 = sim_integer_register[28];
        intreg_x29 = sim_integer_register[29];
        intreg_x30 = sim_integer_register[30];
        intreg_x31 = sim_integer_register[31];
    end

endmodule