/********************************************************************************************
 * Project: SpaceKill
 * File: Ship.hpp
 * ------------------------------------------------------------------------------------------
 * Authors: Valentin Mancier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#ifndef SHIP_HPP_INCLUDED
#define SHIP_HPP_INCLUDED

#include "Entities.hpp"
#include "Shot.hpp"
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Shot;

class Ship
{
protected:
    int m_x;
    int m_y;
    int m_w;
    int m_h;
    int m_direction;
    float m_x_speed;
    float m_y_speed;
    float m_healthMax;
    float m_currentHealth;
    int m_styleShot;
    float m_fireRate;
    float m_elapsedTime;
    int m_life;
    std::vector <Shot*> shots;

    sf::SoundBuffer _shot_buffer;
    sf::Sound _shot_sound;
public:
    Ship();
    Ship(int x, int y, int w, int h, float x_speed, float y_speed, int health,int styleShot);
    ~Ship();

    void loseLife(int damages);
    bool die();
    void moveShotsShip(float timedelta);
    void shoot(float timedelta, int speed);
    void playShotSound();

    void setX(int x);
    void setY(int y);
    void setStyleShot(int styleShot);
    Shot* getShot(int nb);
    void eraseShot(int nb);
    void getShotSettings(int &x, int &y, int &w, int &h, int i) const;
    int getShotsSize() const;
    int getLife() const;
    float getHealthMax() const;
    float getCurrentHealth() const;
    int getX() const;
    int getY() const;
    int getW() const;
    int getH() const;
    int getX_speed() const;
    int getY_speed() const;
    int getStyleShot() const;
};
#endif // SHIP_HPP_INCLUDED
