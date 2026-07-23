CC = gcc
CFLAGS = -Wall -Wextra

OBJDIR = obj/
SRCDIR = src/

SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

TARGET = interpreter

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(TARGET) 

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -rfv $(TARGET) ${OBJS}
	rmdir -v $(OBJDIR)

.PHONY: clean
