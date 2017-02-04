all: make_image

make_image:
	gcc -o make_image make_image.c

clean:
	rm *.o
	rm *~
