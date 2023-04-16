# Most-Simple-Processor-Core (MSPC)
Here I construct a Most-Simple-Processor-Core (MSPC), Which will contain the following components.
* MSPC_PC: Program Counter
* MSPC_IntReg: Integer Registers
* MSPC_ALU: Arthmetic Logic Unit
* MSPC_LSU: Load Store Unit
* MSPC_Mem: Memory (Big-Array) (This part will not be implemented by RTL since we get instruction from C++ simulation file)

And Units for execution
* MSPC_IFU: Instruction Fetch Unit
* MSPC_IDU: Instruction Decode Unit
* MSPC_EXU: EXecution Unit

Macro
* MSPC: The Macro RTL file, will implement these sub_modules