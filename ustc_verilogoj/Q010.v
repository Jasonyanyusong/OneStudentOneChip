/*
向量是为了编写、阅读代码方便，将一组相关的信号用一个向量名称统一命名的方式。例如：wire [7:0] w;
声明了一个8bit位宽的向量信号w，实际上代表的是8个1bit的wire型信号。
注意向量信号的声明是将位宽信息放在信号名之前，这与C语言不太一样。我们可以将向量信号中的一位或多位单独拿来使用。例如：
wire out;
wire [3:0] out_4;
wire [99:0] my_vector;
// 声明一个100bit的向量my_vector
assign out = my_vector[11] & my_vector[10];
// 选择其中两位信号进行运算
assign out_4 = my_vector[23:20];
// 选择其中4bit信号
任务目标：
创建一verilog模块，具有一个3bit位宽的输入向量信号，然后将其输出到3bit位宽的输出向量信号，同时再分别输出到3个1bit位宽的输出信号，如下图所示
*/
module top_module ( 
    input wire [2:0] vec,
    output wire [2:0] outv,
    output wire o2,
    output wire o1,
    output wire o0);
// Module body starts after module declaration
// 请用户在下方编辑代码
    assign outv = vec;
    assign o0 = vec[0:0];
    assign o1 = vec[1:1];
    assign o2 = vec[2:2];
// 用户编辑到此为止
endmodule