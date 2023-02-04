module MultiShifter_4Bit(clk, sel, inp, outp);
    input clk;
    input [2:0] sel;
    input [3:0] inp;
    output reg [3:0] outp;

    always @(posedge clk)
    begin
        case(sel)
        3'b000:
        begin
            // Set to zerp
            outp <= 4'b0000;
        end
        3'b001:
        begin
            // Assign Value
            outp <= inp;
        end
        3'b010:
        begin
            // Logic Right
            outp <= {1'b0, outp[3:1]};
        end
        3'b011:
        begin
            // Logic Left
            outp <= {outp[2:0], 1'b0};
        end
        3'b100:
        begin
            // Arithmetic Right
            outp <= {outp[3], outp[3:1]};
        end
        3'b101:
        begin
            // Arithmetic Left
            outp <= {outp[3], outp[1:0], 1'b0};
        end
        3'b110:
        begin
            // Cyclic Right
            outp <= {outp[0], outp[3:1]};
        end
        3'b111:
        begin
            // Cyclic Left
            outp <= {outp[2:0], outp[3]};
        end
        endcase
    end
endmodule
