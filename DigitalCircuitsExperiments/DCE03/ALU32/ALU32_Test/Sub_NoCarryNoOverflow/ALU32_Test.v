module ALU32_Test (sub_add, a, b, carry, zero, overflow, result);
    input sub_add;// This is a switch of Add(0) or Sub(1)
    input [31:0] a; // This is a Complement number
    input [31:0] b; // This is a Complement number
    output reg [0:0] carry;
    output reg zero, overflow;
    output reg [31:0] result;
    reg [31:0] b_withCin;

    always @(*) 
    /* verilator lint_off WIDTH */
    begin
        assign b_withCin = ({32{sub_add}}^b) + sub_add;
        assign result = a + b_withCin;
        assign carry = a[30] == 1 && b[30] == 1;
        assign overflow = (a[31] == b_withCin[31] && result[31] != a[31]);
        assign zero = ~(| result);
    end
    /* verilator lint_on WIDTH */

    /* verilator lint_off IMPLICIT */
    
    // Give result of test bench F2S1B1T1
    reg [31:0] testF2S1B1T1_expected_result;
    reg [0:0] testF2S1B1T1_expected_carry;
    reg testF2S1B1T1_expected_zero, testF2S1B1T1_expected_overflow;
    assign testF2S1B1T1_expected_result = 32'b01000010001110100011010111000110;
    assign testF2S1B1T1_expected_carry = 1'b0;
    assign testF2S1B1T1_expected_overflow = 0;
    assign testF2S1B1T1_expected_zero = 0;

    // Give result of test bench F2S1B2T1
    reg [31:0] testF2S1B2T1_expected_result;
    reg [0:0] testF2S1B2T1_expected_carry;
    reg testF2S1B2T1_expected_zero, testF2S1B2T1_expected_overflow;
    assign testF2S1B2T1_expected_result = 32'b00110011100000101001101110011100;
    assign testF2S1B2T1_expected_carry = 1'b0;
    assign testF2S1B2T1_expected_overflow = 0;
    assign testF2S1B2T1_expected_zero = 0;

    // Give result of test bench F2S1B2T2
    reg [31:0] testF2S1B2T2_expected_result;
    reg [0:0] testF2S1B2T2_expected_carry;
    reg testF2S1B1T2_expected_zero, testF2S1B1T2_expected_overflow;
    assign testF2S1B2T2_expected_result = 32'b00000000000000000000000000000000;
    assign testF2S1B2T2_expected_carry = 1'b0;
    assign testF2S1B2T2_expected_overflow = 0;
    assign testF2S1B2T2_expected_zero = 0;

    // Give result of test bench F2S1B2T3
    reg [31:0] testF2S1B2T3_expected_result;
    reg [0:0] testF2S1B2T3_expected_carry;
    reg testF2S1B1T3_expected_zero, testF2S1B1T3_expected_overflow;
    assign testF2S1B2T3_expected_result = 32'b11001100011111010110010001100100;
    assign testF2S1B2T3_expected_carry = 1'b0;
    assign testF2S1B2T3_expected_overflow = 0;
    assign testF2S1B2T3_expected_zero = 0;

    // Give result of test bench F2S1B3T1
    reg [31:0] testF2S1B3T1_expected_result;
    reg [0:0] testF2S1B3T1_expected_carry;
    reg testF2S1B3T1_expected_zero, testF2S1B3T1_expected_overflow;
    assign testF2S1B3T1_expected_result = 32'b11001100011111010110010001100100;
    assign testF2S1B3T1_expected_carry = 1'b0;
    assign testF2S1B3T1_expected_overflow = 0;
    assign testF2S1B3T1_expected_zero = 0;

    // Give result of test bench F2S1B3T2
    reg [31:0] testF2S1B3T2_expected_result;
    reg [0:0] testF2S1B3T2_expected_carry;
    reg testF2S1B3T2_expected_zero, testF2S1B3T2_expected_overflow;
    assign testF2S1B3T2_expected_result = 32'b00000000000000000000000000000000;
    assign testF2S1B3T2_expected_carry = 1'b0;
    assign testF2S1B3T2_expected_overflow = 0;
    assign testF2S1B3T2_expected_zero = 0;

    // Give result of test bench F2S1B3T3
    reg [31:0] testF2S1B3T3_expected_result;
    reg [0:0] testF2S1B3T3_expected_carry;
    reg testF2S1B3T3_expected_zero, testF2S1B3T3_expected_overflow;
    assign testF2S1B3T3_expected_result = 32'b00110011100000101001101110011100;
    assign testF2S1B3T3_expected_carry = 1'b0;
    assign testF2S1B3T3_expected_overflow = 0;
    assign testF2S1B3T3_expected_zero = 0;

    /* verilator lint_on IMPLICIT */

endmodule
