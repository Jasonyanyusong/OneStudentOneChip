module register1(load, clk, clr, inp, q);
	input load, clr, clk, inp;
	output reg q;

	always @(posedge clk)
		if (clr == 1)
			q <= 0;
		else if (load == 1)
			q <= inp;
endmodule

