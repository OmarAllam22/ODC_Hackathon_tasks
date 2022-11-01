#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

// ÈÍÑß ãÓÊØíá áÛÇíÉ ÃãÇ íáŞØ ÇÓãì Úáì ÇáÔÇÔÉ æ ßÏå ßÓÈÊ ... æãßÇä ÇáÅÓã Úáì ÇáÔÇÔÉ Ïå ÈíÙåÑ ÈÔßá ÑÇäÏã ßá áãÇ ÈÚãá Ñä 


int main() {

	// Creating the RenderWindow
	RenderWindow win(VideoMode(1200, 700), "First"); 
	RectangleShape shape;
	Vector2f rec_position(600, 350);         // this vector2f class is for posiiton only it creates a postition vector with 2 float-numbers.
	
    // Setting position
	shape.setPosition(rec_position);         // here we set the position of the circleshape we have created to be the vector2f.
	shape.setSize(Vector2f(200, 100));       // with rectangles, we type rect.size(Vector2f(100,100)) ... Vector2f is for position or precisely 2 float variables.
	
	// generating random values for the position of text.
	srand(time(0));							 // set the seed to be the current time and current time changes every second so this is like if the seed is not set.
	int x_value =  rand() % ( 1200 - 150 );  // to guarantee that random x_position doesn't exceed the width of the frame
	int y_value =  rand() % ( 700  - 50  );  // to guarantee that random y_position doesn't exceed the heightof the frame

	cout << x_value << "\n" << y_value ;
	
	// Loading the font
	Font my_font;
	my_font.loadFromFile("F:\\Design\\Fonts\\digital-7 (italic).ttf");
	
	// Generating Text
	Text my_text;
	my_text.setFont(my_font);
	my_text.setPosition(x_value, y_value);
	my_text.setFillColor(Color::Black);
	my_text.setString("Omar Allam");
	
	// Setting the game loop
	while (win.isOpen()) {

		shape.setPosition(Mouse::getPosition(win).x - 100, Mouse::getPosition(win).y - 25);   //subtraction to move the shape from its middle.
		
		// Listening to events
		Event e;
		while (win.pollEvent(e)) {    
			if (e.type == Event::Closed || e.type == Event::MouseButtonPressed)  win.close(); //close the game when I fined the text.
		}


		win.clear();
		
		win.draw(shape);
		win.draw(my_text);
		win.display();
	}
}








/*

if (rec_position.x < 0 || rec_position.x > 1200 - 200) x_inc *= -1;
if (rec_position.y < 0 || rec_position.y > 700 - 200) y_inc *= -1;

rec_position.x += x_inc;
rec_position.y += y_inc;



shape.setPosition(rec_position);
*/






/*
switch (e.type)
{

	case Event::KeyPressed :
		cout << "KeyPressed\n";
		break;
	case Event::MouseMoved:
		cout << e.mouseMove.x << " " << e.mouseMove.y << "\n";
		break;
	case Event::MouseButtonPressed :
		cout << "Mouse is pressed\n";
		break;
	case Event::Resized:
		cout << e.size.height << "\n" << e.size.width;
		break;

}
*/
//if (Keyboard::isKeyPressed(Keyboard::Space) ) 	cout << "Space is pressed\n";
// if (Mouse::isButtonPressed(Mouse::Left))     cout << Mouse::getPosition(win).x << " " << Mouse::getPosition(win).y << endl;

//if (Keyboard::isKeyPressed(Keyboard::Right)

	//shape.Move(2,3);



// if (e.key.code == Keyboard::R) cout << e.key.code ;

//if (e.type == Event::MouseMoved) {
//	cout << e.mouseMove.x << " " << e.mouseMove.y;   // to enable this command, you must call std --> using namespace std;
	// this cout prints the postiton of the event you do ... (but the line is excuted as long as you are inside the window .,,
	// (when you move the mouse outisde the window, no number printed )
// if (e.type == Event::Closed) win.close();
	//if (e.mouseMove == Event::MouseButtonEvent) ;

// Ïì ÚÔÇä íÎáíäì áãÇ ÃÎÏ ÇíİíäÊ ÇáÇíİíäÊ Ïå ÚÈÇÑÉ Úä Çäì ÃÖÛØ Úáì ÚáÇãÉ ÇáÇßÓ Çááì İì ÇáæíäÏæ ÈÊÇÚì ... ŞáÊáå áãÇ ÇÖÛØ Úáì ÇáÇßÓ íŞæã ŞÇİá ÇáæíäÏæ

//	}
