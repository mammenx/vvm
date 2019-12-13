`timescale 1ns/100ps

module  hello_world ();

  initial
  begin
    $display("Hello World");
    $finish;
  end

endmodule
