module ArithmeticRightShiftRegister_PosEdge_2Bit (clock, reset, D, Q);
    input clock;
    input reset;
    input [1:0] D;
    output reg [1:0] Q;

    always @(posedge clock)
    begin
        if (reset)
            Q <= 2'b00;
        else
            Q <= {D[1], D[1:1]};        
    end
endmodule
