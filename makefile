compiler = gcc
versions = -std=c99
object = g.o border.o gettime.o login.o system.o datacall.o
exec_file = a

$(exec_file): $(object)
	$(compiler) $(versions) $(object) -o $(exec_file) -lm
	-rm *.o

g.o: g.c all.h
	$(compiler) $(versions) -c g.c

border.o: border.c all.h
	$(compiler) $(versions) -c border.c

gettime.o: gettime.c all.h
	$(compiler) $(versions) -c gettime.c

login.o: login.c all.h
	$(compiler) $(versions) -c login.c

system.o: system.c all.h
	$(compiler) $(versions) -c system.c

datacall.o: datacall.c all.h
	$(compiler) $(versions) -c datacall.c

.PHONY : clean

run:
	./$(exec_file)
