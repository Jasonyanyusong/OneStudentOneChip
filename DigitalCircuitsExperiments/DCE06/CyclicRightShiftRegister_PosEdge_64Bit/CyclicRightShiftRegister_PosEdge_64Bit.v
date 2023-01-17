module CyclicRightShiftRegister_PosEdge_64Bit (clock, reset, D, Q);
    input clock;
    input reset;
    input [63:0] D;
    output reg [63:0] Q;

    always @(posedge clock)
    begin
        if (reset)
            Q <= 64'b0000000000000000000000000000000000000000000000000000000000000000;
        else
            Q <= {D[0], D[63:1]};        
    end
endmodule
