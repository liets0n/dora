SRC_DIR := ./src
BIN_DIR := ./bin
BUILD_DIR := ./build
INCLUDE_DIR := ./include

CC := gcc

OBJS := dora.o dir.o usage.o

# Compiler and Linker flags Settings:
#   -Wall: Enable all warnings
#   -Wextra: Enable extra warnings
#   -I $(INCLUDE_DIR): Include the include directory
CFLAGS := -Wall -Wextra -I $(INCLUDE_DIR)


# Targets

# Build dora executable
dora: dir $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/dora $(foreach file,$(OBJS),$(BUILD_DIR)/$(file))

# Build object files
%.o: dir $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$*.o -c $(SRC_DIR)/$*.c

# Setup build and bin directories
dir:
	@mkdir -p $(BUILD_DIR) $(BIN_DIR)

# Clean build and bin directories
clean:
	@rm -rf $(BUILD_DIR) $(BIN_DIR)


.PHONY: dir clean
