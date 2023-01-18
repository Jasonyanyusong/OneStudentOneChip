module ArithmeticLeftShiftRegister_NegEdge_32Bit (clock, reset, D, Q);
    input clock;
    input reset;
    input [31:0] D;
    output reg [31:0] Q;

    always @(negedge clock)
    begin
        if (reset)
            Q = 32'b00000000000000000000000000000000;
        else
            Q = Q << 1 ;        
    end
endmodule
