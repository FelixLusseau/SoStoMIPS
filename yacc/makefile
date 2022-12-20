prefixe=compilateur

# exige 3 fichiers:
# - $(prefixe).y (fichier bison)
# - $(prefixe).lex (fichier flex)
# - main.c (programme principal)
# construit un exécutable nommé "main"

# note : le programme principal ne doit surtout pas s'appeler $(prefixe).c
# (make l'écraserait parce qu'il a une règle "%.c: %.y")

all: main

main: $(prefixe).tab.o lex.yy.o main.o quads.o tos.o
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS) -lm

quads: quads.c quads.h	
		$(CC) -o quads.o -c quads.c -Wall -Wextra -Werror -lm

tos: tos.c tos.h	
		$(CC) -o tos.o -c tos.c -Wall -Wextra -Werror

$(prefixe).tab.c: $(prefixe).y
	bison -t -d $(prefixe).y

lex.yy.c: $(prefixe).lex $(prefixe).tab.h
	flex $(prefixe).lex

doc:
	bison --report=all --report-file=$(prefixe).output \
		--graph=$(prefixe).dot --output=/dev/null \
		$(prefixe).y
	dot -Tpdf < $(prefixe).dot > $(prefixe).pdf

test : main
	./main < test/test2.txt 

clean:
	rm -f *.o $(prefixe).tab.c $(prefixe).tab.h lex.yy.c main \
		$(prefixe).output $(prefixe).dot $(prefixe).pdf
