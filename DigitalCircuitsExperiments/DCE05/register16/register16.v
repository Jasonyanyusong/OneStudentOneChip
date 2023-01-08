module register16(load, clk, clr, inp, q);
	input load, clr, clk;
    input [16-1 : 0] inp;
	output reg [16-1 : 0] q;

	always @(posedge clk)
		if (clr == 1)
			q <= 0;
		else if (load == 1)
			q <= inp;
endmodule
