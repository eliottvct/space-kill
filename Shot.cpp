/********************************************************************************************
 * Project: SpaceKill
 * File: Shot.cpp
 * ------------------------------------------------------------------------------------------
 * Authors: Valentin Mancier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#include <iostream>
#include "Shot.hpp"
#include "Entities.hpp"

using namespace std;

// -- Shot --------------------------------------
// Builds an object "shot"
// * in-parameters :
// - "style" : number of the ship's shoot's style
// - "x", int : horizontal position of the shot
// - "y", int : vertical position of the shot
// - "xSpeed", float : horizontal speed of the shot
// - "ySpeed", float : horizontal speed of the shot
// ----------------------------------------------
Shot::Shot(int style, int x, int y, float xSpeed, float ySpeed)
{
    m_style = style;
    switch(style)
    {
    case 0:
        m_damage = SHOT_0_DAMAGE;
        break;
    case 1:
        m_damage = SHOT_1_DAMAGE;
        break;
    case 2:
        m_damage = SHOT_2_DAMAGE;
        break;
    case 3:
        m_damage = SHOT_3_DAMAGE;
        break;
    case 4:
        m_damage = SHOT_4_DAMAGE;
        break;
    case 5:
        m_damage = SHOT_5_DAMAGE;
        break;
    }
    m_wS = DEFAULT_SHOT_WIDTH;
    m_hS = DEFAULT_SHOT_HEIGHT;
    m_xS = x-m_wS/2;
    m_yS = y-m_hS/2;
    m_x_speedS = xSpeed;
    m_y_speedS = ySpeed;
}

// -- moveShot ----------------------------------
// Moves the shot
// * in-parameters :
// - "timeldelta", float : time elapsed since the last main game loop turn
// ----------------------------------------------
void Shot::moveShot(float timedelta)
{
    m_xS += m_x_speedS *timedelta;
    m_yS += m_y_speedS *timedelta;
}

// -- getStyle ----------------------------------
// Returns the shoot's style
// * out-parameters :
// - "m_style", int : shot's style
// ----------------------------------------------
int Shot::getStyle() const
{
    return m_style;
}

// -- getDamages --------------------------------
// Returns the shoot's damages
// * out-parameters :
// - "m_damage", int : shot's amount of damages
// ----------------------------------------------
int Shot::getDamages() const
{
    return m_damage;
}

// -- getX --------------------------------------
// Returns the horizontal shoot's position
// * out-parameters :
// - "m_xS", int : horizontal shoot's position
// ----------------------------------------------
int Shot::getX() const
{
    return m_xS;
}

// -- getY --------------------------------------
// Returns the vertical shoot's position
// * out-parameters :
// - "m_yS", int : vertical shoot's position
// ----------------------------------------------
int Shot::getY() const
{
    return m_yS;
}

// -- getW --------------------------------------
// Returns the shot's width
// * out-parameters :
// - "m_wS", int : shot's width
// ----------------------------------------------
int Shot::getW() const
{
    return m_wS;
}

// -- getH --------------------------------------
// Returns the shot's height
// * out-parameters :
// - "m_hS", int : shot's height
// ----------------------------------------------
int Shot::getH() const
{
    return m_hS;
}

// -- getY_speed --------------------------------
// Returns the vertical ship's speed
// * out-parameters :
// - "m_y_speed", int : vertical ship's speed
// ----------------------------------------------
float Shot::getXSpeed() const
{
    return m_x_speedS;
}
