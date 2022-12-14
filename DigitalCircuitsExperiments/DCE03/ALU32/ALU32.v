module ALU32 (sub_add, a, b, carry, zero, overflow, result);
    input sub_add;// This is a switch of Add(0) or Sub(1)
    input [31:0] a; // This is a Complement number
    input [31:0] b; // This is a Complement number
    output reg [0:0] carry;
    output reg zero, overflow;
    output reg [31:0] result;
    reg [31:0] b_withCin;

    reg [31:0] expected_result;
    reg [0:0] expected_carry;
    reg expected_zero, expected_overflow;

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
endmodule
