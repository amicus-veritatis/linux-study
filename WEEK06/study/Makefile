CC ?= gcc
CFLAGS ?= -Wall -Wextra -g
SRC = program.c
OBJDIR ?= build
OBJ = $(addprefix $(OBJDIR)/, $(notdir $(SRC:.c=.o)))

TARGET ?= program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: %.c $(DEPS) | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# Ensure the object directory exists
$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) $(TARGET)

.PHONY: all clean
