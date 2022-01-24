CC      = g++
LEX     = flex
YACC    = bison
CFLAGS  = -Wall -std=c++11
LIBS    = -lfl -ly
INCLUDE = -Iinclude

SCANNER = scanner
PARSER  = parser

ASTDIR = src/AST/
AST := $(shell find $(ASTDIR) -name '*.cpp')

VISITORDIR = src/visitor/
VISITOR := $(shell find $(VISITORDIR) -name '*.cpp')

SRC := $(AST) \
       $(VISITOR)

EXEC = $(PARSER)
OBJS = $(PARSER:=.c) \
       $(SCANNER:=.c)

OBJS_CPP = $(SRC)

# Substitution reference
DEPS := $(OBJS:%.c=%.d) $(OBJS_CPP:%.cpp=%.d)
OBJS := $(OBJS:%.c=%.o) $(OBJS_CPP:%.cpp=%.o)

all: $(EXEC)

# Static pattern rule
$(SCANNER).c: %.c: %.l
	$(LEX) -o $@ $<

$(PARSER).c: %.c: %.y
	$(YACC) -o $@ --defines=parser.h -v $<

%.o: %.c
	$(CC) -o $@ $(CFLAGS) $(INCLUDE) -c -MMD $<

%.o: %.cpp
	$(CC) -o $@ $(CFLAGS) $(INCLUDE) -c -MMD $<

$(EXEC): $(OBJS)
	$(CC) -o $@ $^ $(LIBS) $(INCLUDE)

clean:
	$(RM) $(DEPS) $(SCANNER:=.c) $(PARSER:=.c) $(OBJS) $(EXEC)

-include $(DEPS)
