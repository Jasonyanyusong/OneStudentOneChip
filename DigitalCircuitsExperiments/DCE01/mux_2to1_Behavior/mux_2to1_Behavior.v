module mux_2to1_Behavior (a, b, s, y);
    input a, b, s;
    output reg y;

    always @(*) begin
        if (s==0)
        begin
            y = a;
        end
        else
        begin
            y = b;
        end
    end
endmodule
