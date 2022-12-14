module ALU32_Test (sub_add, a, b, carry, zero, overflow, result);
    input sub_add;// This is a switch of Add(0) or Sub(1)
    input [31:0] a; // This is a Complement number
    input [31:0] b; // This is a Complement number
    output reg [0:0] carry;
    output reg zero, overflow;
    output reg [31:0] result;
    reg [31:0] b_withCin;

    always @(sub_add) 
    /* verilator lint_off WIDTH */
    begin
        assign b_withCin = ({32{sub_add}}^b) + sub_add;
        assign result = a + b_withCin;
        assign carry = a[30] == 1 && b[30] == 1;
        assign overflow = (a[31] == b_withCin[31] && result[31] != a[31]);
        assign zero = ~(| result);
    end
    /* verilator lint_on WIDTH */

    // Give result of test bench # 1
    reg [31:0] test1_expected_result;
    reg [0:0] test1_expected_carry;
    reg test1_expected_zero, test1_expected_overflow;
    assign test1_expected_result = 32'b00110011100000101001101110011100;
    assign test1_expected_carry = 1'b0;
    assign test1_expected_overflow = 0;
    assign test1_expected_zero = 0;

    // Give result of test bench # 2
    reg [31:0] test2_expected_result;
    reg [0:0] test2_expected_carry;
    reg test2_expected_zero, test2_expected_overflow;
    assign test2_expected_result = 32'b11110001010010000110010111011111;
    assign test2_expected_carry = 1'b0;
    assign test2_expected_overflow = 0;
    assign test2_expected_zero = 0;

endmodule
