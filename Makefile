SHELL:= cmd.exe

CC=gcc
CFLAGS=-Wall -Wextra -g
SRCS=$(wildcard src/*.c)
OUT=todoist.exe

all: build

build:
	$(CC) $(CFLAGS) $(SRCS) -Isrc -o $(OUT)

clean:
	del /Q $(OUT)

rebuild: clean build
