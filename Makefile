define Documentation

endef

-include colors.mk

CC = g++

# Folders
SRCDIR := src
BUILDDIR := build
TARGETDIR := bin

# Targets
EXECUTABLE := Sorting
TARGET := $(TARGETDIR)/$(EXECUTABLE)

# Final Paths
INSTALLBINDIR := /usr/local/bin

# Code Lists
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

# Folder Lists
INCDIRS := $(shell find src/**/* -name '*.h' -exec dirname {} \; | sort | uniq)
INCLIST := $(patsubst src/%,-I src/%,$(INCDIRS))
BUILDLIST := $(patsubst src/%,$(BUILDDIR)/%,$(INCDIRS))

# Shared Compiler Flags
CFLAGS := -g -std=c++11 -w -O3
INC := -I include $(INCLIST) -I /usr/local/include

$(TARGET): $(OBJECTS)
	@mkdir -p $(TARGETDIR)
	@echo  "${P}Linking all targets...${N}"
	@$(CC) $^ -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDLIST)
	@echo "${Y}Compiling${N} ${B}$< ${N}"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

test:
	@echo "${B}Testing with 10 elements${N}"
	@./bin/Sorting ./samples/input1.txt A
	@echo "${B}Testing with 100 elements${N}"
	@./bin/Sorting ./samples/input2.txt A
	@echo "${B}Testing with 1000 elements${N}"
	@./bin/Sorting ./samples/input3.txt A
	@echo "${B}Testing with 10000 elements${N}"
	@./bin/Sorting ./samples/input4.txt A
	@echo "${B}Testing with 100000 elements${N}"
	@./bin/Sorting ./samples/input5.txt A

cleantest:
	@echo "${R}Removing test results ${N}"; rm ./samples/*.out

clean:
	@echo "${R}Cleaning $(TARGET)${N}"; $(RM) -r $(BUILDDIR) $(TARGETDIR)

install:
	@echo "${R}Installing ${N} ${B} $(EXECUTABLE) ${N}"; cp $(TARGET) $(INSTALLBINDIR)

distclean:
	@echo "${R}Removing ${N} ${B} $(EXECUTABLE) ${N}"; rm $(INSTALLBINDIR)/$(EXECUTABLE)

.PHONY: clean
