module AddMinusALU_32(sub_add, a, b, carry, zero, overflow, result);
    input sub_add;
    input [31:0] a;
    input [31:0] b;
    output carry, zero, overflow;
    output [31:0] result;
    wire Cin;
    wire [31:0] t_no_Cin;
    /* verilator lint_off WIDTH */
    /* verilator lint_off SELRANGE */
    assign Cin = sub_add;
    assign t_no_Cin = {32{ Cin }}^b;
    assign {carry,result} = a + t_no_Cin + Cin;
    assign overflow = (a[31] == t_no_Cin[31]) && (result [31] != a[31]);
    assign zero = ~(| result);
    /* verilator lint_on WIDTH */
    /* verilator lint_on SELRANGE */

endmodule