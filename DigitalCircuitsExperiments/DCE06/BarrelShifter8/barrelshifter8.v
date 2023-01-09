module barrelshifter8(din, shamt, lr, al, dout);
    input [7:0] din;
    input [2:0] shamt;
    input lr, al;
    output dout;

    wire mc_out, m7a_out;
    mux_c mc(.datain1(din[7]), .datain0(0), .sel(al), .dataout(mc_out));
    //mux_7a m7a(.datain[0](din[7]))

endmodule