CC=gcc
CFLAGS=-g 
LDLIBS=-lncurses
TARGET=dslab-project.out
OBJS=main.o ctime.o whatnum.o whatpic.o restime.o

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) -lncurses -lm

ctime.o : computeTime.c
	$(CC) -c -o ctime.o computeTime.c

whatnum.o : memoryWhatNum.c
	$(CC) -c -o whatnum.o memoryWhatNum.c

whatpic.o : memoryWhatPic.c
	$(CC) -c -o whatpic.o memoryWhatPic.c

restime.o : responseTime.c
	$(CC) -c -o restime.o responseTime.c

clean:
	rm $(OBJECT) $(TARGET)
