module decode_3to8_case (x, en, y);
/* verilator lint_off WIDTH */
    input [2:0] x;
    input en;
    output reg [7:0] y;

    always @ (x or en)
    
        if (en)
        begin
            case (x)
                3'b000 : y = 8'b00000001;
                3'b001 : y = 8'b00000010;
                3'b010 : y = 8'b00000100;
                3'b011 : y = 8'b00001000;
                3'b100 : y = 8'b00010000;
                3'b101 : y = 8'b00100000;
                3'b110 : y = 8'b01000000;
                3'b111 : y = 8'b10000000;
            endcase
        end
        else y =8'b00000000;
/* verilator lint_on WIDTH */
endmodule
