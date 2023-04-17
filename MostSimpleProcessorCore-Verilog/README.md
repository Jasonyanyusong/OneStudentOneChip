In MSPC_V_ALU, We will have 5 ports, 3 input and 2 outputs, they are:
* inpa: The first input number, send to ALU directly
* inpb: The second input number, send to ALU directly
* sel: A 4 bits function selection port, can select what to do (Have no realtionships with RISCV Instructions)
* booloutp: A 1 bit bool output port, will be used in compare
* numoutp: A XLEN bit output port, will send the result of computing

* Specifically, the Operate Code and its operation will be list below, they are:
|Operate Code|Type|Function|Status|
|----|----|----|----|
|0000|Compute|Doing|DOING|
|0001|Compute|Doing|DOING|
|0010|Compute|Doing|DOING|
|0011|Compute|Doing|DOING|
|0100|Compute|Doing|DOING|
|0101|Compute|Doing|DOING|
|0110|Compute|Doing|DOING|
|0111|Compute|Doing|DOING|
|1000|Shifter|Doing|DOING|
|1001|Shifter|Doing|DOING|
|1010|Shifter|Doing|DOING|
|1011|Shifter|Doing|DOING|
|1100|Shifter|Doing|DOING|
|1101|Shifter|Doing|DOING|
|1110|Shifter|Doing|DOING|
|1111|Shifter|Doing|DOING|


More Readme informations will be available in later commits