module add_datastream_1(in_x, in_y, out_s);
    input [1:0] in_x, in_y;
    output [1:0] out_s;

    assign out_s = in_x + in_y;
endmodule
