module register32(load, clk, clr, inp, q);
	input load, clr, clk;
    input [32-1 : 0] inp;
	output reg [32-1 : 0] q;

	always @(posedge clk)
		if (clr == 1)
			q <= 0;
		else if (load == 1)
			q <= inp;
endmodule
