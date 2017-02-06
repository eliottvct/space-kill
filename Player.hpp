/********************************************************************************************
 * Project: SpaceKill
 * File: Player.hpp
 * ------------------------------------------------------------------------------------------
 * Authors: Valentin Mancier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include "Ship.hpp"

class Player : public Ship
{
private:

public:
    Player(int x, int y, int w, int h, float x_speed, float y_speed, int health, int styleShot);
    Player();

    void moveP(bool LeftKeyDown1, bool LeftKeyDown2, bool RightKeyDown1, bool RightKeyDown2, bool UpKeyDown1, bool UpKeyDown2, bool DownKeyDown1, bool DownKeyDown2, float timedelta);
};
#endif // PLAYER_HPP_INCLUDED
