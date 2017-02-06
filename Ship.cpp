/********************************************************************************************
 * Project: SpaceKill
 * File: Ship.cpp
 * ------------------------------------------------------------------------------------------
 * Authors: Valentin Mancier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#include <iostream>
#include "Ship.hpp"

using namespace std;

// -- Ship --------------------------------------
// Builds by default an object "ship"
// ----------------------------------------------
Ship::Ship()
{
    m_x = 200;
    m_y = 10;
    m_w = 1;
    m_h = 1;
    m_x_speed = 20.0;
    m_y_speed = 0;
    m_healthMax = 100;
}

// -- Ship --------------------------------------
// Builds an object "ship"
// * in-parameters :
// - "x", int : horizontal position of the ship
// - "y", int : vertical position of the ship
// - "w", int : width of the ship
// - "h", int : height of the ship
// - "x_speed", float : horizontal speed of the ship
// - "y_speed", float : horizontal speed of the ship
// - "health", int : level of the ship's health
// - "styleShot" : number of the ship's shoot's style
// ----------------------------------------------
Ship::Ship(int x, int y, int w, int h, float x_speed, float y_speed, int health, int styleShot)
    : m_x(x), m_y(y), m_w(w), m_h(h), m_x_speed(x_speed), m_y_speed(y_speed), m_healthMax(health), m_styleShot(styleShot)
{
    m_fireRate = DEFAULT_SHOT_FIRERATE;
    m_currentHealth = m_healthMax;
}

// -- ~Ship -------------------------------------
// Deletes the object "ship"
// ----------------------------------------------
Ship::~Ship()
{
    for(unsigned int i = 0; i<shots.size(); i++)
    {
        delete shots[i];
        shots.clear();
    }
}

// -- loseLife ----------------------------------
// Makes the ship lose a part of his life
// * in-parameters :
// - "damages", int : amount of damages
// ----------------------------------------------
void Ship::loseLife(int damages)
{
    if (m_currentHealth > damages)
    {
        m_currentHealth = m_currentHealth-damages;
    }
    else if (m_currentHealth <= damages)
    {
        m_currentHealth = m_healthMax;
        m_life--;
    }
    if (m_styleShot>=1)
    {
        m_styleShot--;
    }
}

// -- die ---------------------------------------
// Makes the ship die
// ----------------------------------------------
bool Ship::die()
{
    if (m_life <= 0)
    {
        return true;
    }
    return false;
}

// -- moveShotsShip -----------------------------
// Moves the ship's shots
// - "timeldelta", float : time elapsed since the last main game loop turn
// ----------------------------------------------
void Ship::moveShotsShip(float timedelta)
{
    for(unsigned int i=0; i<shots.size(); i++)
    {
        shots[i]->moveShot(timedelta);
        if ( shots[i]->getX()< 0 || (shots[i]->getX())> MODEL_WIDTH || shots[i]->getY()< 0 || shots[i]->getY()> MODEL_HEIGHT)
        {
            delete shots[i];
            shots.erase(shots.begin()+i);
        }
    }
}

// -- shoot -------------------------------------
// Makes the ship shoot according to the style of shot
// * in-parameters :
// - "timeldelta", float : time elapsed since the last main game loop turn
// ----------------------------------------------
void Ship::shoot(float timedelta, int speed)
{
    m_elapsedTime += timedelta;
    if (m_elapsedTime>m_fireRate)
    {
        playShotSound();
        switch(m_styleShot)
        {
        case 0:
        {
            Shot* shot0 = new Shot(0, m_x+m_w/2, m_y+m_h/3, 0, m_direction*speed);
            shots.push_back(shot0);
        }
        break;
        case 1:
        {
            Shot* shot1 = new Shot(1, m_x+m_w/2, m_y+m_h/3,0 , m_direction*speed);
            shots.push_back(shot1);
        }
        break;
        case 2:
        {
            Shot* shot2 = new Shot(1, m_x+m_w/2, m_y+m_h/3, 0, m_direction*speed);
            shots.push_back(shot2);
            Shot* shotLeft2 = new Shot(2, m_x, m_y+m_h/2, 0, m_direction*speed);
            shots.push_back(shotLeft2);
            Shot* shotRight2 = new Shot(2, m_x+m_w, m_y+m_h/2, 0, m_direction*speed);
            shots.push_back(shotRight2);
        }
        break;
        case 3:
        {
            Shot* shot3 = new Shot(2, m_x+m_w/2, m_y+m_h/3, 0, m_direction*speed);
            shots.push_back(shot3);
            Shot* shotLeft3 = new Shot(3, m_x, m_y+m_h/2,0, m_direction*speed);
            shots.push_back(shotLeft3);
            Shot* shotRight3 = new Shot(3, m_x+m_w, m_y+m_h/2, 0, m_direction*speed);
            shots.push_back(shotRight3);
        }
        break;
        case 4:
        {
            Shot* shot4 = new Shot(3, m_x+m_w/2, m_y+m_h/3, 0, m_direction*speed);
            shots.push_back(shot4);
            Shot* shotLeftD4 = new Shot(4, m_x-10, m_y+m_h/2, m_direction*speed, m_direction*speed);
            shots.push_back(shotLeftD4);
            Shot* shotRightD4 = new Shot(4, m_x+m_w+10, m_y+m_h/2, -m_direction*speed, m_direction*speed);
            shots.push_back(shotRightD4);
        }
        break;
        case 5:
        {
            Shot* shot5 = new Shot(3, m_x+m_w/2, m_y+m_h/3, 0, m_direction*speed);
            shots.push_back(shot5);
            Shot* shotLeft5 = new Shot(4, m_x, m_y+m_h/2, 0, m_direction*speed);
            shots.push_back(shotLeft5);
            Shot* shotRight5 = new Shot(4, m_x+m_w, m_y+m_h/2, 0, m_direction*speed);
            shots.push_back(shotRight5);
            Shot* shotLeftD5 = new Shot(5, m_x-10, m_y+m_h/2, m_direction*speed, m_direction*speed);
            shots.push_back(shotLeftD5);
            Shot* shotRightD5 = new Shot(5, m_x+m_w+10, m_y+m_h/2, -m_direction*speed, m_direction*speed);
            shots.push_back(shotRightD5);
        }
        break;
        }
        m_elapsedTime=0;
    }
}

// -- playShotSound -----------------------------
// Plays a fire sound when ships are shooting
// ----------------------------------------------
void Ship::playShotSound()
{
    _shot_buffer.loadFromFile(PATH + "shot.ogg");
    _shot_sound.setBuffer(_shot_buffer);
    _shot_sound.setVolume(3.0);
    _shot_sound.play();
}

// -- setX --------------------------------------
// Sets the horizontal ship's position
// ----------------------------------------------
void Ship::setX(int x)
{
    m_x = x;
}

// -- setY --------------------------------------
// Sets the vertical ship's position
// ----------------------------------------------
void Ship::setY(int y)
{
    m_y = y;
}

// -- setStyleShot ------------------------------
// Sets the ship's style of shot
// ----------------------------------------------
void Ship::setStyleShot(int styleShot)
{
    if(styleShot<=0)
    {
        m_styleShot=0;
    }
    else if(styleShot>=5)
    {
        m_styleShot=5;
    }
    else
    {
        m_styleShot=styleShot;
    }
}

// -- getShot -----------------------------------
// Returns a specified shot
// * in-parameters :
// "nb", int : index of the shot to get
// * out-parameters :
// - "shots[nb]", vector : Shot*
// ----------------------------------------------
Shot* Ship::getShot(int nb)
{
    return shots[nb];
}

// -- getShotSettings ---------------------------
// Return the shot's position and size
// * in-parameters :
// - "x", int : horizontal shot's position
// - "y", int : vertical shot's position
// - "w", int : shot's width
// - "h", int : shot's height
// - "i", int : index of the shot to get
// ----------------------------------------------
void Ship::getShotSettings(int &x, int &y, int &w, int &h, int i) const
{
    x = shots[i]->getX();
    y = shots[i]->getY();
    w = shots[i]->getW();
    h = shots[i]->getH();
}

// -- getShotsSize ------------------------------
// Returns the size of the vector "shots", so the number of shots
// * out-paramters :
// - "shots.size", int : number of shots in the "shots" vector
// ----------------------------------------------
int Ship::getShotsSize() const
{
    return shots.size();
}

// -- eraseShot ---------------------------------
// Erases a shot
// * in-parameters :
// - "nb", int : index of the shot delete
// ----------------------------------------------
void Ship::eraseShot(int nb)
{
    shots.erase(shots.begin()+nb);
}

// -- getLife -----------------------------------
// Returns the ship's life
// * out-parameters :
// - "m_life", int : ship's life
// ----------------------------------------------
int Ship::getLife() const
{
    return m_life;
}

// -- getCurrentHealth --------------------------
// Returns the ship's current health
// * out-parameters :
// - "m_CurrentHealth", int : ship's health
// ----------------------------------------------
float Ship::getCurrentHealth() const
{
    return m_currentHealth;
}

// -- getHealthMax ------------------------------
// Returns the ship's maximum health
// * out-parameters :
// - "m_healthMax", int : ship's maximum health
// ----------------------------------------------
float Ship::getHealthMax() const
{
    return m_healthMax;
}


// -- getX --------------------------------------
// Returns the horizontal ship's position
// * out-parameters :
// - "m_x", int : horizontal ship's position
// ----------------------------------------------
int Ship::getX() const
{
    return m_x;
}

// -- getY --------------------------------------
// Returns the vertical ship's position
// * out-parameters :
// - "m_y", int : vertical ship's position
// ----------------------------------------------
int Ship::getY() const
{
    return m_y;
}

// -- getW --------------------------------------
// Returns the ship's width
// * out-parameters :
// - "m_w", int : ship's width
// ----------------------------------------------
int Ship::getW() const
{
    return m_w;
}

// -- getH --------------------------------------
// Returns the ship's height
// * out-parameters :
// - "m_h", int : ship's height
// ----------------------------------------------
int Ship::getH() const
{
    return m_h;
}

// -- getX_speed --------------------------------
// Returns the horizontal ship's speed
// * out-parameters :
// - "m_x_speed", int : horizontal ship's speed
// ----------------------------------------------
int Ship::getX_speed() const
{
    return m_x_speed;
}

// -- getY_speed --------------------------------
// Returns the vertical ship's speed
// * out-parameters :
// - "m_y_speed", int : vertical ship's speed
// ----------------------------------------------
int Ship::getY_speed() const
{
    return m_y_speed;
}

// -- getStyleShot ------------------------------
// Returns the ship's style
// * out-parameters :
// - "m_styleShot", int : ship's style
// ----------------------------------------------
int Ship::getStyleShot() const
{
    return m_styleShot;
}
