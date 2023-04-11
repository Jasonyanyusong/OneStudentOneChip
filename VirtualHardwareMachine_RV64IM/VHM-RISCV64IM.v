module RV64IM_VHM(riscv_32bits_instruction, clk);
    input clk; // This is the clock of the VHM.

    input [31:0] riscv_32bits_instruction; // This is the only input of RV64IM_VHM, this is the port that the processor receive instruction from simulation and simulator.

    reg [63:0] vhm_pc, vhm_dnpc, vhm_snpc; // They are VHM's Program Counter, Dynamic Next Program Counter, Static Next Program Counter.

    reg [63:0] intreg_x00, intreg_x01, intreg_x02, intreg_x03, intreg_x04, intreg_x05, intreg_x06, intreg_x07;    // Register x00 to x07, XLEN = 64.
    reg [63:0] intreg_x80, intreg_x09, intreg_x10, intreg_x11, intreg_x12, intreg_x13, intreg_x14, intreg_x15;    // Register x08 to x15, XLEN = 64.
    reg [63:0] intreg_x16, intreg_x17, intreg_x18, intreg_x19, intreg_x20, intreg_x21, intreg_x22, intreg_x23;    // Register x16 to x23, XLEN = 64.
    reg [64:0] intreg_x24, intreg_x25, intreg_x26, intreg_x27, intreg_x28, intreg_x29, intreg_x30, intreg_x31;    // Register x24 to x31, XLEN = 64.

    reg [63:0] sim_integer_register[0:31]; // Registers with XLEN = 64, After executiion, copy sim_integer_register to intreg.

    reg [7:0] sim_memory[0:268435455]; // Memory size is 0x10000000.

    reg [6:0] opcode; // This is used for storing the opcode, the last 7 digit of instruction.

    always @(posedge clk)
    // We will first read the last 7 digit of the instruction, then determine the type of the instruction.
    // For differnt type of instruction, we will create another case model for dealing with the specific function.
    begin
        opcode = riscv_32bits_instruction[6:0];

        case (opcode)
            // TODO: the opcode is initialized, for some opcode, we may need another case structure.
        endcase

        sim_integer_register[0] = 64'b0000000000000000000000000000000000000000000000000000000000000000; // Register x0($0) is always 0.
        
        intreg_x00 = sim_integer_register[0];
    end

endmodule