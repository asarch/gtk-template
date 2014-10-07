TARGET = gtk-template
SRCS = main.c menu.c toolbar.c statusbar.c callbacks.c window.c
OBJS = main.o menu.o toolbar.o statusbar.o callbacks.o window.o
HDRS = main.h menu.h toolbar.h statusbar.h callbacks.h window.h
LD_FLAGS = `pkg-config gtk+-3.0 --libs`
CC_FLAGS = -g -ggdb
CC_FLAGS += `pkg-config gtk+-3.0 --cflags`

$(TARGET) : $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(LD_FLAGS)

$(OBJS) : $(SRCS) $(HDRS)
	$(CC) -c $(SRCS) $(CC_FLAGS)

.PHONY:
clean:
	rm $(TARGET) $(OBJS)
