module  simple_adder  #(
  parameter WIDTH = 1
) (
   input  wire              clk
  ,input  wire              rst_n

  ,input  wire              din_valid
  ,input  wire  [WIDTH-1:0] din

  ,output reg               dout_valid
  ,output reg   [WIDTH-1:0] dout

);

  always@(posedge clk,  negedge rst_n)
  begin
    if(~rst_n)
    begin
      dout_valid    <=  1'b0;
      dout          <=  {WIDTH{1'b0}};
    end
    else
    begin
      dout_valid    <=  din_valid;
      dout          <=  din;
    end
  end

endmodule //simple_adder
