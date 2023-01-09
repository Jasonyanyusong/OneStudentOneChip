module mux21(datain, sel, dataout);
    input [1:0] datain;
    input sel;
    output reg dataout;

    always @(sel) 
    begin
        case (sel)
        0 : dataout = datain [0];
        1 : dataout = datain [1];
        endcase
    end
endmodule
