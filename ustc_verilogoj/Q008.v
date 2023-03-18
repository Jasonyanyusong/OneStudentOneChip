//创建一个Verilog模块，实现同或门的逻辑功能，对于两输入同或门来说，输入相同时输出1，输入不同时输出0，正好与异或门相反，如下图所示
module top_module( 
    input a, 
    input b, 
    output out );
// 请用户在下方编辑代码
    assign out = a == b;
	
//用户编辑到此为止
endmodule