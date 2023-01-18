module MultiFunctionShiftRegister_NegEdge_4Bit (clk, sel, inp, D, Q);
    input clk;
    input inp;
    input [2:0] sel;
    input [3:0] D;
    output reg [3:0] Q;

    always @(negedge clk)
    begin
        case(sel)
            3'b000: Q <= 4'b0000; // OK
            3'b001: Q <= D; // OK
            3'b010: Q <= Q >> 1; // OK
            3'b011: Q <= Q << 1; // OK
            3'b100: Q <= {Q[3], Q[3:1]}; // OK
            3'b101: Q <= {inp, Q[3:1]}; // OK
            3'b110: Q <= {Q[0], Q[3:1]}; // OK
            3'b111: Q <= {Q[2:0], Q[3]}; // OK
        endcase    
    end
endmodule
