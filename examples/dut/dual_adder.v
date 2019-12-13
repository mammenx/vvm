module  dual_adder  #(
  parameter WIDTH0 = 1
 ,parameter WIDTH1 = 1

) (

   input  wire                clk0
  ,input  wire                rst0_n

  ,input  wire                din0_valid
  ,input  wire  [WIDTH0-1:0]  din0

  ,output wire                dout0_valid
  ,output wire  [WIDTH0-1:0]  dout0

  ,input  wire                clk1
  ,input  wire                rst1_n

  ,input  wire                din1_valid
  ,input  wire  [WIDTH1-1:0]  din1

  ,output wire                dout1_valid
  ,output wire  [WIDTH1-1:0]  dout1

);

  simple_adder  #(
    .WIDTH  (WIDTH0)

  ) u_simple_adder_0  (

     .clk           (clk0          )
    ,.rst_n         (rst0_n        )
                                   
    ,.din_valid     (din0_valid    )
    ,.din           (din0          )
                                   
    ,.dout_valid    (dout0_valid   )
    ,.dout          (dout0         )

  );


  simple_adder  #(
    .WIDTH  (WIDTH1)

  ) u_simple_adder_1  (

     .clk           (clk1          )
    ,.rst_n         (rst1_n        )
                                   
    ,.din_valid     (din1_valid    )
    ,.din           (din1          )
                                   
    ,.dout_valid    (dout1_valid   )
    ,.dout          (dout1         )

  );



endmodule //dual_adder

