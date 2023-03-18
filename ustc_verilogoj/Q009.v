//之前的verilog模块结构都比较简单，输出信号可直接用输入信号的逻辑表达式表示出来，模块功能稍微复杂时，一般都会用到中间信号，以下图为例，输入信号in经过两个非门后输出到out端口，为了在verilog模块中表示两个非门中间的这跟信号，需要将其定义为线网型（wire）信号，此处我们命名为not_in。
//上述模块的verilog代码为：
//请根据上述示例，完成下图中电路所对应的Verilog模块
module top_module(
    input a,
    input b,
    input c,
    input d,
    output out,
    output out_n   
); 
// 请用户在下方编辑代码
    wire a_and_b, c_and_d, a_and_b_OR_c_and_d;
    assign a_and_b = a && b;
    assign c_and_d = c && d;
    assign a_and_b_OR_c_and_d = a_and_b || c_and_d;
    assign out = a_and_b_OR_c_and_d;
    assign out_n = ! a_and_b_OR_c_and_d;
//用户编辑到此为止
endmodule
