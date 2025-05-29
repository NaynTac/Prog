CC = gcc
CFLAGS = -Wall -Wextra -g $(shell pkg-config --cflags sdl2 SDL2_image)
LDFLAGS = $(shell pkg-config --libs sdl2 SDL2_image)
SRCS = main.c graphics.c
OBJS = $(SRCS:.c=.o)
TARGET = dvd_screensaver


all: $(TARGET)


$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	$(RM) -f $(OBJS) $(TARGET)