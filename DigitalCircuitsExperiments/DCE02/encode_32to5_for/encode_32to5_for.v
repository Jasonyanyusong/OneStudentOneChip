module encode_32to5_for(x, en, y);
    input [31:0] x;
    input en;
    output reg [4:0] y;
    integer i;
    always @ (x or en)
        begin
            if (en)
                begin
                    y = 0;
                    for (i = 0; i<= 31; i = i + 1)
                        if(x [i] == 1)
                            y = i[4:0];
                end
                else
                    y = 0;
        end
endmodule
