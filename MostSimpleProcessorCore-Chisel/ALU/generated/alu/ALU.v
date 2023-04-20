module ALU(
  input         clock,
  input         reset,
  input  [63:0] io_DataInA,
  input  [63:0] io_DataInB,
  input  [3:0]  io_OperateCode,
  output [63:0] io_ALUResult
);
  wire [63:0] _io_ALUResult_T_3 = io_DataInA + io_DataInB; // @[ALU.scala 13:50]
  wire [3:0] _io_ALUResult_T_4 = {{1'd0}, io_OperateCode[3:1]}; // @[ALU.scala 14:23]
  wire [63:0] _io_ALUResult_T_7 = io_DataInA - io_DataInB; // @[ALU.scala 14:50]
  wire [3:0] _io_ALUResult_T_8 = {{2'd0}, io_OperateCode[3:2]}; // @[ALU.scala 15:23]
  wire [63:0] _io_ALUResult_T_10 = ~io_DataInA; // @[ALU.scala 15:39]
  wire [3:0] _io_ALUResult_T_11 = {{3'd0}, io_OperateCode[3]}; // @[ALU.scala 16:23]
  wire [63:0] _io_ALUResult_T_13 = io_DataInA & io_DataInB; // @[ALU.scala 16:50]
  wire [126:0] _io_ALUResult_T_55 = {{63'd0}, io_DataInB}; // @[Mux.scala 47:70]
  wire [126:0] _io_ALUResult_T_63 = _io_ALUResult_T_11[0] ? {{63'd0}, _io_ALUResult_T_13} : _io_ALUResult_T_55; // @[Mux.scala 47:70]
  wire [126:0] _io_ALUResult_T_64 = _io_ALUResult_T_8[0] ? {{63'd0}, _io_ALUResult_T_10} : _io_ALUResult_T_63; // @[Mux.scala 47:70]
  wire [126:0] _io_ALUResult_T_65 = _io_ALUResult_T_4[0] ? {{63'd0}, _io_ALUResult_T_7} : _io_ALUResult_T_64; // @[Mux.scala 47:70]
  wire [126:0] _io_ALUResult_T_66 = io_OperateCode[0] ? {{63'd0}, _io_ALUResult_T_3} : _io_ALUResult_T_65; // @[Mux.scala 47:70]
  assign io_ALUResult = _io_ALUResult_T_66[63:0]; // @[ALU.scala 12:18]
endmodule
