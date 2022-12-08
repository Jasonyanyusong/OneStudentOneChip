module decode_2to4_for (x, en, y);
    input [1:0] x;
    input en;
    output reg [3:0] y;
    integer i;

    always @(x or en)
    begin
        if (en)
        begin
            /* verilator lint_off WIDTH */
            for (i=0; i <= 3; i = i + 1)
                if (x == i) 
                    y[i] = 1;
                else
                    y[i] = 0;
            /* verilator lint_on WIDTH */
        end
        else
            y = 4'b0000;
    end
endmodule
