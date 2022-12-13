module ALU32 (sub_add, a, b, carry, zero, overflow, result);
    input sub_add;// This is a switch of Add(0) or Sub(1)
    input [31:0] a; // This is a Complement number
    input [31:0] b; // This is a Complement number
    output reg carry, zero, overflow;
    output reg [31:0] result;
    reg [31:0] b_withCin;

    always @(sub_add) 
    begin
        assign b_withCin = ({32{sub_add}}^b) + sub_add;
        assign { carry, result } = a + b_withCin;
        assign overflow = (a[31] == b_withCin[31] && result[31] != a[31]);
        assign zero = ~(| result);
    end
endmodule