CC = gcc

CFLAGS = -g -Wall -Wextra -Werror -Wno-unused-function
LDLIBS = -lm

LEXYACC_PATH = ./lex-yacc
INCLUDE_PATH = ./include

TARGET       = sos

SRCDIR       = src
OBJDIR       = obj
BINDIR       = bin

SOURCES     := $(wildcard $(SRCDIR)/*.c)
INCLUDES    := $(wildcard $(INCLUDE_PATH)/*.h)
OBJECTS_TMP     := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

LEXSRC      := $(wildcard $(LEXYACC_PATH)/*.lex)
YACCSRC     := $(wildcard $(LEXYACC_PATH)/*.y)
LEXC		:= $(LEXSRC:$(LEXYACC_PATH)/%.lex=$(SRCDIR)/%.c)
YACCC		:= $(YACCSRC:$(LEXYACC_PATH)/%.y=$(SRCDIR)/%.c)
LEXOBJ		:= $(LEXSRC:$(LEXYACC_PATH)/%.lex=$(OBJDIR)/%.o)
YACCOBJ		:= $(YACCSRC:$(LEXYACC_PATH)/%.y=$(OBJDIR)/%.o)

OBJECTS      = $(filter-out $(LEXOBJ) $(YACCOBJ), $(OBJECTS_TMP))

OUTPUT  = $(BINDIR)/$(TARGET)

all : $(OUTPUT)

$(LEXC):
	flex -o $@ $(LEXSRC)
	@echo "\033[92mLexing complete !\033[0m"

$(YACCC):
	bison -d -o $@ $(YACCSRC) 
	@echo "\033[92mYaccing complete !\033[0m"

$(OUTPUT): $(OBJECTS) $(LEXOBJ) $(YACCOBJ)
	mkdir -p $(BINDIR)
	$(CC) -o $@ $^ $(CFLAGS) $(LDLIBS)
	@echo "\033[92mLinking complete !\033[0m"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c $(INCLUDES) $(LEXC) $(YACCC)
	mkdir -p $(OBJDIR)
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDE_PATH)
	@echo "\033[92mCompiling complete !\033[0m"

$(LEXOBJ): $(OBJDIR)/%.o : $(SRCDIR)/%.c $(INCLUDES) $(LEXC)
	mkdir -p $(OBJDIR)
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDE_PATH)
	@echo "\033[92mCompiling lex complete !\033[0m"

$(YACCOBJ): $(OBJDIR)/%.o : $(SRCDIR)/%.c $(INCLUDES) $(YACCC)
	mkdir -p $(OBJDIR)
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDE_PATH)
	@echo "\033[92mCompiling yacc complete !\033[0m"

test :  $(OUTPUT)
		for file in $(wildcard tests/*.txt) ; do \
			echo "\033[92m-------------------------------TEST COMPILATION-------------------------------\033[0m" $${file} ; \
			rm -f mips.asm ; \
			if ! ./$(OUTPUT) --tos < $${file}  ; then \
				echo "\n\033[91mError in $${file}\033[0m" ; \
				exit 1 ; \
			fi ; \
        done

test_mips :  $(OUTPUT)
		for file in $(wildcard tests/*.txt) ; do \
			echo "\033[92m-------------------------------TEST COMPILATION-------------------------------\033[0m" $${file} ; \
			rm -f mips.asm ; \
			if ! ./$(OUTPUT) --tos < $${file} > /dev/null ; then \
				echo "\n\033[91mError in $${file}\033[0m" ; \
				continue ; \
			else \
				echo "\033[92mOk\033[m" ; \
			fi ; \
			echo "\n\033[0;34m------------TEST MIPS------------\033[0m" ; \
			if spim -file mips.asm 2>&1 | grep -A 20 'error\|parser\|undefined' ; then \
				echo "\n\033[91mError in $${file}'s MIPS\033[0m\n" ; \
			else \
				echo "\033[0;34mOk\033[m\n" ; \
			fi ; \
			echo "\n" ; \
        done

benchs :  $(OUTPUT)
		for file in $(wildcard BenchmarksSoS/*.sos) ; do \
			echo "\033[92m-------------------------------TEST COMPILATION-------------------------------\033[0m" $${file} ; \
			rm -f mips.asm ; \
			if ! ./$(OUTPUT) --tos < $${file}  ; then \
				echo "\n\033[91mError in $${file}\033[0m" ; \
				exit 1 ; \
			fi ; \
        done

benchs_mips :  $(OUTPUT)
		for file in $(wildcard BenchmarksSoS/*.sos) ; do \
			echo "\033[92m-------------------------------TEST COMPILATION-------------------------------\033[0m" $${file} ; \
			rm -f mips.asm ; \
			if ! ./$(OUTPUT) --tos < $${file} > /dev/null ; then \
				echo "\n\033[91mError in $${file}\033[0m" ; \
				continue ; \
			else \
				echo "\033[92mOk\033[m" ; \
			fi ; \
			echo "\n\033[0;34m------------TEST MIPS------------\033[0m" ; \
			if spim -file mips.asm 2>&1 | grep -A 20 'error\|parser\|undefined' ; then \
				echo "\n\033[91mError in $${file}'s MIPS\033[0m\n" ; \
			else \
				echo "\033[0;34mOk\033[m\n" ; \
			fi ; \
			echo "\n" ; \
        done

.PHONY: clean doc
doc:
	mkdir -p doc
	bison --report=all --report-file=doc/yacc.output \
		--graph=doc/yacc.dot --output=/dev/null \
		lex-yacc/yacc.y
	dot -Tpdf < doc/yacc.dot > doc/yacc.pdf

clean:
	rm -f $(OBJDIR)/*.o
	rm -f $(OUTPUT)
	rm -f $(LEXC)
	rm -f $(YACCC) $(YACCC:.c=.h) $(YACCC:.c=.output)
	rm -rf doc
	rm -f mips.asm
