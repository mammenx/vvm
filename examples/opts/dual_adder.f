-cc
--trace
-v
${EXAMPLES_ROOT}/dut/simple_adder.v
${EXAMPLES_ROOT}/dut/dual_adder.v
-CFLAGS '-I${ROOT}'
--exe ${EXAMPLES_ROOT}/tb/dual_adder_tb.cpp
