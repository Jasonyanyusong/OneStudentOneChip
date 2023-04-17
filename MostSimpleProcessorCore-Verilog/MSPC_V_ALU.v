module MSPC_V_ALU(inpa, inpb, sel, booloutp, numoutp);
    input [63:0] inpa, inpb;
    input [3:0] sel;
    output reg [63:0] numoutp;
    output reg booloutp;

    always @(sel)
    begin
    case(sel)
        4'b0000:
        begin
            // Function: Add
            numoutp = inpa + inpb;
        end

        4'b0001:
        begin
            // Function: Minus
            numoutp = inpa - inpb;
        end

        4'b0010:
        begin
            // Function: Not
            numoutp = ~inpa;
        end

        4'b0011:
        begin
            // Function: And
            numoutp = inpa & inpb;
        end

        4'b0100:
        begin
            // Function: OR
            numoutp = inpa | inpb;
        end

        4'b0101:
        begin
            // Function: XOR
            numoutp = inpa ^ inpb;
        end

        4'b0110:
        begin
            // Function: BLT (Be Less Than)
            booloutp = inpa < inpb;
        end

        4'b0111:
        begin
            // Function: BEQ (Be EQuale)
            booloutp = inpa == inpb;
        end

        4'b1000:
        begin
            // No Operate
        end

        4'b1001:
        begin
            // No Operate
        end

        4'b1010:
        begin
            // Function: SRL (Shift Right Logic)
            booloutp = inpa >> inpb;
        end

        4'b1011:
        begin
            // Function: SLL (Shift Left Logic)
            booloutp = inpa << inpb;
        end

        4'b1100:
        begin
            // Function: SRA (Shift Right Arthmetic)
            booloutp = signed'(inpa) >> inpb;
        end

        4'b1101:
        begin
            // No Operate
        end

        4'b1110:
        begin
            // No Operate
        end

        4'b1111:
        begin
            // No Operate
        end

        default:
        begin
            booloutp = 1'b0;
            numoutp = 64'h0000000000000000;
        end
    endcase
    end
endmodule