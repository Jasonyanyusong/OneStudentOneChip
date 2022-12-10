module add_1bit_case (c_i, a_i, b_i, s_i, c_iplus1);
    input c_i, a_i, b_i;
    output reg s_i, c_iplus1;

    always @( * ) 
    begin
        case (c_i)
        0 : begin
            case (a_i)
            0 : begin
                case(b_i)
                0 : begin
                    s_i = 0;
                    c_iplus1 = 0;
                end
                1 : begin
                    s_i = 1;
                    c_iplus1 = 0;
                end
                endcase
            end
            1 : begin
                case(b_i)
                0 : begin
                    s_i = 1;
                    c_iplus1 = 0;
                end
                1 : begin
                    s_i = 0;
                    c_iplus1 = 1;
                end
                endcase
            end
            endcase
        end
        1 : begin
            case (a_i)
            0 : begin
                case(b_i)
                0 : begin
                    s_i = 1;
                    c_iplus1 = 0;
                end
                1 : begin
                    s_i = 0;
                    c_iplus1 = 1;
                end
                endcase
            end
            1 : begin
                case(b_i)
                0 : begin
                    s_i = 0;
                    c_iplus1 = 1;
                end
                1 : begin
                    s_i = 1;
                    c_iplus1 = 1;
                end
                endcase
            end
            endcase
        end
        endcase
    end

endmodule
