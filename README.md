SelfJoystick

This is a PoC for a Joystick armor testing program.
Joystick buttons are displayed on the body and thank to Joystick usb bridge, I can interact with game.

Installation

Before you can run 'make all', you have to open the Makefile and insert the paths to your sfml installations where indicated.

Then run make. It will build executable 'SelfJoystick'

export LD_LIBRARY_PATH=/home/path/to/SFML-2.5.1/lib


If SFML is already on your LD_LIBRARY_PATH, invoke program using:

	./SelfJoystick
	
nb: for now it read from a directory hardcoded but in future release your just give the directory name

Otherwise invoke using:

	export LD_LIBRARY_PATH=/path-to-sfml-install/lib/ && /SelfJoystick music_directory

