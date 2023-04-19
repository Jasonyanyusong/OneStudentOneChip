# Most-Simple-Processor-Core (MSPC)
Here I construct a Most-Simple-Processor-Core (MSPC), Which will contain the following components.
* MSPC_ALU
* MSPC_LSU
* MSPC_IDU
* MSPC_IFU

# ALU Part:
The Operate Code has 4 digits.
The highest digit is used for distinguishing Computing(0) / Shifting(1).
The last 3 digits are used for specifing what should the ALU do.

For Computing part of ALU, we set the OperateCode as:
    0000, Add, A + B
    0001, Sub, A - B
    0010, Not, ~ A
    0011, And, A & B
    0100, Or,  A | B
    0101, Xor, A ^ B
    0110, Cmp, A < B
    0111, Beq, A===B

For Shifting part of ALU, we set the OperateCode as:
    1000, Preserved
    1001, Preserved
    1010, Shift Right Logic
    1011, Shift Left Logic
    1100, Shift Right Arithmetic
    1101, Preserved
    1110, Shift Right Cycle (Not Implemented Yet)
    1111, Shift Left Cycle (Not Implemented Yet)