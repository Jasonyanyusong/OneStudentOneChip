module mux21(datain0, datain1, sel, dataout);
    input datain0, datain1;
    input sel;
    output reg dataout;

    always @(sel) 
    begin
        case (sel)
        0 : dataout = datain0;
        1 : dataout = datain1;
        endcase
    end
endmodule
