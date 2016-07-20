NAME    := vernam
BIN_DIR := /usr/local/bin

all: build

build: $(NAME).c
	gcc -o $(NAME) $<

test: build
	./vernam --row zyxwvutsrqponmlkjihgfedcba --pad -1 --key test --text attackatdawn
	./vernam --row zyxwvutsrqponmlkjihgfedcba --pad -1 --key test --cipher gcogelhndvlt

install: build
	install -m 0755 $(NAME) $(BIN_DIR)

uninstall:
	rm -f $(BIN_DIR)/$(NAME)

clean:
	rm -r $(NAME)