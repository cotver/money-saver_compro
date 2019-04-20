compiler = gcc
versions = -std=c99
object = main.o border.o gettime.o login.o system.o datacall.o record.o savings.o
exec_file = MoneySaver

$(exec_file): $(object)
	$(compiler) $(versions) $(object) -o $(exec_file) -lm -rm *.o

main.o: main.c all.h
	$(compiler) $(versions) -c main.c

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

record.o: record.c all.h
	$(compiler) $(versions) -c record.c

savings.o: savings.c all.h
	$(compiler) $(versions) -c savings.c

.PHONY : clean

run:
	./$(exec_file)
