#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

int main(){
    // time
    sf::Clock clock;
    sf::Time startTime = clock.getElapsedTime();
    std::cout << "start time: " << startTime.asMilliseconds() << " ms" << std::endl;

    // network
    sf::Http http;
    http.setHost("http://www.baidu.com/");
    sf::Http::Request request;
    sf::Http::Response response = http.sendRequest(request);
    std::cout << "status: " << response.getStatus() << std::endl;

    

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
