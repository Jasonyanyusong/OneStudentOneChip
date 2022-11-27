module one_and (a, b, c);
    input a, b;
    output c;
    assign c = a & b;
endmodule

module two_or (a, b, c);
    input a, b;
    output c;
    assign c = a | b;
endmodule

module three_not (a, b);
    input a;
    output b;
    assign b = ~a;
endmodule

module mux_2to1_Structure(a, b, s, y);
    input a, b, s;
    output y;
    wire l, r, s_n;
    three_not i1(.a(s), .b(s_n));
    one_and i2 (.a(s_n), .b(a), .c(a));
    one_and i3 (.a(s), .b(b), .c(r));
    two_or i4 (.a(l), .b(r), .c(y));
endmodule
