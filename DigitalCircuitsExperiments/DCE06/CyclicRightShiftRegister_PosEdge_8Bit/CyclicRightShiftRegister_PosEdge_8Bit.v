module CyclicRightShiftRegister_PosEdge_8Bit (clock, reset, D, Q);
    input clock;
    input reset;
    input [7:0] D;
    output reg [7:0] Q;

    always @(posedge clock)
    begin
        if (reset)
            Q <= 8'b00000000;
        else
            Q <= {D[0], D[7:1]};        
    end
endmodule
