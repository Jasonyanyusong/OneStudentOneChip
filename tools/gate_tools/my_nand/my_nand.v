module my_nand (a, b, y);
    input a,b;
    output reg y;

    always @(a or b) 
    begin
        case (a)
        1 : case (b)
            1 : y = 0;
            0 : y = 1;
        endcase
        0 : case (b)
            1 : y = 1;
            0 : y = 1;
        endcase
        endcase
    end
endmodule
