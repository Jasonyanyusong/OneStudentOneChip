module MultiFunctionShiftRegister_NegEdge_2Bit (clk, sel, inp, D, Q);
    input clk;
    input inp;
    input [2:0] sel;
    input [1:0] D;
    output reg [1:0] Q;

    always @(negedge clk)
    begin
        case(sel)
            3'b000: Q <= 2'b00;
            3'b001: Q <= D;
            3'b010: Q <= Q >> 1;
            3'b011: Q <= Q << 1;
            3'b100: Q <= {Q[1], Q[1:1]};
            3'b101: Q <= {inp, Q[1:1]};
            3'b110: Q <= {D[0], D[1:1]};
            3'b111: Q <= {D[0:0], D[1]};
        endcase    
    end
endmodule
