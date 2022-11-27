module my_and (a, b, c);
    input a, b;
    output c;
    assign c = a & b;
endmodule

module my_or (a, b, c);
    input a, b;
    output c;
    assign c = a | b;
endmodule

module my_not (a, b);
    input a;
    output b;
    assign b = ~a;
endmodule

module mux_2to1_Structure(a, b, s, y);
    input a, b, s;
    output y;
    wire l, r, s_n;
    my_not i1(.a(s), .b(s_n));
    my_and i2 (.a(s_n), .b(a), .c(a));
    ny_and i3 (.a(s), .b(b), .c(r));
    my_or i4 (.a(l), .b(r), .c(y));
endmodule
