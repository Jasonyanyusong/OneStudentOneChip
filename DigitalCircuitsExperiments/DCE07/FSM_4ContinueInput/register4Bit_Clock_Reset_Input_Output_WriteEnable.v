module register4Bit_Clock_Reset_Input_Output_WriteEnable (Module_clock, Module_reset, Module_input, Module_output, Module_write_enable);
    input Module_clock, Module_reset, Module_write_enable;
    input [3:0] Module_input;
    output reg [3:0] Module_output;

    always @(posedge Module_clock)
    begin
        if (Module_reset == 1)
            Module_output <= 4'b0;
        else if (Module_write_enable == 1)
            Module_output <= Module_input;    
    end
endmodule
