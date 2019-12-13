-cc
--trace
${EXAMPLES_ROOT}/dut/simple_adder.v
-CFLAGS '-I${ROOT}'
--exe ${EXAMPLES_ROOT}/tb/simple_adder_tb.cpp
