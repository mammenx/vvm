DUT_TOP ?= dual_adder

RUN_DIR = ${EXAMPLES_ROOT}/run/${DUT_TOP}

ifneq ($(words $(CURDIR)),1)
 $(error Unsupported: GNU Make cannot build in directories containing spaces, build elsewhere: '$(CURDIR)')
endif
ifeq ($(VERILATOR_ROOT),)
VERILATOR = verilator
else
export VERILATOR_ROOT
VERILATOR = $(VERILATOR_ROOT)/bin/verilator
endif
ifeq ($(ROOT),)
	$(error ROOT is not defined!)
endif
ifeq ($(EXAMPLES_ROOT),)
	$(error EXAMPLES_ROOT is not defined!)
endif

default:
	@mkdir -p ${RUN_DIR}
	@cd ${RUN_DIR} && \
		echo "-- Verilator out example"; \
		echo "-- VERILATE ----------------"; \
		$(VERILATOR) -f ${EXAMPLES_ROOT}/opts/${DUT_TOP}.f; \
		echo "-- COMPILE -----------------"; \
		$(MAKE) -j 4 -C obj_dir -f V${DUT_TOP}.mk V${DUT_TOP}; \
		echo "-- RUN ---------------------"; \
		obj_dir/V${DUT_TOP} +trace; \
		echo "-- DONE --------------------"; \

######################################################################

maintainer-copy::
clean mostlyclean distclean maintainer-clean::
	-rm -rf ${RUN_DIR}
