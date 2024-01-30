MAIN := main
SRCFILES := $(shell find . -type f -name "*.cpp")
OBJFILES := $(patsubst %.cpp, %.o, $(SRCFILES))
COMPILE_FLAGS_FILE := compile_flags.txt

.PHONY: all clean

all: $(MAIN)

clean:
	-@$(RM) $(wildcard $(OBJFILES) $(MAIN))

$(MAIN): $(OBJFILES)
	@$(CXX) @$(COMPILE_FLAGS_FILE) $^ -o $(MAIN)

%.o: %.cpp Makefile
	@$(CXX) @$(COMPILE_FLAGS_FILE) -c $< -o $@
