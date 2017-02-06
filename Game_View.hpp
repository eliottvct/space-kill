/********************************************************************************************
 * Project: SpaceKill
 * File: Game_View.hpp
 * ------------------------------------------------------------------------------------------
 * Authors: Valentin Mancier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#ifndef GAME_VIEW_HPP_INCLUDED
#define GAME_VIEW_HPP_INCLUDED
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Game_Model;

class Game_View
{
private:
    int _w, _h;
    float _y_background;
    bool run;

    sf::RenderWindow * _window;

    sf::Image _background_image;
    sf::Image _button1_image;
    sf::Image _button2_image;
    sf::Image _headband_image;
    sf::Image _healthbar_image;
    sf::Image _player_image;
    sf::Image _player1_image;
    sf::Image _player2_image;
    sf::Image _enemy0_image;
    sf::Image _enemy1_image;
    sf::Image _enemy2_image;
    sf::Image _enemy3_image;
    sf::Image _enemy4_image;
    sf::Image _enemy5_image;
    sf::Image _enemy6_image;
    sf::Image _enemy7_image;
    sf::Image _shot0_image;
    sf::Image _shot1_image;
    sf::Image _shot2_image;
    sf::Image _title_image;
    sf::Image _transition_image;
    sf::Image _gameover_image;

    sf::Texture _background_texture;
    sf::Texture _button1_texture;
    sf::Texture _button2_texture;
    sf::Texture _headband_texture;
    sf::Texture _healthbar_texture;
    sf::Texture _player_texture;
    sf::Texture _player1_texture;
    sf::Texture _player2_texture;
    sf::Texture _enemy0_texture;
    sf::Texture _enemy1_texture;
    sf::Texture _enemy2_texture;
    sf::Texture _enemy3_texture;
    sf::Texture _enemy4_texture;
    sf::Texture _enemy5_texture;
    sf::Texture _enemy6_texture;
    sf::Texture _enemy7_texture;
    sf::Texture _shot0_texture;
    sf::Texture _shot1_texture;
    sf::Texture _shot2_texture;
    sf::Texture _title_texture;
    sf::Texture _transition_texture;
    sf::Texture _gameover_texture;

    sf::Sprite _background_sprite;
    sf::Sprite _button1_sprite;
    sf::Sprite _button2_sprite;
    sf::Sprite _headband_sprite;
    sf::Sprite _healthbar_sprite;
    sf::Sprite _player_sprite;
    sf::Sprite _player1_sprite;
    sf::Sprite _player2_sprite;
    sf::Sprite _enemy0_sprite;
    sf::Sprite _enemy1_sprite;
    sf::Sprite _enemy2_sprite;
    sf::Sprite _enemy3_sprite;
    sf::Sprite _enemy4_sprite;
    sf::Sprite _enemy5_sprite;
    sf::Sprite _enemy6_sprite;
    sf::Sprite _enemy7_sprite;
    sf::Sprite _shot0_sprite;
    sf::Sprite _shot1_sprite;
    sf::Sprite _shot2_sprite;
    sf::Sprite _title_sprite;
    sf::Sprite _transition_sprite;
    sf::Sprite _gameover_sprite;

    sf::Font _minimal_font;
    sf::Text _score_string;
    sf::Music _music;

    Game_Model *_model;

public:
    Game_View(int w, int h, int bpp);
    ~Game_View();

    void drawSprite(float x, float y, float w, float h, sf::Sprite mySprite);

    /** Introduction **/
    void drawIntro(sf::Clock clock);
    void drawBackground();
    void drawAnimation(float t);
    void drawTitle();

    /** Menu **/
    void drawMenu();
    void drawButtons();

    /** Game **/
    void drawGame();
    void drawPlayerShots();
    void drawEnemiesShots();
    void drawPlayer();
    void drawEnemies();
    void drawEnemiesSprites(sf::Sprite);
    void drawHeadBand();
    void drawLife();
    void drawHealth();
    void drawHealthLevel(float x);
    void drawScore();
    void drawTransition(sf::Clock m_clock);
    void drawGameOver();

    bool treatEvents(float timedelta);
    bool treatMenuEvents();
    void setModel(Game_Model *model);
    void playMusic(bool loop);
};

#endif // GAME_VIEW_HPP_INCLUDED
