# Paths
SRCDIR := ../src
TDIR := .
OBJDIR := ../build
INCDIR := ../include
PROGRAM := tests
SRC := $(wildcard $(TDIR)/*.cc) $(SRCDIR)/minmax.cc
PRG := $(OBJDIR)/$(PROGRAM)

# Commands
CC := clang++
RM := rm -f
MKDIR := mkdir -p

# Flags
CFLAGS := -I$(INCDIR) -Wall -Wpedantic
LDFLAGS :=

# Targets
.PHONY: all prg test clean

all: prg test

test: prg
	$(PRG)

prg: $(PRG)

$(PRG): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(SRC): | $(OBJDIR)

$(OBJDIR):
	$(MKDIR) $(OBJDIR)

clean:
	$(RM) $(PRG)
