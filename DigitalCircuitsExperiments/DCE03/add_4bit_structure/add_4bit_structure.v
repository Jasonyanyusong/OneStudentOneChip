module add_4bit_structure (a_0, b_0, c_in, s_0, a_1, b_1, c_1, s_1, a_2, b_2, c_2, s_2, a_3, b_3, c_3, s_3, c_out);
    input a_0, b_0, c_in;
    input a_1, b_1, c_1;
    input a_2, b_2, c_2;
    input a_3, b_3, c_3;

    output s_0, s_1, s_2, s_3, c_out;

    wire add0_1, add1_2, add2_3;

    my_add1bit add0(.c_i(c_in), .a_i(a_0), .b_i(b_0), .s_i(s_0), .c_iplus1(add0_1));
    my_add1bit add1(.c_i(add0_1), .a_i(a_1), .b_i(b_1), .s_i(s_1), .c_iplus1(add1_2));
    my_add1bit add2(.c_i(add1_2), .a_i(a_2), .b_i(b_2), .s_i(s_2), .c_iplus1(add2_3));
    my_add1bit add3(.c_i(add2_3), .a_i(a_3), .b_i(b_3), .s_i(s_3), .c_iplus1(c_out));

endmodule
