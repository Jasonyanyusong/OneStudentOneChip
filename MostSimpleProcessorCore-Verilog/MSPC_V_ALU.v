module MSPC_V_ALU(inpa, inpb, sel, booloutpm numoutp);
    input [63:0] inpa, inpb;
    input [3:0] sel;
    output [63:0] numoutp;
    output booloutp;

    case(sel)
        4'b0000:
        begin
            // TODO
        end

        4'b0001:
        begin
            // TODO
        end

        4'b0010:
        begin
            // TODO
        end

        4'b0011:
        begin
            // TODO
        end

        4'b0100:
        begin
            // TODO
        end

        4'b0101:
        begin
            // TODO
        end

        4'b0110:
        begin
            // TODO
        end

        4'b0111:
        begin
            // TODO
        end

        4'b1000:
        begin
            // TODO
        end

        4'b1001:
        begin
            // TODO
        end

        4'b1010:
        begin
            // TODO
        end

        4'b1011:
        begin
            // TODO
        end

        4'b1100:
        begin
            // TODO
        end

        4'b1101:
        begin
            // TODO
        end

        4'b1110:
        begin
            // TODO
        end

        4'b1111:
        begin
            // TODO
        end

        default:
        begin
            booloutp = 1'b0;
            numoutp = 64'x0000000000000000;
        end
    endcase
endmodule