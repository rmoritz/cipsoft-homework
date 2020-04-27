# Paths
SRCDIR := src
OBJDIR := build
INCDIR := include
PROGRAM := solver
SRC := $(wildcard $(SRCDIR)/*.cc)
PRG := $(OBJDIR)/$(PROGRAM)

# Commands
CC := clang++
DOXY := $(shell which doxygen)
RM := rm -rf
MKDIR := mkdir -p

# Flags
CFLAGS := -Iinclude -O3 -Wall -Wpedantic
LDFLAGS := 

# Targets
.PHONY: all prg clean

all: docs prg

prg: $(PRG)

docs: | $(OBJDIR)
ifneq ($(strip $(DOXY)),)
	$(DOXY)
endif

$(PRG): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(SRC): | $(OBJDIR)

$(OBJDIR):
	$(MKDIR) $(OBJDIR)

clean:
	$(RM) $(OBJDIR) 
