//библиотеки:
#include <SFML/Graphics.hpp>
#include <iostream>
// заголовки:
#include "view.h"
#include "mission.h"
using namespace sf;
class lvl
{
public:
    
    Image tile;
    Texture texture;
    float x = 0, y = 0, currentFrame = 0;
    Sprite sprite;
    lvl()
    {
        tile.loadFromFile("карта.png");
        texture.loadFromImage(tile);
        sprite.setTexture(texture);
        sprite.setPosition(0, 0);
    }
};
class Player {
private: float x = 0, y = 0;
public:
    float dx = 0, dy = 0, speed;
    int dir = 0;
    String File;
    Image image;
    View view;
    Texture texture;
    Sprite sprite;
    float  currentFrame = 0;
    int r = 1, l = 1;
    Player()
    {
        dx = 0; dy = 0; speed = 0;
        image.loadFromFile("pngwing.com.png");
        texture.loadFromImage(image);
        sprite.setTexture(texture);
     //   sprite.setTextureRect(IntRect(0, 0, 50, 40));
        sprite.setPosition(500, 500);
        sprite.scale(0.1f, 0.1f);
    }
    void controll(float time)
    {

        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            dir = 1; speed = 0.1;
            getplayercoordinateforview(X(), Y());
        }

        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            dir = 0; speed = 0.1;
            getplayercoordinateforview(X(), Y());
        }

        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            dir = 3; speed = 0.1;
            getplayercoordinateforview(X(), Y());

        }

        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            dir = 2; speed = 0.1;
            //CurrentFrame += 0.005 * time;
            //if (CurrentFrame > 3) CurrentFrame -= 3;
           // p.sprite.setTextureRect(IntRect(96 * int(CurrentFrame), 0, 96, 96));
            getplayercoordinateforview(X(), Y());

        }
    }
    void update(float time)
    {
        switch (dir)
        {
        case 0: dx = speed; dy = 0; break;
        case 1: dx = -speed; dy = 0; break;
        case 2: dx = 0; dy = speed; break;
        case 3: dx = 0; dy = -speed; break;
        }
        

        x += dx * time;
        y += dy * time;
        speed = 0;
        sprite.setPosition(x, y);
        view.setCenter(x, y);
    }
    float X() {
        //std::cout << x << " " << y << "\n";
        return x;
    }
    float Y() {
        return y;
    }
};
int main()
{
    RenderWindow window(VideoMode(2600, 1600), "gamme");
    CircleShape shape(10.f);
    shape.setPosition(1780, 55);
    shape.setFillColor(sf::Color(100, 250, 50));
    lvl map;
    Player p;
    Clock clock;


    Image tile1;
    Sprite sprite;
    Texture texture;
    tile1.loadFromFile("парк патриот.png");
    texture.loadFromImage(tile1);
    sprite.setTexture(texture);
    sprite.setPosition(550, 800);
    sprite.scale(0.1f, 0.1f);

    Texture tmission;
    tmission.loadFromFile("novat.png");
    Image imission;
    Sprite smission;
    smission.setPosition(500, 500);


    Image tile2;
    Sprite sprite2;
    Texture texture2;
    tile2.loadFromFile("монумент славы.png");
    texture2.loadFromImage(tile2);
    sprite2.setTexture(texture2);
    sprite2.setPosition(830, 1300);
    sprite2.scale(0.1f, 0.1f);
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 100;
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();



        }
        FloatRect sopriteBones = p.sprite.getGlobalBounds();
        FloatRect sopriterestagle = shape.getGlobalBounds();
        FloatRect sopriterestagle1 = sprite2.getGlobalBounds();
        FloatRect sopriterestagle2 = sprite.getGlobalBounds();
        p.controll(time);
        p.update(time);
        window.clear();
        window.draw(map.sprite);
        if (sopriteBones.intersects(sopriterestagle)) { smission.setPosition(500, 500); smission.setTexture(tmission); window.draw(smission); }
        if (sopriteBones.intersects(sopriterestagle1)) { smission.setPosition(200, 500); smission.setTexture(texture2);smission.scale(1.f, 1.f); window.draw(smission); }
        if (sopriteBones.intersects(sopriterestagle2)) { smission.setPosition(500, 400); smission.setTexture(texture); smission.scale(1.f, 1.f); window.draw(smission); }
        window.draw(shape);
        window.draw(sprite2);
        window.draw(sprite);
        window.draw(p.sprite);
        window.display();
    }
}
