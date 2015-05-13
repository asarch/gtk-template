TARGET = gtk-template
SRCS = main.c
OBJS = main.o
HDRS =

CC_FLAGS = -g -ggdb
CC_FLAGS += `pkg-config gtk+-3.0 --cflags`

LD_FLAGS = `pkg-config gtk+-3.0 --libs`

$(TARGET) : $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LD_FLAGS)

$(OBJS) : $(SRCS) $(HDRS)
	$(CC) -c $(SRCS) $(CC_FLAGS)

.PHONY:
clean:
	rm $(TARGET) $(OBJS)
