package test
import chisel3._
import chisel3.experimental._

/*
The Operate Code has 4 digits.
The highest digit is used for distinguishing Computing(0) / Shifting(1).
The last 3 digits are used for specifing what should the ALU do.
*/

/*
For Computing part of ALU, we set the OperateCode as:
    000, Add, A + B
    001, Sub, A - B
    010, Not, ~ A
    011, And, A & B
    100, Or,  A | B
    101, Xor, A ^ B
    110, Cmp, A < B
    111, Beq, A ==B
*/

/*
For Shifting part of ALU, we set the OperateCode as:
    000, Preserved
    001, Preserved
    010, Shift Right Logic
    011, Shift Left Logic
    100, Shift Right Arithmetic
    101, Preserved
    110, Shift Right Cycle
    111, Shift Left Cycle
*/

class ALU extends Module{
    val io = IO(new Bundle{
        val DataInA = Input(UInt(64.W))
        val DataInB = Input(UInt(64.W))
        val OperateCode = Input(UInt(4.W))
        val ComputeResult = Output(UInt(64.W))
        val CompareResult = Output(Bool(1.W))
    }) // Define ALU's IO

    io.ComputeResult := Mux(
        OperateCode(3),
        Mux(
            OperateCode(2),
            Mux(
                OperateCode(1),
                Mux(
                    OperateCode(0),
                    // 1111 TODO
                    ,
                    // 1110 TODO
                ),
                Mux(
                    OperateCode(0),
                    // 1101 TODO
                    ,
                    // 1100 TODO
                )
            ),
            Mux(
                OperateCode(1),
                Mux(
                    OperateCode(0),
                    // 1011 TODO
                    ,
                    // 1010 TODO
                ),
                Mux(
                    OperateCode(0),
                    // 1001 TODO
                    ,
                    // 1000 TODO
                )
            )
        ),
        Mux(
            OperateCode(2),
            Mux(
                OperateCode(1),
                Mux(
                    OperateCode(0),
                    // 0111 TODO
                    ,
                    // 0110 TODO
                ),
                Mux(
                    OperateCode(0),
                    // 0101 TODO
                    ,
                    // 0100 TODO
                )
            ),
            Mux(
                OperateCode(1),
                Mux(
                    OperateCode(0),
                    // 0011 TODO
                    ,
                    // 0010 TODO
                ),
                Mux(
                    OperateCode(0),
                    // 0001 TODO
                    ,
                    // 0000 TODO
                )
            )
        )
    )

    io.CompareResult := Mux()
}