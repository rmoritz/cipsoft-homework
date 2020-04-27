# Paths
SRCDIR := src
OBJDIR := build
INCDIR := include
PROGRAM := solver
SRC := $(wildcard $(SRCDIR)/*.cc)
PRG := $(OBJDIR)/$(PROGRAM)

# Commands
CC := clang++
RM := rm -rf
MKDIR := mkdir -p

# Flags
CFLAGS := -Iinclude -O3 -Wall -Wpedantic
LDFLAGS := 

# Targets
.PHONY: all prg clean

all: prg
prg: $(PRG)

$(PRG): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(SRC): | $(OBJDIR) $(DSTDIR)

$(OBJDIR):
	$(MKDIR) $(OBJDIR)

clean:
	$(RM) $(OBJDIR) 
