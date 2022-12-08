module decode_1to2_case (x, en, y);
    input [0:0] x;
    input en;
    output reg [1:0] y;

    always @ (x or en)
        if (en)
        begin
            case(x)
                1'd0 : y = 2'b01;
                1'd1 : y = 2'b10;
            endcase
        end
        else y =2'b00;
endmodule
