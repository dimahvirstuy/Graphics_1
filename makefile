all:
	gcc pic_maker.c
	./a.out
clean:
	rm pic.ppm
	rm a.out
