#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>
#include <time.h>
#include <cstdlib>
#include <windows.h>
#include <string>
#include <string>
#include <sstream>


//WINDOW
void pollEvents(sf::RenderWindow &pong);
sf::RectangleShape addPaddle(sf::Vector2f pos);
sf::RectangleShape addBlock();
sf::CircleShape addBall(sf::Vector2f pos);
//PADDLE
void paddleControls(sf::RectangleShape &paddle1, sf::RectangleShape &paddle2);
void colision(sf::CircleShape &ball, sf::RectangleShape &paddle1, sf::RectangleShape &paddle2, sf::Vector2f &ballVelocity,
     sf::RenderWindow &pong,unsigned int &points, sf::RectangleShape block);
void paddleColision(sf::CircleShape &ball, sf::RectangleShape &paddle1, sf::RectangleShape &paddle2,
     sf::Vector2f &ballVelocity);
void ballWallColision(sf::CircleShape &ball, sf::RenderWindow &pong, sf::Vector2f &ballVelocity, sf::RectangleShape block);
void ballColisionScore(sf::CircleShape &ball, sf::RenderWindow &pong, sf::Vector2f &ballVelocity,unsigned int &points);
//NPC
void npcAi(sf::CircleShape ball, sf::RectangleShape &paddle2);
//TESTING
void ballControl(sf::CircleShape &ball, sf::RenderWindow &pong, sf::Vector2f &ballVelocity);

//gameinit
void running(unsigned short choice);

void printConfig();

int main(){
    unsigned short choice = -1;
    do{
        std::cout << "\t\tPONG\n\n\t1.1P\n\t2.2P\n\t3.CONTROLS\n\n\t0.EXIT\nchoice >> ";
        std::cin >> choice;
        switch (choice)
        {
            case 1:
            {
                running(choice);
                break;
            }
            case 2:
            {
                running(choice);
                break;
            }
            case 3:
            {
                printConfig();
                break;
            }
            case 0:
            {
                continue;
            }
            default :
            {
                std::cout << "\t\t**WRONG CHOICE**\n";
                Sleep(500);
                break;
            }

        }
        system("cls");
    }while(choice!=0);

    return 0;
}

void pollEvents(sf::RenderWindow &pong)
{
    while(const std::optional event = pong.pollEvent())
    {
        if(event->is<sf::Event::Closed>())
        {
            pong.close();
        }
        else if(auto *keyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            if(keyPressed->scancode == sf::Keyboard::Scancode::Escape)
            {
                pong.close();
            }
            
            
        }
        


    }
}

sf::RectangleShape addPaddle(sf::Vector2f pos)
{
    sf::RectangleShape paddle({7.0f, 70.0f});
    paddle.setOrigin(paddle.getGeometricCenter());
    paddle.setPosition(pos);
    paddle.setFillColor(sf::Color::Cyan);

    return paddle;
}

sf::CircleShape addBall(sf::Vector2f pos)
{

    

    sf::CircleShape ball(6.0f);
    ball.setOrigin(ball.getGeometricCenter());
    ball.setFillColor(sf::Color::Cyan);
    ball.setPosition(pos);


    return ball;
}

void paddleControls(sf::RectangleShape &paddle1, sf::RectangleShape &paddle2 )
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up) && (paddle1.getPosition().y - paddle1.getSize().y/2) > 0.0f)
        {
            paddle1.move({0.0f, -7.0f});
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down) && (paddle1.getPosition().y + paddle1.getSize().y/2) < 450.0f)
        {
            paddle1.move({0.0f, 7.0f});
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W) && (paddle2.getPosition().y - paddle2.getSize().y/2) > 0.0f)
        {
            paddle2.move({0.0f, -7.0f});
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S) && (paddle2.getPosition().y + paddle2.getSize().y/2) < 450.0f)
        {
            paddle2.move({0.0f, 7.0f});
        }
}

void colision(sf::CircleShape &ball, sf::RectangleShape &paddle1, sf::RectangleShape &paddle2, sf::Vector2f &ballVelocity,
                 sf::RenderWindow &pong, unsigned int &points, sf::RectangleShape block)
{
    ballWallColision(ball, pong, ballVelocity, block);
    paddleColision(ball, paddle1, paddle2, ballVelocity);
    ballColisionScore(ball, pong, ballVelocity, points);

    
}
void ballWallColision(sf::CircleShape &ball, sf::RenderWindow &pong, sf::Vector2f &ballVelocity, sf::RectangleShape block)
{
    
    if(ball.getPosition().y >= pong.getSize().y || ball.getPosition().y <= 0)   // Odbicia od górnej i dolnej ściany
        {
            ballVelocity.y = -ballVelocity.y;
        }
    else if(ball.getGlobalBounds().findIntersection(block.getGlobalBounds()) )
    {
        ballVelocity.x = -ballVelocity.x;
    }
        
}

void paddleColision(sf::CircleShape &ball, sf::RectangleShape &paddle1, sf::RectangleShape &paddle2, sf::Vector2f &ballVelocity)
{
    static float multiplier = 1.2f;
    if(ball.getGlobalBounds().findIntersection(paddle1.getGlobalBounds()) || ball.getGlobalBounds().findIntersection(paddle2.getGlobalBounds()))  //kolizja z paletkami gracza
        {
            ballVelocity.x = -ballVelocity.x * multiplier;
        }
       
}

void ballColisionScore(sf::CircleShape &ball, sf::RenderWindow &pong, sf::Vector2f &ballVelocity, unsigned int &points)
{
   
    if (ball.getPosition().x <= 0) {
        ball.setPosition({pong.getSize().x / 2.0f, pong.getSize().y / 2.0f});  // Reset pozycji
        Sleep(600);
        ballVelocity = {5.0f, float(rand()%5+3)};  // Reset prędkości
    }
    else if (ball.getPosition().x >= pong.getSize().x) {
        
        ball.setPosition({pong.getSize().x / 2.0f, pong.getSize().y / 2.0f});  // Reset pozycji
        Sleep(600);
        ballVelocity = {-5.0f, float(rand()%5+3)};  // Reset prędkości
        points++;
    }
}

void ballControl(sf::CircleShape &ball, sf::RenderWindow &pong, sf::Vector2f &ballVelocity)
{

    ballVelocity = {0.0f, 0.0f};
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::O))
    {
        ball.move({0.0f, -5.0f});
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::L))
    {
        ball.move({0.0f, 5.0f});
    }
}

void npcAi(sf::CircleShape ball, sf::RectangleShape &paddle2)
{
    if( paddle2.getPosition().y > ball.getPosition().y && ball.getPosition().x > 800/2 && paddle2.getPosition().y - paddle2.getSize().y/2 > 0 )
    {
                paddle2.move({0.0f, -7.0f});

        
    }
    if(paddle2.getPosition().y < ball.getPosition().y  && ball.getPosition().x > 800/2 && paddle2.getPosition().y+paddle2.getSize().y/2 < 450.0f)
    {              

                paddle2.move({0.0f, 7.0f});
          
        
    }

}
void running(unsigned short choice)
{
    srand(time(NULL));
    ///////////////////////////VARIABLES////////////////////////////
        unsigned int width = 800, height = 450;
        sf::Vector2f player1position = {10.0f,225.0f};
        sf::Vector2f player2position = {790.0f,225.0f};
        sf::Vector2f ballPosition = {float(width/2)+30.0f, float(height/2)};   
        sf::Vector2f ballVelocity = {float((rand()%3+1)+5), float(rand()%3+1)};
        unsigned int points = 0;
        unsigned int randomizeBlockDisplay;
        sf::RectangleShape block;
    
        sf::RenderWindow pong(sf::VideoMode({width, height}), "Pong");
        pong.setFramerateLimit(45);
    
        sf::Font font;
        if(!font.openFromFile("font/ARIAL.TTF"))
        {
            std::cerr << "Could not load font from ./font/ARIAL.TTF" << std::endl;

        }
        std::cout << std::to_string(points);
    
        sf::Text text(font);
        
        text.setFillColor(sf::Color::Cyan);
        text.setCharacterSize(30);
        text.setOrigin(text.getLocalBounds().size / 2.0f);
        text.setPosition({width/2.0f-50.0f , 15.0f});
    
    
        sf::RectangleShape paddle1 = addPaddle(player1position);
        sf::RectangleShape paddle2 = addPaddle(player2position);
        sf::CircleShape ball = addBall(ballPosition);
        
        
    
        while(pong.isOpen())
        {
           
                block = addBlock();
            
            ball.move(ballVelocity);
            std::stringstream sStream;
            sStream << "SCORE " << points;
            text.setString(sStream.str());
            randomizeBlockDisplay = rand()%1000;
    ///////////////////////////////////////////////////////////////TEST//////////////////////
            //ballControl(ball, pong, ballVelocity);
    ///////////////////////////////////////////////////////////////POLL EVENTS////////////////////////////
            pollEvents(pong);
    /////////////////////////////////////////////////////////////KOLIZJE//////////////////////
            colision(ball, paddle1, paddle2, ballVelocity, pong, points, block);
    
    ///////////////////////////////////////////////////////////STEROWANIE/////////////////////
            paddleControls(paddle1, paddle2);
    ///////////////////////////////////////////////////////////////AI///////////////////////////////////////////////
            if(choice == 1)
            {
                npcAi(ball, paddle2);
            }
                
    /////////////////////////////////////////////////////////RENDER AND DRAW///////////////////////////////////////////////////////////
            
    
            pong.clear(sf::Color::Black);
    
            pong.draw(paddle1);
            pong.draw(paddle2);
            pong.draw(ball);
            pong.draw(text);
            if(randomizeBlockDisplay > 800 )
            {
                pong.draw(block);
            }
           
            std::cout << "paletka2> " << paddle2.getPosition().x << "x" << paddle2.getPosition().y 
            <<"\t\tball: " << ball.getPosition().x << "x" << ball.getPosition().y << std::endl;
    
            pong.display();
        }
       
}

void printConfig()
{
    std::cout << " \n\n\t\t UP ARROW-> player1 up\n\t\t DOWN ARROW => player1 down\n\n\t\t W -> player2 up\n\t\tS -> dlayer2 down\n\n";
    system("pause");
}

sf::RectangleShape addBlock()
{

    sf::RectangleShape block({20.0f, 20.0f});
    block.setOrigin(block.getGeometricCenter());
    block.setPosition({float(((rand()%300)+200)), float(rand()%450) });

    return block;
}