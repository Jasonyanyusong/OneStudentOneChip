module mux_1b(datain, sel, dataout);
    input [3:0] datain;
    input [1:0] sel;
    output reg dataout;

    always @(sel) 
    begin
        case (sel)
        0 : dataout = datain [0];
        1 : dataout = datain [1];
        2 : dataout = datain [2];
        3 : dataout = datain [3];
        endcase
    end
endmodule
