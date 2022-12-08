module encode_8to3_case (x, en, y);
    input [7:0] x;
    input en;
    output reg [2:0] y;

    always @(x or en) 
    begin
        if (en) 
        begin
            case (x)
                8'b00000001 : y = 3'b000;
                8'b00000010 : y = 3'b001;
                8'b00000100 : y = 3'b010;
                8'b00001000 : y = 3'b011;
                8'b00010000 : y = 3'b100;
                8'b00100000 : y = 3'b101;
                8'b01000000 : y = 3'b110;
                8'b10000000 : y = 3'b111;
                default : y = 3'b000;
            endcase
        end
        else y = 3'b000;
    end
endmodule
