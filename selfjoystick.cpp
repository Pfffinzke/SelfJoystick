
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <cstring>
#include <unistd.h>
#include <cmath>
#include "selfjoystick.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <cstdint>
#include <random>


using namespace std;


int current_life = 10;
bool pressed = false;

int main() {
	
// Create the main window
sf::RenderWindow window(sf::VideoMode(480, 320), "SFML window");

//get information about the joystick
sf::Joystick::Identification id = sf::Joystick::getIdentification(0);
std::cout << "\nVendor ID: " << id.vendorId << "\nProduct ID: " << id.productId << std::endl;
sf::String controller("Joystick Use: " + id.name);

	
// Create a graphical text to display
sf::Font font;
if (!font.loadFromFile("aAkuilah.ttf"))
	return EXIT_FAILURE;

		sf::String LifeText = std::to_string(10);

		sf::Text Life;
		Life.setFont(font);
		Life.setColor(sf::Color::Red);
		Life.setPosition(140.0f,50.0f);
		Life.setCharacterSize(200);
		Life.setStyle(sf::Text::Bold);
		Life.setOutlineColor(sf::Color(125, 0, 8));
		Life.setOutlineThickness(3.0f);

 
while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
        {
        	// Close window: exit
          	if (event.type == sf::Event::Closed) {
				window.close();
			} else if (event.type == sf::Event::KeyPressed) {
				// the user interface: SPACE pauses and plays, ESC quits
				switch (event.key.code) {
        case sf::Keyboard::Escape:
					  std::cout << "press escape - escape" << std::endl;
						window.close();
						break;
					}
				}
			}
        
        if(event.type == sf::Event::JoystickButtonPressed && pressed==false) {
					switch (event.joystickButton.button) {
						case 0 :
							pressed=true;
							current_life--;
							break;
	
						case 1 :
							pressed=true;
							current_life--;
							break;
	
						case 2 :
							pressed=true;
							current_life--;
							break;
	
						case 3 :
							pressed=true;
							current_life--;
							break;
	
						default:
							break;
					}
				}
				if(event.type==sf::Event::JoystickButtonReleased){
					pressed=false;
				}
        // Clear screen
        window.clear();
        // Draw the string
        if (current_life >= 1){
        			Life.setPosition(140.0f,50.0f);
        			Life.setCharacterSize(200);
        		Life.setString(std::to_string((int)(current_life)));
        }
        else if (current_life == 0){
        	Life.setPosition(30.0f, 80.0f);
        	Life.setCharacterSize(130);
        		Life.setString("DEAD");
        }
       else if (current_life < 0){
        	current_life=10;
        }
        window.draw(Life);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}