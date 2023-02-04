module BarrelShifter_8Bit(din, shamt, lr, al, dout);
    input [7:0] din;
    input [2:0] shamt;
    input lr, al;
    output [7:0] dout;

    wire mc_out, m7a_out, m6a_out, m5a_out, m4a_out, m3a_out, m2a_out, m1a_out, m0a_out;
    wire m7b_out, m6b_out, m5b_out, m4b_out, m3b_out, m2b_out, m1b_out, m0b_out;

    mux21 mc(.datain1(din[7]), .datain0(0), .sel(al), .dataout(mc_out));
    mux41 m7a(.datain0(din[7]), .datain1(mc_out), .datain2(din[7]), .datain3(din[6]), .dataout(m7a_out), .sel0(shamt[0]), .sel1(lr));
    mux41 m6a(.datain0(din[6]), .datain1(din[7]), .datain2(din[6]), .datain3(din[5]), .dataout(m6a_out), .sel0(shamt[0]), .sel1(lr));
    mux41 m5a(.datain0(din[5]), .datain1(din[6]), .datain2(din[5]), .datain3(din[4]), .dataout(m5a_out), .sel0(shamt[0]), .sel1(lr));
    mux41 m4a(.datain0(din[4]), .datain1(din[5]), .datain2(din[4]), .datain3(din[3]), .dataout(m4a_out), .sel0(shamt[0]), .sel1(lr));
    mux41 m3a(.datain0(din[3]), .datain1(din[4]), .datain2(din[3]), .datain3(din[2]), .dataout(m3a_out), .sel0(shamt[0]), .sel1(lr));
    mux41 m2a(.datain0(din[2]), .datain1(din[3]), .datain2(din[2]), .datain3(din[1]), .dataout(m2a_out), .sel0(shamt[0]), .sel1(lr));
    mux41 m1a(.datain0(din[1]), .datain1(din[2]), .datain2(din[1]), .datain3(din[0]), .dataout(m1a_out), .sel0(shamt[0]), .sel1(lr));
    mux41 m0a(.datain0(din[0]), .datain1(din[1]), .datain2(din[0]), .datain3(0), .dataout(m0a_out), .sel0(shamt[0]), .sel1(lr));

    mux41 m7b(.datain0(m7a_out), .datain1(mc_out), .datain2(m7a_out), .datain3(m5a_out), .dataout(m7b_out), .sel0(shamt[1]), .sel1(lr));
    mux41 m6b(.datain0(m6a_out), .datain1(mc_out), .datain2(m6a_out), .datain3(m4a_out), .dataout(m6b_out), .sel0(shamt[1]), .sel1(lr));
    mux41 m5b(.datain0(m5a_out), .datain1(m7a_out), .datain2(m5a_out), .datain3(m3a_out), .dataout(m5b_out), .sel0(shamt[1]), .sel1(lr));
    mux41 m4b(.datain0(m4a_out), .datain1(m6a_out), .datain2(m4a_out), .datain3(m2a_out), .dataout(m4b_out), .sel0(shamt[1]), .sel1(lr));
    mux41 m3b(.datain0(m3a_out), .datain1(m5a_out), .datain2(m3a_out), .datain3(m1a_out), .dataout(m3b_out), .sel0(shamt[1]), .sel1(lr));
    mux41 m2b(.datain0(m2a_out), .datain1(m4a_out), .datain2(m2a_out), .datain3(m0a_out), .dataout(m2b_out), .sel0(shamt[1]), .sel1(lr));
    mux41 m1b(.datain0(m1a_out), .datain1(m3a_out), .datain2(m1a_out), .datain3(0), .dataout(m1b_out), .sel0(shamt[1]), .sel1(lr));
    mux41 m0b(.datain0(m0a_out), .datain1(m2a_out), .datain2(m0a_out), .datain3(0), .dataout(m0b_out), .sel0(shamt[1]), .sel1(lr));

    mux41 m7c(.datain0(m7b_out), .datain1(mc_out), .datain2(m7b_out), .datain3(m7b_out), .dataout(dout[7]), .sel0(shamt[2]), .sel1(lr));
    mux41 m6c(.datain0(m6b_out), .datain1(mc_out), .datain2(m6b_out), .datain3(0), .dataout(dout[6]), .sel0(shamt[2]), .sel1(lr));
    mux41 m5c(.datain0(m5b_out), .datain1(mc_out), .datain2(m5b_out), .datain3(m1b_out), .dataout(dout[5]), .sel0(shamt[2]), .sel1(lr));
    mux41 m4c(.datain0(m4b_out), .datain1(mc_out), .datain2(m4b_out), .datain3(m0b_out), .dataout(dout[4]), .sel0(shamt[2]), .sel1(lr));
    mux41 m3c(.datain0(m3b_out), .datain1(m7b_out), .datain2(m3b_out), .datain3(0), .dataout(dout[3]), .sel0(shamt[2]), .sel1(lr));
    mux41 m2c(.datain0(m2b_out), .datain1(m6b_out), .datain2(m2b_out), .datain3(0), .dataout(dout[2]), .sel0(shamt[2]), .sel1(lr));
    mux41 m1c(.datain0(m1b_out), .datain1(m5b_out), .datain2(m1b_out), .datain3(0), .dataout(dout[1]), .sel0(shamt[2]), .sel1(lr));
    mux41 m0c(.datain0(m0b_out), .datain1(m4b_out), .datain2(m0b_out), .datain3(0), .dataout(dout[0]), .sel0(shamt[2]), .sel1(lr));

endmodule