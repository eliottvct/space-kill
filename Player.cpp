/********************************************************************************************
 * Project: SpaceKill
 * File: Player.cpp
 * ------------------------------------------------------------------------------------------
 * Authors: Valentin Mancier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#include <iostream>
#include "Player.hpp"
#include "Ship.hpp"
#include "Game_View.hpp"

using namespace std;

using namespace sf;

// -- Player -------------------------------------
// Builds an object "player"
// * in-parameters :
// - "x", int : horizontal position of the player
// - "y", int : vertical position of the player
// - "w", int : width of the player
// - "h", int : height of the player
// - "x_speed", float : horizontal speed of the player
// - "y_speed", float : horizontal speed of the player
// - "health", int : level of the player's health
// - "styleShot" : number of the player's shoot's style
// ----------------------------------------------
Player::Player(int x, int y, int w, int h, float x_speed, float y_speed, int health, int styleShot)
    :Ship(x, y, w, h, x_speed, y_speed, health, styleShot)
{
    m_life = DEFAULT_PLAYER_LIFE;
    m_direction=DEFAULT_PLAYER_DIRECTION;
    m_elapsedTime=0;
    m_fireRate = DEFAULT_PLAYER_FIRERATE;
}

// -- moveP -------------------------------------
// Moves the player
// * in-parameters :
// - "LeftKeyDown1", bool : the left arrow key
// - "LeftKeyDown2", bool : the 'q' key
// - "RightKeyDown1", bool : the right arrow key
// - "RightKeyDown2", bool : the 'd' key
// - "UpKeyDown1", bool : the up arrow key
// - "UpKeyDown2", bool : the 'z' key
// - "DownKeyDown1", bool : the down arrow key
// - "DownKeyDown2", bool : the 's' key
// - "timeldelta", float : time elapsed since the last main game loop turn
// ----------------------------------------------
void Player::moveP(bool LeftKeyDown1, bool LeftKeyDown2, bool RightKeyDown1, bool RightKeyDown2, bool UpKeyDown1, bool UpKeyDown2, bool DownKeyDown1, bool DownKeyDown2, float timedelta)
{
    if (LeftKeyDown1 || LeftKeyDown2)
    {
        if (m_x-m_x_speed*timedelta > 0)
        {
            setX(m_x-m_x_speed*timedelta);
        }
        else if(m_x-m_x_speed*timedelta < 0)
        {
            setX(0);
        }
    }
    if (RightKeyDown1 || RightKeyDown2)
    {
        int limit = m_x+m_w+m_x_speed*timedelta;
        if (limit < MODEL_WIDTH)
        {
            setX(m_x+m_x_speed*timedelta);
        }
        else if(limit> MODEL_WIDTH)
        {
            setX(MODEL_WIDTH-m_w);
        }
    }
    if(UpKeyDown1 || UpKeyDown2)
    {
        if (m_y-m_y_speed*timedelta > 0)
        {
            setY(m_y-m_y_speed*timedelta);
        }
        else if (m_y-m_y_speed*timedelta < 0)
        {
            setY(0);
        }
    }
    if(DownKeyDown1 || DownKeyDown2)
    {
        int limit = m_y+m_h+m_y_speed*timedelta;
        if (limit < MODEL_HEIGHT)
        {
            setY(m_y+m_y_speed*timedelta);
        }
        else if (limit > MODEL_HEIGHT)
        {
            setY(MODEL_HEIGHT -m_h);
        }
    }
}
