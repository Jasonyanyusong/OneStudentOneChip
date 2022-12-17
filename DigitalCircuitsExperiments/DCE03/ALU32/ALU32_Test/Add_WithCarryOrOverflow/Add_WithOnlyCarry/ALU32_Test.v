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

    // Give result of test bench F1S2B1T1
    reg [31:0] testF1S2B1T1_expected_result;
    reg [0:0] testF1S2B1T1_expected_carry;
    reg testF1S2B1T1_expected_zero, testF1S2B1T1_expected_overflow;
    assign testF1S2B1T1_expected_result = 32'b01000110101011101010000101010100;
    assign testF1S2B1T1_expected_carry = 1'b0;
    assign testF1S2B1T1_expected_overflow = 0;
    assign testF1S2B1T1_expected_zero = 0;

endmodule
