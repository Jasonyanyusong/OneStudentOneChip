module MultiFunctionShiftRegister_NegEdge_8Bit (clk, sel, inp, D, Q);
    input clk;
    input inp;
    input [2:0] sel;
    input [7:0] D;
    output reg [7:0] Q;

    always @(negedge clk)
    begin
        case(sel)
            3'b000: Q <= 8'b00000000; // OK
            3'b001: Q <= D; // OK
            3'b010: Q <= Q >> 1; // OK
            3'b011: Q <= Q << 1; // OK
            3'b100: Q <= {Q[7], Q[7:1]}; // OK
            3'b101: Q <= {inp, Q[7:1]}; // OK
            3'b110: Q <= {Q[0], Q[7:1]}; // OK
            3'b111: Q <= {Q[6:0], Q[7]}; // OK
        endcase    
    end
endmodule
