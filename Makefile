CC=g++
CFLAGS=-g 
LDLIBS=-lncurses
TARGET=dslab-project.out
OBJS=main.o ctime.o whatnum.o whatpic.o restime.o

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) -lncurses -lm -std=c++14

ctime.o : computeTime.cpp
	$(CC) -c -o ctime.o computeTime.cpp

whatnum.o : memoryWhatNum.cpp
	$(CC) -c -o whatnum.o memoryWhatNum.cpp

whatpic.o : memoryWhatPic.cpp
	$(CC) -c -o whatpic.o memoryWhatPic.cpp

restime.o : responseTime.cpp
	$(CC) -c -o restime.o responseTime.cpp

clean:
	rm $(OBJECT) $(TARGET)
