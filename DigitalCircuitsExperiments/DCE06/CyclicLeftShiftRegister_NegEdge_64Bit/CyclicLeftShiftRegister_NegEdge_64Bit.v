module CyclicLeftShiftRegister_NegEdge_64Bit (clock, reset, D, Q);
    input clock;
    input reset;
    input [63:0] D;
    output reg [63:0] Q;

    always @(negedge clock)
    begin
        if (reset)
            Q <= 64'b0000000000000000000000000000000000000000000000000000000000000000;
        else
            Q <= {D[62:0], D[63]};        
    end
endmodule
