//L7A-CSCI 261
//LEXUS CARTON
//NOVEMBER 7,2019
#include <iostream>
#include <cmath>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

int main() {

    // TODO #1
    // creates the window object with an 640x640 resolution window
    RenderWindow window(VideoMode(640, 640, 32), "SFML Example");

    /***** PLACE YOUR FILE PROCESSING CODE HERE *****/

    // TODO #3
    // Draw loop: Each iteration of this loop draws a single frame
    while (window.isOpen()) {

        // Erase the screen with black (because space)
        window.clear( Color::Blue );

        /***** PLACE YOUR DRAW CALLS HERE *****/

        // TODO #6

        // TODO #7
        RectangleShape rect;
        rect.setSize( Vector2f( 150, 350 ) );
        rect.setPosition( 250, 200 );
        rect.setFillColor( Color(150, 75, 0) );
        window.draw(rect);

        CircleShape star;
        star.setPosition( 200, 100 );
        star.setRadius(75);
        star.setFillColor( Color::Green );
        window.draw( star );

        CircleShape leaf;
        leaf.setPosition( 225, 125 );
        leaf.setRadius(100);
        leaf.setFillColor( Color::Green );
        window.draw( leaf );

        CircleShape leaf2;
        leaf2.setPosition( 275, 75 );
        leaf2.setRadius(75);
        leaf2.setFillColor( Color::Green );
        window.draw( leaf2 );

        CircleShape leaf3;
        leaf3.setPosition( 350, 125 );
        leaf3.setRadius(50);
        leaf3.setFillColor( Color::Green );
        window.draw( leaf3 );


        CircleShape leaf4;
        leaf4.setPosition( 175, 200 );
        leaf4.setRadius(50);
        leaf4.setFillColor( Color::Green );
        window.draw( leaf4 );


        RectangleShape line;
        rect.setSize( Vector2f( 150, 350 ) );
        line.rotate(45);
        rect.setPosition( 250, 200 );
        rect.setFillColor( Color(150, 75, 0) );
        window.draw(line);


        // TODO #10


        /***** END OF DRAWING	*****/

        // TODO #2:
        // Apply all the draws to the screen
        window.display();

        // TODO #5
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();

                }
            }
        }



    return EXIT_SUCCESS;
}
