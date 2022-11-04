#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

// Defining coin class
class Coin
{
public:
	Coin(Vector2f size) {
		coin.setSize(size);
		coin.setFillColor(Color::Yellow);
	}

	void drawTo(RenderWindow &win) {
		win.draw(coin);
	}

	FloatRect getGlobalBounds() {
		return coin.getGlobalBounds();
	}

	void setPosition(Vector2f new_pos) {
		coin.setPosition(new_pos);
	}

private:
	RectangleShape coin;
};


// Defining player class
class Player {
public:
	Player(Vector2f size) {
		player.setSize(size);
		player.setFillColor(Color::Green);
	}

	void drawTo(RenderWindow &win) {
		win.draw(player);
	}

	void move(Vector2f distance) {
		player.move(distance);
	}

	void setPos(Vector2f newPos) {
		player.setPosition(newPos);
	}
	int getY() {
		return player.getPosition().y;
	}
	bool isCollidingWithCoin(Coin *coin){
		if (player.getGlobalBounds().intersects(coin->getGlobalBounds())) {
			return true;
		}
		return false;
	}


private:
	RectangleShape player;
};



int main() {

	RenderWindow win(VideoMode(900, 900), "my");
	
	// calling the `Player` class
	Player player({ 40, 40 });             // look at the { } we wrote to accept a vector2f instead () 
	player.setPos({ 50,700 });
	

	// calling the `coin` class
	vector<Coin*> vec;
	Coin coin1({ 20,20 });
	Coin coin2({ 20,20 });
	vec.push_back(&coin1);
	vec.push_back(&coin2);

	coin1.setPosition({ 200,200 });
	coin2.setPosition({ 400,400 });



	SoundBuffer buffer; 
	buffer.loadFromFile("F:\\gun.wav");

	Sound sound(buffer);
	sound.play();



	const int gravity_height = 700;
	const float gravity_speed = 0.3f;        // number of pixels to move with
	bool is_jumping = false;

	// entering the `loop` game:
	while (win.isOpen()) {
		const float move_speed = 0.2f;
		Event e;
		
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			player.move({ 0, -move_speed });
			is_jumping = true;
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down))  player.move({ 0, move_speed });
		else if (Keyboard::isKeyPressed(Keyboard::Left))  player.move({ -move_speed, 0});
		else if (Keyboard::isKeyPressed(Keyboard::Right)) player.move({ move_speed, 0 });


		// this to make the object falls as gravity... the gravity_speed reduces it until it reaches the gravity_height then stop falling.
		if (player.getY() < gravity_height && is_jumping == false) {
			player.move({ 0, gravity_speed });
		}

		//coin logic : this is to make the coin disappear (move to a position outside the frame) when it collides with the square.

		for (int i = 0; i < vec.size(); i++) {
			if (player.isCollidingWithCoin(vec[i]) ) {
				vec[i]->setPosition({ 40000, 300000 });   // to emulate that it disappeared.
			}
		}


		while (win.pollEvent(e)) {
			switch (e.type) {
			case (Event::Closed): 
				win.close();
				break;
			case (Event::KeyReleased):
				is_jumping = false;
				break;
			}
		}
		

		win.clear();
		coin1.drawTo(win);
		coin2.drawTo(win);
		player.drawTo(win);
		win.display();
	}


}