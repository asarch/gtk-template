TARGET = gtk-template
SRCS = main.c
OBJS = main.o
HDRS =
LD_FLAGS = `pkg-config gtk+-3.0 --libs`
CC_FLAGS = `pkg-config gtk+-3.0 --cflags`
CC_OPTS = -g -ggdb

$(TARGET) : $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LD_FLAGS)

$(OBJS) : $(SRCS) $(HDRS)
	$(CC) -c $(SRCS) $(CC_OPTS) $(CC_FLAGS)

.PHONY:
clean:
	rm $(TARGET) $(OBJS)
