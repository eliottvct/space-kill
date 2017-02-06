/********************************************************************************************
 * Project: SpaceKill
 * File: Enemy.hpp
 * ------------------------------------------------------------------------------------------
 * Authors: Valentin Mancier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#ifndef ENEMY_HPP_INCLUDED
#define ENEMY_HPP_INCLUDED
#include "Ship.hpp"

class Enemy : public Ship
{
private:
    int m_style;
    int m_value;    //number of points earned by the player when the ennemy is killed

public:
    Enemy(int x, int style);

    void setEnemySettings(float coef);
    void moveForward(float timedelta);

    int getStyle() const;
    int getValue() const;
};

#endif // ENEMY_HPP_INCLUDED
