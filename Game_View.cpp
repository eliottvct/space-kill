/********************************************************************************************
 * Project: SpaceKill
 * File: Game_View.cpp
 * ------------------------------------------------------------------------------------------
 * Authors: Valentin Mancier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#include "Game_View.hpp"
#include "Game_Model.hpp"
#include "Entities.hpp"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

using namespace sf;

// -- Game_View ---------------------------------
// Builds the game view
// * in-parameters :
// - w, int : width of the window
// - h, int : height of the window
// - bbp, int : number of bits by pixel
// ----------------------------------------------
Game_View::Game_View(int w, int h, int bpp): _w(w), _h(h)
{
    _window = new RenderWindow(sf::VideoMode(w, h, bpp), "SpaceKill", sf::Style::Resize);
    _window->setVerticalSyncEnabled(false);
    _window->setFramerateLimit(60);
    run= true;

    if (!_background_image.loadFromFile(PATH + "background.jpg") ||
            !_button1_image.loadFromFile(PATH + "button1.png") ||
            !_button2_image.loadFromFile(PATH + "button2.png") ||
            !_headband_image.loadFromFile(PATH + "headband.png") ||
            !_healthbar_image.loadFromFile(PATH + "healthbar.png") ||
            !_player_image.loadFromFile(PATH + "player.png") ||
            !_player1_image.loadFromFile(PATH + "player1.png") ||
            !_player2_image.loadFromFile(PATH + "player2.png") ||
            !_enemy0_image.loadFromFile(PATH + "enemy0.png") ||
            !_enemy1_image.loadFromFile(PATH + "enemy1.png") ||
            !_enemy2_image.loadFromFile(PATH + "enemy2.png") ||
            !_enemy3_image.loadFromFile(PATH + "enemy3.png") ||
            !_enemy4_image.loadFromFile(PATH + "enemy4.png") ||
            !_enemy5_image.loadFromFile(PATH + "enemy5.png") ||
            !_enemy6_image.loadFromFile(PATH + "enemy6.png") ||
            !_enemy7_image.loadFromFile(PATH + "enemy7.png") ||
            !_shot0_image.loadFromFile(PATH + "shot0.png") ||
            !_shot1_image.loadFromFile(PATH + "shot1.png") ||
            !_shot2_image.loadFromFile(PATH + "shot2.png") ||
            !_title_image.loadFromFile(PATH + "title.png") ||
            !_minimal_font.loadFromFile(PATH + "minimal.ttf") ||
            !_transition_image.loadFromFile(PATH + "transition.png") ||
            !_gameover_image.loadFromFile(PATH + "gameover.png") ||
            !_music.openFromFile(PATH + "music.ogg") ||

            !_background_texture.loadFromImage(_background_image) ||
            !_button1_texture.loadFromImage(_button1_image) ||
            !_button2_texture.loadFromImage(_button2_image) ||
            !_headband_texture.loadFromImage(_headband_image) ||
            !_healthbar_texture.loadFromImage(_healthbar_image) ||
            !_player_texture.loadFromImage(_player_image) ||
            !_player1_texture.loadFromImage(_player1_image) ||
            !_player2_texture.loadFromImage(_player2_image) ||
            !_enemy0_texture.loadFromImage(_enemy0_image) ||
            !_enemy1_texture.loadFromImage(_enemy1_image) ||
            !_enemy2_texture.loadFromImage(_enemy2_image) ||
            !_enemy3_texture.loadFromImage(_enemy3_image) ||
            !_enemy4_texture.loadFromImage(_enemy4_image) ||
            !_enemy5_texture.loadFromImage(_enemy5_image) ||
            !_enemy6_texture.loadFromImage(_enemy6_image) ||
            !_enemy7_texture.loadFromImage(_enemy7_image) ||
            !_shot0_texture.loadFromImage(_shot0_image) ||
            !_shot1_texture.loadFromImage(_shot1_image) ||
            !_shot2_texture.loadFromImage(_shot2_image) ||
            !_title_texture.loadFromImage(_title_image) ||
            !_transition_texture.loadFromImage(_transition_image) ||
            !_gameover_texture.loadFromImage(_gameover_image))
    {
        _background_sprite = Sprite();
        _button1_sprite = Sprite();
        _button2_sprite = Sprite();
        _headband_sprite = Sprite();
        _healthbar_sprite = Sprite();
        _player_sprite = Sprite();
        _player1_sprite = Sprite();
        _player2_sprite = Sprite();
        _enemy0_sprite = Sprite();
        _enemy1_sprite = Sprite();
        _enemy2_sprite = Sprite();
        _enemy3_sprite = Sprite();
        _enemy4_sprite = Sprite();
        _enemy5_sprite = Sprite();
        _enemy6_sprite = Sprite();
        _enemy7_sprite = Sprite();
        _shot0_sprite = Sprite();
        _shot1_sprite = Sprite();
        _shot2_sprite = Sprite();
        _title_sprite = Sprite();
        _minimal_font = Font();
        _transition_sprite = Sprite();
        _gameover_sprite = Sprite();
    }
    else
    {
        _y_background = 0;
        _background_sprite = Sprite(_background_texture);
        _background_sprite.setPosition(0,_y_background);

        _button1_sprite = Sprite(_button1_texture);
        _button2_sprite = Sprite(_button2_texture);

        _headband_sprite = Sprite(_headband_texture);
        _healthbar_sprite = Sprite(_healthbar_texture);

        _player_sprite = Sprite(_player_texture);
        _player1_sprite = Sprite(_player1_texture);
        _player2_sprite = Sprite(_player2_texture);
        _enemy0_sprite = Sprite(_enemy0_texture);
        _enemy1_sprite = Sprite(_enemy1_texture);
        _enemy2_sprite = Sprite(_enemy2_texture);
        _enemy3_sprite = Sprite(_enemy3_texture);
        _enemy4_sprite = Sprite(_enemy4_texture);
        _enemy5_sprite = Sprite(_enemy5_texture);
        _enemy6_sprite = Sprite(_enemy6_texture);
        _enemy7_sprite = Sprite(_enemy7_texture);
        _shot0_sprite = Sprite(_shot0_texture);
        _shot1_sprite = Sprite(_shot1_texture);
        _shot2_sprite = Sprite(_shot2_texture);
        _title_sprite = Sprite(_title_texture);
        _transition_sprite = Sprite(_transition_texture);
        _gameover_sprite = Sprite(_gameover_texture);
    }
}

// -- ~Game_View --------------------------------
// Deletes the game view
// ----------------------------------------------
Game_View::~Game_View()
{
    if(_window != NULL)
    {
        delete _window;
    }
}

// -- drawIntro --------------------------------
// Draws the introduction sequence
// * in-parameters :
// - "clock", Clock : current clock
// ----------------------------------------------
void Game_View::drawIntro(Clock clock)
{
    float timedelta;
    Time elapsed;
    float t = 0.0;
    while(t < 500.0)
    {
        _window->clear();
        drawBackground();
        drawAnimation(t);
        drawTitle();
        _window->display();

        elapsed = clock.getElapsedTime();
        timedelta = elapsed.asSeconds();

        t+=timedelta;
    }
}

// -- drawIntro --------------------------------
// Draws the background with a vertical scrolling effect
// ----------------------------------------------
void Game_View::drawBackground()
{

    drawSprite(0,_y_background, MODEL_WIDTH/(_background_sprite.getGlobalBounds().width), MODEL_HEIGHT/(_background_sprite.getGlobalBounds().height),_background_sprite);
    drawSprite(0,-MODEL_HEIGHT+_y_background, MODEL_WIDTH/(_background_sprite.getGlobalBounds().width), MODEL_HEIGHT/(_background_sprite.getGlobalBounds().height),_background_sprite);
    _y_background += 0.8 ;
    if (_y_background >= MODEL_HEIGHT)
    {
        _y_background =0;
    }
}

// -- drawAnimation -----------------------------
// Draws the animation of the introduction sequence
// * in-parameters :
// - "t", float : duration of the animation
// ----------------------------------------------
void Game_View::drawAnimation(float t)
{
    drawSprite(100+t, 540-t, PLAYER_WIDTH/(_player1_sprite.getGlobalBounds().width), PLAYER_HEIGHT/(_player1_sprite.getGlobalBounds().height), _player1_sprite);
    _player1_sprite.setRotation(-50);
//    drawSprite(VIEW_WIDTH-200-t, 650-t, 150/PLAYER_WIDTH, 150/PLAYER_HEIGHT, _player2_sprite);
    drawSprite(VIEW_WIDTH-200-t, 650-t, PLAYER_WIDTH/(_player2_sprite.getGlobalBounds().width), PLAYER_HEIGHT/(_player2_sprite.getGlobalBounds().height), _player2_sprite);
    _player2_sprite.setRotation(50);
}

// -- drawTitle ---------------------------------
// Draws the title during the animation sequence
// ----------------------------------------------
void Game_View::drawTitle()
{
    drawSprite(0, 0, MODEL_WIDTH, MODEL_HEIGHT/5, _title_sprite);
}

// -- drawMenu ----------------------------------
// Draws the menu
// ----------------------------------------------
void Game_View::drawMenu()
{
    _window->clear();
    drawBackground();
    drawTitle();
    drawButtons();
    _window->display();
}

// -- drawButtons -------------------------------
// Draws the buttons of the menu
// ----------------------------------------------
void Game_View::drawButtons()
{
    drawSprite(VIEW_WIDTH/2-(_button1_sprite.getGlobalBounds().width)/2, VIEW_HEIGHT/2, 1.0, 1.0, _button1_sprite);
    _button1_sprite.setPosition(VIEW_WIDTH/2-(_button1_sprite.getGlobalBounds().width)/2, VIEW_HEIGHT/2);
    drawSprite(VIEW_WIDTH/2-(_button2_sprite.getGlobalBounds().width)/2, VIEW_HEIGHT-_button1_sprite.getGlobalBounds().width, 1.0, 1.0, _button2_sprite);
    _button2_sprite.setPosition(VIEW_WIDTH/2-(_button2_sprite.getGlobalBounds().width)/2, VIEW_HEIGHT-_button1_sprite.getGlobalBounds().width);
}

// -- drawGame ----------------------------------
// Draws all the necessary elements for the game
// ----------------------------------------------
void Game_View::drawGame()
{
    _window->clear();
    drawBackground();
    drawPlayerShots();
    drawEnemiesShots();
    drawPlayer();
    drawEnemies();
    drawHeadBand();
    _window->display();
}

// -- drawSprite --------------------------------
// Draws a sprite
// * in-parameters
// - "x", int : horizontal sprite's position
// - "y", int : vertical sprite's position
// - "w", int : width of the sprite
// - "h", int : height of the sprite
// - "mySprite", Sprite : sprite to draw
// ----------------------------------------------
void Game_View::drawSprite(float x, float y, float scaleX, float scaleY, Sprite mySprite)
{
    mySprite.setScale(scaleX, scaleY);
    mySprite.setPosition(x, y);
    _window->draw(mySprite);
}

// -- drawPlayerShots ---------------------------
// Draws the player's shots
// ----------------------------------------------
void Game_View::drawPlayerShots()
{
    sf::Sprite myPlayerShotSprite;
    int x, y, w, h;
    int style;
    for (int i=0; i < (_model->getPlayer())->getShotsSize(); i++)
    {
        style = _model->getPlayer()->getShot(i)->getStyle();
        _model->getPlayer()->getShotSettings(x, y, w, h, i);
        if(style==0 ||style==1)
        {
            myPlayerShotSprite =_shot0_sprite;
        }
        else if (style==2 || style==3)
        {
            myPlayerShotSprite =_shot1_sprite;
        }
        else
        {
            myPlayerShotSprite =_shot2_sprite;
        }
        float xSpeed =_model->getPlayer()->getShot(i)->getXSpeed();
        if(xSpeed>0.0)
        {
            myPlayerShotSprite.setRotation(-45);
        }
        else if (xSpeed<0.0)
        {
            myPlayerShotSprite.setRotation(45);
        }
        drawSprite(x, y, DEFAULT_SHOT_WIDTH/(myPlayerShotSprite.getGlobalBounds().width), DEFAULT_SHOT_HEIGHT/(myPlayerShotSprite.getGlobalBounds().height), myPlayerShotSprite);
    }
}

// -- drawEnemiesShots --------------------------
// Draws the enemies's shots
// ----------------------------------------------
void Game_View::drawEnemiesShots()
{
    int x, y, w, h;
    for(int i=0; i < _model->getEnemiesSize(); i++)
    {
        for(int j=0; j < (_model->getEnemy(i))->getShotsSize(); j++)
        {
            (_model->getEnemy(i))->getShotSettings(x, y, w, h, j);
            Game_View::drawSprite(x, y, DEFAULT_SHOT_WIDTH/(_shot0_sprite.getGlobalBounds().width), DEFAULT_SHOT_HEIGHT/(_shot0_sprite.getGlobalBounds().height), _shot1_sprite);
        }
    }
}

// -- drawPlayer --------------------------------
// Draws the player
// ----------------------------------------------
void Game_View::drawPlayer()
{
    int x, y, w, h;
    _model->getPlayerSettings(x, y, w, h);
    drawSprite(x, y, w/(_player_sprite.getGlobalBounds().width), h/(_player_sprite.getGlobalBounds().height), _player_sprite);
}

// -- drawEnemies -------------------------------
// Draws all the enemies according to their style number
// ----------------------------------------------
void Game_View::drawEnemies()
{
    int style = _model->getLevelNumber()%LEVELS;
    switch(style)
    {
    case 0:
        Game_View::drawEnemiesSprites(_enemy0_sprite);
        break;
    case 1:
        Game_View::drawEnemiesSprites(_enemy1_sprite);
        break;
    case 2:
        Game_View::drawEnemiesSprites(_enemy2_sprite);
        break;
    case 3:
        Game_View::drawEnemiesSprites(_enemy3_sprite);
        break;
    case 4:
        Game_View::drawEnemiesSprites(_enemy4_sprite);
        break;
    case 5:
        Game_View::drawEnemiesSprites(_enemy5_sprite);
        break;
    case 6:
        Game_View::drawEnemiesSprites(_enemy6_sprite);
        break;
    case 7:
        Game_View::drawEnemiesSprites(_enemy7_sprite);
        break;
    default:
        break;
    }
}

// -- drawEnemiesSprites ------------------------
// Draws the enemies's sprites
// * in-parameters :
// - "myEnemeySprite", Sprite : sprite of the enemy to draw
// ----------------------------------------------
void Game_View::drawEnemiesSprites(Sprite myEnemySprite)
{
    int x, y, w, h;
    for (int i=0; i < _model->getEnemiesSize(); i++)
    {
        _model->getEnemySettings(x, y, w, h, i);
        Game_View::drawSprite(x, y, DEFAULT_ENEMY_WIDTH/(myEnemySprite.getGlobalBounds().width), DEFAULT_ENEMY_HEIGHT/(myEnemySprite.getGlobalBounds().height), myEnemySprite);
    }
}

// -- drawHeadBand ------------------------------
// Draws the headband (life, level of life and score)
// ----------------------------------------------
void Game_View::drawHeadBand()
{
    drawSprite(0, 0, VIEW_WIDTH/(_headband_sprite.getGlobalBounds().width), 20/(_headband_sprite.getGlobalBounds().height), _headband_sprite);
    drawLife();
    drawHealth();
    drawScore();
}

// -- drawLife ----------------------------------
// Draws the player's number of life according to his life number
// ----------------------------------------------
void Game_View::drawLife()
{
    int lifeNumber = (_model->getPlayer())->getLife();
    switch (lifeNumber)
    {
    case 1:
        drawSprite(2, 0, 19, 19, _player_sprite);
        break;
    case 2:
        drawSprite(2, 0, 19, 19, _player_sprite);
        drawSprite(27, 0, 19, 19, _player_sprite);
        break;
    case 3:
        drawSprite(2, 0, 19, 19, _player_sprite);
        drawSprite(27, 0, 19, 19, _player_sprite);
        drawSprite(52, 0, 19, 19, _player_sprite);
        break;
    default:
        break;
    }
}

// -- drawHealth --------------------------------
// Draws the player's level of life according to his health level
// ----------------------------------------------
void Game_View::drawHealth()
{
    float lifeLevel = (_model->getPlayer()->getCurrentHealth()/_model->getPlayer()->getHealthMax())*100;
    if (lifeLevel == 0.0)
    {
        lifeLevel = 100.0;
    }
    drawHealthLevel(2*lifeLevel-1);
}

// -- drawHealthLevel ---------------------------
// Draws the player's level of life according to his health level
// * in-parameters :
// - "x", float : player's health
// ----------------------------------------------
void Game_View::drawHealthLevel(float x)
{
    _healthbar_sprite.setTextureRect(sf::IntRect(0, 0, (int) x, 10));
    drawSprite(100, 5, x/(_headband_sprite.getGlobalBounds().width), 10/(_headband_sprite.getGlobalBounds().height), _healthbar_sprite);
}

// -- to_string ---------------------------------
// Converts an int to a string
// * out-parameters :
// - "oss", ostringstream
// ----------------------------------------------
template <typename T>
std::string to_string(T value)
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

// -- drawScore ---------------------------------
// Draws the player's score
// ----------------------------------------------
void Game_View::drawScore()
{
    std::string str = "Score : ";
    str += to_string(_model->getScore());

    _score_string.setString(str);
    _score_string.setFont(_minimal_font);
    _score_string.setScale(20, 20);
    _score_string.setPosition(310, -5);
    _score_string.setFillColor(sf::Color(0, 0, 0));
    _window->draw(_score_string);
}

// -- treatEvents -------------------------------
// Treat the game's events
// ----------------------------------------------
bool Game_View::treatEvents(float timedelta)
{
    if(_window->isOpen()&& run)
    {
        Event event;
        _window->pollEvent(event);

        bool EscapeKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
        bool LeftKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
        bool RightKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
        bool UpKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
        bool DownKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
        bool ZKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
        bool QKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
        bool SKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
        bool DKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::D);

        if (EscapeKeyDown)
        {
            _window->close();
            run = false;
        }
        (_model->getPlayer())->moveP(LeftKeyDown, QKeyDown, RightKeyDown, DKeyDown, UpKeyDown, ZKeyDown, DownKeyDown, SKeyDown, timedelta);
    }
    return run;
}

// -- treatMenuEvents ---------------------------
// Treat the game's events
// ----------------------------------------------
bool Game_View::treatMenuEvents()
{
    bool runMenu = true;
    sf::Event _menu_event;
    _window->pollEvent(_menu_event);

    bool LeftMouseKeyDown = sf::Mouse::isButtonPressed(sf::Mouse::Left);
    bool EscapeKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);

    if ((LeftMouseKeyDown) && (_menu_event.mouseButton.x > _button1_sprite.getPosition().x)
         && (_menu_event.mouseButton.x < (_button1_sprite.getTextureRect().width)+(_button1_sprite.getPosition().x))
         && (_menu_event.mouseButton.y > _button1_sprite.getPosition().y)
         && (_menu_event.mouseButton.y < (_button1_sprite.getTextureRect().height)+(_button1_sprite.getPosition().y)))
    {
        runMenu = false;
    }
    if ((LeftMouseKeyDown) && (_menu_event.mouseButton.x > _button2_sprite.getPosition().x)
        && (_menu_event.mouseButton.x < (_button2_sprite.getTextureRect().width)+(_button2_sprite.getPosition().x))
        && (_menu_event.mouseButton.y > _button2_sprite.getPosition().y)
        && (_menu_event.mouseButton.y < (_button2_sprite.getTextureRect().height)+(_button2_sprite.getPosition().y)))
    {
        _window->close();
        run = false;
    }
    if (EscapeKeyDown)
    {
        _window->close();
        run = false;
    }
    return runMenu;
}

// -- setModel ----------------------------------
// Sets the model
// ----------------------------------------------
void Game_View::setModel(Game_Model *model)
{
    _model = model;
}

// -- playMusic ---------------------------------
// Plays the music theme during the game
// * in-parameters :
// - "loop", bool : says if the music has to play in loop or not
// ----------------------------------------------
void Game_View::playMusic(bool loop)
{
    if(loop)
    {
        _music.setLoop(true);
    }
    _music.setVolume(10.0);
    _music.play();
}

// -- drawTransition ----------------------------
// Draws the transition when a level is changing
// * in-parameters :
// - "m_clock", Clock
// ----------------------------------------------
void Game_View::drawTransition(sf::Clock m_clock)
{
    bool levelchange = _model->getLevelChange();
    Time elapsed;
    if(levelchange)
    {
        _model->setLevelChange(false);
        float time;
        float duration = 50.0;
        float timetogo = duration;
        while(timetogo > 0.0)
        {
            elapsed = m_clock.getElapsedTime();
            time = elapsed.asSeconds();

            drawSprite(0, 0, VIEW_WIDTH, VIEW_HEIGHT, _transition_sprite);
            _window->display();
            timetogo -= time;
        }
    }
}

// -- drawGameOver ------------------------------
// Draws the "Game Over" screen when the player is dead
// ----------------------------------------------
void Game_View::drawGameOver()
{
    bool dead = _model->getPlayer()->die();
    sf::Event _gameover_event;

    if(dead)
    {
        while(run)
        {
            drawSprite(0, 0, VIEW_WIDTH/(_gameover_sprite.getGlobalBounds().width), VIEW_HEIGHT/(_gameover_sprite.getGlobalBounds().height), _gameover_sprite);
            _window->display();

            _window->pollEvent(_gameover_event);

            bool EscapeKeyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
            if (EscapeKeyDown)
            {
                _window->close();
                run =false;
            }
        }
    }
}
