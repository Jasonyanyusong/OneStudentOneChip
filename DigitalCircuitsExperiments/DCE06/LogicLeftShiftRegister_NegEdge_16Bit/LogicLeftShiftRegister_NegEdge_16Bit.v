module LogicLeftShiftRegister_NegEdge_16Bit (clock, reset, D, Q);
    input clock;
    input reset;
    input [15:0] D;
    output reg [15:0] Q;

    always @(negedge clock)
    begin
        if (reset)
            Q = 16'b0000000000000000;
        else
            Q = Q << 1 ;        
    end
endmodule
