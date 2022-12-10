module my_not (a, y);
    input a;
    output reg y;

    always @(a) 
    begin
        case (a)
        1 : y = 0;
        0 : y = 1;
        endcase
    end
endmodule
