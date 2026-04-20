SRC = $(wildcard *.c)
HEADERS = $(wildcard *.h)
OBJ = $(SRC:.c=.o)
TARGET = prog1

all: $(TARGET)

$(TARGET): $(OBJ)
	gcc -o $(TARGET) $(OBJ)

%.o: %.c $(HEADERS)
	gcc -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJ)
