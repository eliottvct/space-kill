/********************************************************************************************
 * Project: SpaceKill
 * File: Enemy.cpp
 * ------------------------------------------------------------------------------------------
 * Authors: Valentin Mancier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#include <iostream>
#include "Enemy.hpp"
#include "Entities.hpp"

using namespace std;

// -- Enemy -------------------------------------
// Builds an object "enemy" depending of his style
// * in-parameters :
// - "x", int : horizontal position of the enemy
// - "style", int : number of the enemy's style
// ----------------------------------------------
Enemy::Enemy(int x, int style)
{
    m_style = style;
    m_elapsedTime=0;
    m_direction=DEFAULT_ENEMY_DIRECTION;
    m_fireRate = DEFAULT_ENEMY_FIRERATE;
    switch(style)
    {
    case 0:
        Enemy::setEnemySettings( COEF_0);
        break;
    case 1:
        Enemy::setEnemySettings( COEF_1);
        break;
    case 2:
        Enemy::setEnemySettings( COEF_2);
        break;
    case 3:
        Enemy::setEnemySettings( COEF_3);
        break;
    case 4:
        Enemy::setEnemySettings( COEF_4);
        break;
    case 5:
        Enemy::setEnemySettings( COEF_5);
        break;
    case 6:
        Enemy::setEnemySettings( COEF_6);
        break;
    case 7:
        Enemy::setEnemySettings( COEF_7);
        break;
    }
    m_x = x;
    m_currentHealth=m_healthMax;
}

// -- setEnemySettings --------------------------
// Set the enemies's parameters
// * in-parameter :
// - "coef", float : determinates the enemies's difficulty
// ----------------------------------------------
void Enemy::setEnemySettings(float coef)
{
    m_x_speed = DEFAULT_ENEMY_X_SPEED*coef;
    m_y_speed = DEFAULT_ENEMY_X_SPEED*coef;
    m_healthMax = DEFAULT_ENEMY_HEALTH*coef;
    m_life =1;
    m_styleShot = DEFAULT_ENEMY_STYLESHOT*coef;
    m_value = DEFAULT_ENEMY_VALUE*coef;
    m_w = DEFAULT_ENEMY_WIDTH;
    m_h = DEFAULT_ENEMY_HEIGHT;
    m_y = (-m_h);
}

// -- moveForward -------------------------------
// Moves the enemy forward
// * in-parameters :
// - "timeldelta", float : time elapsed since the last main game loop turn
// ----------------------------------------------
void Enemy::moveForward(float timedelta)
{
    m_y += m_y_speed*timedelta;
}

// -- getStyle ----------------------------------
// Gets the number of the enemy's style
// * out-parameters :
// - "m_style", int : number of the enemy's style
// ----------------------------------------------
int Enemy::getStyle() const
{
    return m_style;
}

// -- getValue ----------------------------------
// Gets the number of the enemy's value
// * out-parameters :
// - "m_value", int : number of the enemy's value
// ----------------------------------------------
int Enemy::getValue() const
{
    return m_value;
}
