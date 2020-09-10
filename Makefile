CC = gcc

objects = q3c_dsa.o aux_dsa.o

q3c: $(objects)
	$(CC) -o q3c q3c_dsa.o aux_dsa.o

q3c_dsa.o: q3_dsa.h

aux_dsa.o: q3_dsa.h

.PHONY: clean
clean:
	rm $(objects) q3c