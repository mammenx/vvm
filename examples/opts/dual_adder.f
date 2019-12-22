-cc
--trace
-v
${EXAMPLES_ROOT}/dut/simple_adder.v
${EXAMPLES_ROOT}/dut/dual_adder.v
-CFLAGS '-fmax-errors=2'
-CFLAGS '-std=c++11'
-CFLAGS '-pthread'
-CFLAGS '-I${ROOT}'
-CFLAGS '-I${ROOT}/tools/spdlog/include'
-LDFLAGS '-std=c++11'
-LDFLAGS '-pthread'
--exe ${EXAMPLES_ROOT}/tb/dual_adder_tb.cpp
