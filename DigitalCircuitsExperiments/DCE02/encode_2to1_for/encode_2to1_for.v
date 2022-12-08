module encode_2to1_for(x, en, y);
    input [1:0] x;
    input en;
    output reg [0:0] y;
    integer i;
    always @ (x or en)
        begin
            if (en)
                begin
                    y = 0;
                    for (i = 0; i<= 1; i = i + 1)
                        if(x [i] == 1)
                            y = i[0:0];
                end
                else
                    y = 0;
        end
endmodule
