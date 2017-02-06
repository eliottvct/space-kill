/********************************************************************************************
 * Project: SpaceKill
 * File: Shot.hpp
 * ------------------------------------------------------------------------------------------
 * Authors: Valentin Mancier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#ifndef SHOT_HPP_INCLUDED
#define SHOT_HPP_INCLUDED

class Shot
{
private:
    int m_xS;
    int m_yS;
    int m_wS;
    int m_hS;
    float m_x_speedS;
    float m_y_speedS;
    int m_style;
    float m_damage;

public:
    Shot(int style, int x, int y, float xSpeed, float ySpeed);

    void shotSettings(int style, int x, int y,float xSpeed, float ySpeed);
    void moveShot(float timedelta);

    int getStyle() const;
    int getDamages() const;
    int getX()const;
    int getY()const;
    int getW()const;
    int getH()const;
    float getXSpeed() const;
};

#endif // SHOT_HPP_INCLUDED
