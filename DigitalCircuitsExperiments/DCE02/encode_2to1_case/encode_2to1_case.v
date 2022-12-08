module encode_2to1_case (x, en, y);
    input [1:0] x;
    input en;
    output reg [0:0] y;

    always @(x or en) 
    begin
        if (en) 
        begin
            case (x)
                2'b01 : y = 1'b0;
                2'b10 : y = 1'b1;
                default : y = 1'b0;
            endcase
        end
        else y = 1'b0;
    end
endmodule
