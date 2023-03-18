//wire 是 Verilog 的关键字，用于表征信号类型的，其含义是线网。wire 可理解为物理连线，但又有所不同，因为 Verilog 中的 wire 是有方向的。例如设计一模块，模块名命名为 top_module，输入信号名为 in，输出信号名为 out，使 in 与 out 直连，如下图所示：
//请使用 assign 语句将代码补充完整，使其实现上述电路图的功能。
module top_module(
  input in, output out
);
  // Write your code here
    assign out = in;
endmodule