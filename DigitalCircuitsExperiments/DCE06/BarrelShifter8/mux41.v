module mux41(datain0, datain1, datain2, datain3, sel0, sel1, dataout);
    input datain0, datain1, datain2, datain3;
    input sel0, sel1;
    output reg dataout;

    always @(sel0 , sel1) 
    begin
        case (sel1)
        0 : case (sel0)
            0 : dataout = datain0;
            1 : dataout = datain1;
            endcase
        1 : case (sel0)
            0 : dataout = datain2;
            1 : dataout = datain3;
            endcase
        endcase
    end

endmodule
