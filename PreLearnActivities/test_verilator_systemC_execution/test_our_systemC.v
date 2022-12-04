module test_our_systemC (clk);
    input clk;
    always @(posedge clk) begin
        $display("Hello World");
        $finish;
    end
endmodule
