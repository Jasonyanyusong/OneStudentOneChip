module decode_1to2_for (x, en, y);
    input [0:0] x;
    input en;
    output reg [1:0] y;
    integer i;

    always @(x or en)
    begin
        if (en)
        begin
            /* verilator lint_off WIDTH */
            for (i=0; i <= 1; i = i + 1)
                if (x == i) 
                    y[i] = 1;
                else
                    y[i] = 0;
            /* verilator lint_on WIDTH */
        end
        else
            y = 2'b00;
    end
endmodule
