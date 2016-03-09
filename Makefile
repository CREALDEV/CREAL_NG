# Main Makefile for CREAL_NG/ZOE-BIOS

all : linenoise creal strls signals main

linenoise : src/linenoise.c src/include/linenoise.h
#~ 	@echo "Complie and Link Marxd"
	cc src/linenoise.c -c 
#-Wall

creal : main.c 
#~ 	@echo "making CREAL_NG"
	cc  -c main.c -o creal.o
#-Wall

strls : src/stringManipulation/strlcat.c src/stringManipulation/strlcpy.c 
#~ 	@echo "making CREAL_NG"
	cc -c src/stringManipulation/strlcat.c src/stringManipulation/strlcpy.c 
#-Wall

signals : src/signals.c src/include/signals.h 
#~ 	@echo "making CREAL_NG"
	cc -c src/signals.c 
#-Wall

main : linenoise.o creal.o strlcat.o strlcpy.o signals.o 
	@echo "making CREAL_NG"
	cc  creal.o linenoise.o strlcat.o strlcpy.o signals.o -o creal_ng
#-Wall

install :
	@echo "Disabled"
#~ 	cp default_marxd.conf marxd.conf

clean :
	@echo "Deleting build files"
	rm  creal.o linenoise.o strlcat.o strlcpy.o signals.o creal_ng

uninstall :
	@echo "Disabled"
#~ 	rm -f Marxd jobsender marxd.conf
	
debug :
	@echo "Not implemented yet"
#~ 	rm -f Marxd jobsender marxd.conf
