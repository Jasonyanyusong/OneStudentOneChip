module ArithmeticLeftShiftRegister_NegEdge_8Bit (clock, reset, D, Q);
    input clock;
    input reset;
    input [7:0] D;
    output reg [7:0] Q;

    always @(negedge clock)
    begin
        if (reset)
            Q = 8'b00000000;
        else
            Q = Q << 1 ;        
    end
endmodule
