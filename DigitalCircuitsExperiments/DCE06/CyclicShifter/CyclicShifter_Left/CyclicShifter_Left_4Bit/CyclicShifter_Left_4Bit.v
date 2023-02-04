module CyclicShifter_Left_4Bit(clk, clr, inp, outp, load);
    input clk, clr, load;
    input [3:0] inp;
    output reg [3:0] outp;

    always @(posedge clk)
    begin
        if(load)
            outp <= inp;
        else if (clr)
            outp <= 4'b0000;
        else
            outp <= {outp[2:0], outp[3]};  
    end
endmodule
