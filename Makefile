SHELL:= cmd.exe

CC=gcc
CFLAGS=-Wall -Wextra -g
SRCS=$(wildcard src/*.c)
OUT=todoist.exe
TEST=tests\test.ps1

all: build

build:
	$(CC) $(CFLAGS) $(SRCS) -Isrc -o $(OUT)

test: build
	powershell -ExecutionPolicy Bypass -File $(TEST)

clean:
	del /Q $(OUT)

rebuild: clean build
