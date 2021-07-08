# +--------------------+
# |                    |
# |   GENERAL CONFIG   |
# |                    |
# +--------------------+

PROBLEM_NAME := *.cpp
DEBUG := true
LANG := cpp

CXX := g++
CXXFLAGS := -std=c++20 -O2 -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wshift-overflow -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion
DEBUG_CXXFLAGS := -fsanitize=address -fsanitize=undefined -fsanitize=float-divide-by-zero -fsanitize=float-cast-overflow -fno-sanitize-recover=all -fstack-protector-all 
DEBUG_CXXFLAGS += -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC
REMOVE := rm a.out

PRECOMPILE_HEADERS := bits/stdc++.h
#PRECOMPILE_HEADERS := bits/extc++.h

ifeq ($(LANG),cpp)
TARGET := $(PROBLEM_NAME)
EXECUTE := ./TEST
CLEAN_TARGETS := $(TARGET)
else ifeq ($(LANG),python)
TARGET := $(PROBLEM_NAME).py
EXECUTE := python3 ./$(TARGET)
CLEAN_TARGETS :=
else
$(error "Unknown language; please set TARGET, EXECUTE, and CLEAN_TARGETS manually")
endif

# +-------------------+
# |                   |
# |   GENERAL RULES   |
# |                   |
# +-------------------+

all: $(TARGET)
.PHONY: all

clean:
	-rm -rf $(CLEAN_TARGETS)
.PHONY: clean

veryclean:
	-rm -rf $(CLEAN_TARGETS) *.res
.PHONY: veryclean

rebuild: clean all
.PHONY: rebuild

# +---------------------+
# |                     |
# |   C++ COMPILATION   |
# |                     |
# +---------------------+

ifeq ($(DEBUG),true)
CXXFLAGS += $(DEBUG_CXXFLAGS)
endif

PCH := .precompiled_headers
CLEAN_TARGETS += $(PCH)

$(PCH)/%.gch:
	rm -f $@
	mkdir -p $(dir $@)
	$(LINK.cpp) -x c++-header "$$(echo '#include<$*>' | $(LINK.cpp) -H -E -x c++ - 2>&1 >/dev/null | head -1 | cut -d ' ' -f2)" -o $@
.PRECIOUS: $(PCH)/%.gch

%: %.cpp # Cancel the builtin rule

%: %.cpp $(patsubst %,$(PCH)/%.gch,$(PRECOMPILE_HEADERS))
	$(LINK.cpp) -isystem $(PCH) $< $(LOADLIBES) $(LDLIBS) -o $@
.PRECIOUS: %


# +-----------------------+
# |                       |
# |   RUNNING / TESTING   |
# |                       |
# +-----------------------+

export TIME=\n  real\t%es\n  user\t%Us\n  sys\t%Ss\n  mem\t%MKB

build: $(TARGET)
	$(CXX) $(CXXFLAGS) $(TARGET) -o $(EXECUTE)
ifeq ($(DEBUG),true)
	@echo "Built with DEBUG flags enabled, code may be slower than normal"
endif
.PHONY: build

run: $(TARGET)
	$(CXX) $(CXXFLAGS) $(TARGET) -o $(EXECUTE)
	\time $(EXECUTE)
ifeq ($(DEBUG),true)
	@echo "Built with DEBUG flags enabled, code may be slower than normal"
endif
.PHONY: run

%.res: $(TARGET) %.in
	@echo ""
	\time $(EXECUTE) < $*.in > $*.res
ifeq ($(DEBUG),true)
	@echo "Built with DEBUG flags enabled, code may be slower than normal"
endif
.PRECIOUS: %.res

%.out: % # Cancel the builtin rule

__test_%: %.res %.out
	@echo ""
	cat $*.in
	cat $*.res
	cat $*.out
	diff $*.res $*.out
.PHONY: __test_%

CASES := $(sort $(basename $(wildcard *.in)))
TESTS := $(sort $(basename $(wildcard *.out)))

runs: $(patsubst %,%.res,$(CASES))
.PHONY: run

solve: runs
.PHONY: solve

check: $(patsubst %,__test_%,$(TESTS)) 
.PHONY: check

test: build check
.PHONY: test
