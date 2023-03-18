//wire是Verilog的关键字，用于表征信号类型的，其含义是线网，wire可理解为物理连线，但又有所不同，因为verilog中的wire是有方向的，例如设计一模块，模块名命名为top_module，输入信号名为in，输出信号名为out，使in与out直连，如下图所示：
//请使用assign语句将代码补充完整，使其实现上述电路图的功能
module top_module( 
    input a,b,c,
    output w,x,y,z );
// 请用户在下方编辑代码
    assign w = a;
    assign x = b;
    assign y = b;
    assign z = c;

//用户编辑到此为止
endmodule
