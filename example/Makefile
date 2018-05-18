CC		:= gcc
CFLAGS  	:= -Wall

OUTNAME 	:= kvExample

C_FILES 	 := ../src/lcKeyValueMap.c  example.c
OBJ_FILES  	 := $(C_FILES:%.c=%.o)

example: $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $(OUTNAME) $^

clean: 
	find ../ -name '*.o' -delete
	rm -f $(OUTNAME)
