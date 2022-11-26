module mux_2to1_Datastream (a, b, s, y);
    input a, b, s;
    output y;
    assign y = (~s & a) | (s & b);
endmodule