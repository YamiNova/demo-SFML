#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

int main(){
    sf::Clock clock;
    sf::Time time1 = clock.getElapsedTime();
    std::cout << "current time: " << time1.asMilliseconds() << " ms" << std::endl;

    // create the main window
    sf::RenderWindow window(sf::VideoMode(1366, 768), "SFML window");

    sf::Texture texture;
    if (!texture.loadFromFile("resource/picture/BTS.jpg"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    sf::Music music;
    if (!music.openFromFile("resource/music/Come-On.wav"))
        return EXIT_FAILURE;
    
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);

    music.play();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed)
                window.close();
        }
        window.clear();
        window.draw(shape);
        window.draw(sprite);
        window.display();
    }
    return 0;
 }
