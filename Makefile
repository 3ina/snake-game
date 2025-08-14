CC = gcc
CFLAGS = -g -Wall -I$(SRC_DIR)
LDFLAGS = -lncurses
TARGET = my_game
SRC_DIR = src
BUILD_DIR = build
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCES))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@echo "Cleaning project..."
	rm -f $(TARGET)
	rm -rf $(BUILD_DIR)
	rm -f $(SRC_DIR)/*.gch
	@echo "Done."
.PHONY: all clean
