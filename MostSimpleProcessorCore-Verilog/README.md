In MSPC_V_ALU, We will have 5 ports, 3 input and 2 outputs, they are:
* inpa: The first input number, send to ALU directly
* inpb: The second input number, send to ALU directly
* sel: A 4 bits function selection port, can select what to do (Have no realtionships with RISCV Instructions)
* booloutp: A 1 bit bool output port, will be used in compare
* numoutp: A XLEN bit output port, will send the result of computing

* Specifically, the Operate Code and its operation will be list below, they are:
|Operate Code|Type|Function|
|----|----|----|
|0000|Compute|TODO|
|0001|Compute|TODO|
|0010|Compute|TODO|
|0011|Compute|TODO|
|0100|Compute|TODO|
|0101|Compute|TODO|
|0110|Compute|TODO|
|0111|Compute|TODO|
|1000|Shifter|TODO|
|1001|Shifter|TODO|
|1010|Shifter|TODO|
|1011|Shifter|TODO|
|1100|Shifter|TODO|
|1101|Shifter|TODO|
|1110|Shifter|TODO|
|1111|Shifter|TODO|


More Readme informations will be available in later commits