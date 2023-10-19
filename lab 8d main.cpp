//l8B
//2 skip days used 

## THIS CODE DISPLAYS THE GIVEN PHOTO, MIGHTYFAVOG.JPG. AND BOUNCES AROUND SIMILAR TO THE DVD LOGO. 




#include <iostream>                             // for standard input/output
#include <algorithm>

using namespace std;                            // using the standard namespace

#include <SFML/Graphics.hpp>                    // include the SFML Graphics Library
using namespace sf;                             // using the sf namespace

int main() {
    //****************************************
    // New block for various constants
    //****************************************
    // our screen size
    const int window_width = 900;
    const int window_height = 900;
    const float ball_radius = rand() % (50 - 10 + 1) + 10;
    double X = (rand() % (400 - 100 + 1) + 100) / 2;
    double Y = (rand() % (400 - 100 + 1) + 100) / 2;

    // files
    const string spriteFile = "data/mightyfavog.jpg" ;

    // animation constants
    const float FRAME_RATE = 5000.0 ;  // control the speed of the animation loop in milliseconds

    //********************************************
    //  PLACE ANY FILE INPUT PROCESSING BELOW HERE
    //********************************************

    // our sprites position and velocity
    float sPositionX = 200 ;
    float sPositionY = 250 ;
    float sVelocityX = 1 ;
    float sVelocityY = 1 ;

    // now create the sprite
    Texture spriteTexture;
    if( !spriteTexture.loadFromFile( spriteFile ) ) {
        cerr << "[ERROR]: Could not open " << spriteFile << endl;
        return -1;
    }

    CircleShape circle;
    circle.setPosition(Vector2f(X, Y));
    circle.setRadius(rand() % (50 - 10 + 1) + 10);
    circle.setFillColor( Color::White );



//    std::vector<sf::Sprite> Bubbles;;
//    Sprite mySprite1;
//    mySprite1.setTexture(spriteTexture);
//    sf::Texture keyTexture;
//


    // We want to control the loop speed so it is the same no matter what computer we
    // run on.    We do this by delaying the loop using FRAME_RATE and the SFML clock object
    Clock frameRateClock ;

    //********************************************
    //  PLACE ANY FILE INPUT PROCESSING ABOVE HERE
    //********************************************

    // create a RenderWindow object
    RenderWindow window( VideoMode(window_width, window_height), "SFML Animation Example Window" );

    // while our window is open, keep it open
    // this is our draw loop
    while( window.isOpen() ) {
        window.clear(Color::Black);           // clear the contents of the old frame
        // by setting the window to black

        //****************************************
        //  ADD ALL OF OUR DRAWING BELOW HERE
        //****************************************

        // update the position
        sPositionX = sPositionX + sVelocityX;
        sPositionY = sPositionY + sVelocityY;

        // keep on screen
        if (sPositionX + spriteTexture.getSize().x > window_width) {
            sPositionX = 0;
        } else if( sPositionX < 0 ) {
            sPositionX = window_width - spriteTexture.getSize().x ;
        }

        if (sPositionY + spriteTexture.getSize().y > window_height ) {
            sPositionY = 0;
        } else if( sPositionY < 0 ) {
            sPositionY = window_height - spriteTexture.getSize().y ;
        }

        circle.setPosition( Vector2f( sPositionX, sPositionY ) ) ;

        window.draw( circle );

        //****************************************
        //  ADD ALL OF OUR DRAWING ABOVE HERE
        //****************************************

        window.display();                       // display the window

        //****************************************
        // HANDLE EVENTS BELOW HERE
        //****************************************
        Event event;
        while( window.pollEvent(event) ) {      // ask the window if any events occurred
            if (event.type == Event::Closed) { // if event type is a closed event
                // i.e. they clicked the X on the window
                window.close();                 // then close our window
            } else if (event.type == Event::KeyPressed) {
                switch (event.key.code) {
                    case Keyboard::Q:
                        window.close();
                        break;
                    case Keyboard::Left:
                    case Keyboard::Right:
                        sVelocityX = -sVelocityX;
                        break;
                    case Keyboard::Up:
                    case Keyboard::Down:
                        sVelocityY = -sVelocityY;
                        break;
                }
            }
            else if (event.type == Event::MouseButtonPressed) {
                sPositionX = event.mouseButton.x - spriteTexture.getSize().x/2 ;
                sPositionY = event.mouseButton.y - spriteTexture.getSize().y/2;
                if( sPositionX < 0) {
                    sPositionX = 0 ;
                }
                if( sPositionY < 0) {
                    sPositionY = 0 ;
                }

            }
        }

        // wait before looping
        while( frameRateClock.getElapsedTime() < microseconds( FRAME_RATE ) ) ;
        frameRateClock.restart() ; // reset the timer
    }

    return EXIT_SUCCESS;                        // report our program exited successfully
}
