module decode_4to16_for (x, en, y);
    input [3:0] x;
    input en;
    output reg [15:0] y;
    integer i;

    always @(x or en)
    begin
        if (en)
        begin
            /* verilator lint_off WIDTH */
            for (i=0; i <= 15; i = i + 1)
                if (x == i) 
                    y[i] = 1;
                else
                    y[i] = 0;
            /* verilator lint_on WIDTH */
        end
        else
            y = 16'b0000000000000000;
    end
endmodule
