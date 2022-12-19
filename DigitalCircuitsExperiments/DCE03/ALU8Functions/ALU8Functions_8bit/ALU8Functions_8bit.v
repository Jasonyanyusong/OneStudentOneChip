module ALU8Functions_8bit (input_mode_select, input_a, input_b, output_result);
    input[2:0] input_mode_select;
    input[7:0] input_a, input_b;
    output reg[7:0] output_result;

    /* verilator lint_off WIDTH */
    always @(*)
    begin
        case(input_mode_select)
        3'b000 : assign output_result = input_a + input_b;
        3'b001 : assign output_result = input_a - input_b;
        3'b010 : assign output_result = !input_a;
        3'b011 : assign output_result = input_a & input_b;
        3'b100 : assign output_result = input_a | input_b;
        3'b101 : assign output_result = input_a ^ input_b;
        3'b110 : assign output_result = input_a < input_b;
        3'b111 : assign output_result = input_a == input_b;
        endcase
    end
    /* verilator lint_on WIDTH */

endmodule
