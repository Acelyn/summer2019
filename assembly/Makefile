ruoya: main.o checksum.o
	gcc -o ruoya main.o checksum.o

main.o: main.c
	gcc -c main.c

checksum.o: checksum.s
	gcc -c checksum.s

#junk.s: junk.c 
#	gcc -S -O3 junk.c
