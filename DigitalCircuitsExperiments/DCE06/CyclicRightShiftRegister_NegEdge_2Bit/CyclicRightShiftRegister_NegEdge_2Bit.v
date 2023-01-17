module CyclicRightShiftRegister_NegEdge_2Bit (clock, reset, D, Q);
    input clock;
    input reset;
    input [1:0] D;
    output reg [1:0] Q;

    always @(negedge clock)
    begin
        if (reset)
            Q <= 2'b00;
        else
            Q <= {D[0], D[1:1]};        
    end
endmodule
