CFLAGS=-std=c++11 -g -Wl,--no-undefined -w

SFML=~/dev/SFML-2.5.1

INCLUDESFML=$(SFML)/include

LIBSFML=$(SFML)/lib

INCLUDES := -I $(INCLUDESFML)

LIBS     :=  -L $(LIBSFML) -l sfml-graphics -l sfml-window -l sfml-system   -lmagic 

all: SelfJoystick
	
selfjoystick.o: selfjoystick.cpp selfjoystick.hpp 
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@ 

SelfJoystick: selfjoystick.o
	@echo "** Building the game"
	g++ -o SelfJoystick selfjoystick.o $(LIBS)

clean:
	@echo "** Removing object files and executable..."
	rm -f SelfJoystick *.o

install:
	@echo '** Installing...'
	cp SelfJoystick /usr/bin

uninstall:
	@echo '** Uninstalling...'
	rm -f /usr/bin/SelfJoystick
 