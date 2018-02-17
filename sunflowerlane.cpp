//sunflowerlane.cpp
//Laurin Fisher
//2-15-18
//SunflowerLane, a harvest-moon inspired farming game.
	//This is the main graphics loop file

#include <SFML/Graphics.hpp>
#include <iostream> 

int main(){
	float windowX = 500; 
	float windowY = 500; 

	sf::RenderWindow window(sf::VideoMode(windowX, windowY), "SunflowerLane"); 
	
	//Player
	sf::CircleShape Player(10.f); 
	Player.setFillColor(sf::Color::Red); 
	Player.setPosition(100,100); 
	//Draw black screen
	sf::RectangleShape board(sf::Vector2f(500.f, 500.f)); 
	board.setFillColor(sf::Color::Black); 

	//Draw farming squares 

	float moveAmt = 4.f; 

	while(window.isOpen()){
		sf::Event event; 
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close(); 
				return 0; 
			}

			//Move the Player 
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
				const sf::Vector2f playerPos = Player.getPosition(); 
				Player.setPosition(playerPos.x-moveAmt, 
					playerPos.y);
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
				const sf::Vector2f playerPos = Player.getPosition(); 
				Player.setPosition(playerPos.x+moveAmt, 
					playerPos.y);
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
				const sf::Vector2f playerPos = Player.getPosition(); 
				Player.setPosition(playerPos.x, 
					playerPos.y-moveAmt);
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
				const sf::Vector2f playerPos = Player.getPosition(); 
				Player.setPosition(playerPos.x, 
					playerPos.y+moveAmt);
			}
		}

		//Draw 
		window.clear(); 
		window.draw(board); 
		window.draw(Player); 
		window.display(); 
	}	

	return 0; 
}