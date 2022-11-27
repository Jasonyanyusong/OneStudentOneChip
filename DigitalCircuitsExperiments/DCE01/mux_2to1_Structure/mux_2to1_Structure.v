module mux_2to1_Structure(a, b, s, y);
    input a, b, s;
    output y;
    wire l, r, s_n;
    my_not i1(.a(s), .b(s_n));
    my_and i2 (.a(s_n), .b(a), .c(l));
    my_and i3 (.a(s), .b(b), .c(r));
    my_or i4 (.a(l), .b(r), .c(y));
endmodule
