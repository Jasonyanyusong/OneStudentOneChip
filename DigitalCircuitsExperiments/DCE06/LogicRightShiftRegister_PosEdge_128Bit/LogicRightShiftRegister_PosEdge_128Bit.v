module LogicRightShiftRegister_PosEdge_128Bit (clock, reset, D, Q);
    input clock;
    input reset;
    input [127:0] D;
    output reg [127:0] Q;

    always @(posedge clock)
    begin
        if (reset)
            Q = 128'b00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000;
        else
            Q = Q >> 1 ;        
    end
endmodule
