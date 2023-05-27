#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main(){
    // create the main window
    sf::RenderWindow window(sf::VideoMode(500, 600), "SFML works!");
    
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
 }
