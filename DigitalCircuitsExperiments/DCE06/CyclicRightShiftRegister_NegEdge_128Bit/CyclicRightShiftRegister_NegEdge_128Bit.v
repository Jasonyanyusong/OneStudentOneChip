module CyclicRightShiftRegister_NegEdge_128Bit (clock, reset, D, Q);
    input clock;
    input reset;
    input [127:0] D;
    output reg [127:0] Q;

    always @(negedge clock)
    begin
        if (reset)
            Q <= 128'b00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;
        else
            Q <= {D[0], D[127:1]};        
    end
endmodule
