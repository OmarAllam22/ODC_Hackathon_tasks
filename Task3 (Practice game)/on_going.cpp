#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

const int M = 20;
const int N = 10;

struct point { int x, y; }; //diff between struct and class is that, struct by default is public but class by default is private.
point a[4];       //  creates a point object from the struct point with four numbers..from this object I can call x & y of the struct
point b[4];		  //  creates a point object from the struct point with four numbers..from this object I can call x & y of the struct


int field[M][N] = {};

// following array draws differnt cube examples
int figures[7][4] = {
	1,3,5,7,
	2,4,5,7,
	3,5,4,6,
	3,5,4,7,
	2,3,5,7,
	3,5,7,6,
	2,3,4,5,
};


bool check()
{
	for (int i = 0; i < 4; i++)
		if (a[i].x < 0 || a[i].x >= N || a[i].y >= M) return 0;
		else if (field[a[i].y][a[i].x]) return 0;

	return 1;
};


int main() {

	RenderWindow win(VideoMode(400, 600), "my game");
	Texture back, cubes, frame;
	back.loadFromFile("C:\\Users\\HP\\Downloads\\back.png");
	cubes.loadFromFile("C:\\Users\\HP\\Downloads\\cubes.png");
	frame.loadFromFile("C:\\Users\\HP\\Downloads\\fram.png");

	Sprite sprite1(back), sprite2(cubes), sprite3(frame); 

	sprite2.setTextureRect(IntRect(0, 0, 18, 18));   // IntRect just draw rectangle but not as a shape ... it draws it as integer positions....first two numbers are
													 // the position , and second two numbers are the size of the rectangle
	
													 // setTextureRect() crop a rectangle with the given IntRect

	int dx = 0; bool rotate = 0; int colorNum = 1;
	float timer = 0, delay = 0.3;
	
	Clock clock;   //it is a class enables me to get the ellapsed time


	while (win.isOpen()) {

		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;




		Event e;
		while (win.pollEvent(e))
		{
			if (e.type == Event::Closed) win.close();

				if (e.key.code == Keyboard::Up) rotate = true;
				else if (e.key.code == Keyboard::Left)  dx = -1;
				else if (e.key.code == Keyboard::Right) dx = 1;
		
	   	}

		if (Keyboard::isKeyPressed(Keyboard::Down)) delay = 0.05;


		win.clear();
		win.draw(sprite1);
		win.draw(sprite2);
		win.display();


	}


}










//rect int to deal with textures. 






/*
int main() {


	RenderWindow win(VideoMode(1280, 700),"my second project");
	CircleShape triangle(100, 3);     // this draws the triangle because the second parameter in the circle determines the number of angles ... so when it
		    						  // 360 then it is a circle... and so if it is empty (default is 360) .. then the number 3 is for triangle (no of triangel angles)
	
    // draw line
	VertexArray line(LinesStrip, 4);
	line[0].position = Vector2f(10, 10);
	line[0].color = Color::Cyan;
	line[1].position = Vector2f(20, 20);
	line[1].color = Color::Red;
	line[2].position = Vector2f(30, 30);
	line[2].color = Color::Blue;
	line[3].position = Vector2f(40, 40);
	line[3].color = Color::Green;




}

*/


//Vertex Vs VertexArray is that ... VertexArray is already an array so we should't pass [] when we define it.

// this method is to draw a line,,, we can also draw line by combining many rectangles each other.
