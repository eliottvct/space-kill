/********************************************************************************************
 * Project: SpaceKill
 * File: Entities.hpp
 * ------------------------------------------------------------------------------------------
 * Authors: Valentin Mancier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#include <string>

#ifndef ENTITIES_HPP_INCLUDED
#define ENTITIES_HPP_INCLUDED

/************* GAME_MODEL ************/
const int MODEL_WIDTH = 880;
const int MODEL_HEIGHT = 1440;
const std::string PATH = "/Users/eliottvincent/Desktop/Projets IUT/SpaceKillMac/assets/";

/************* GAME_VIEW ************/
const int VIEW_WIDTH = 880;
const int VIEW_HEIGHT = 1440;
const int VIEW_BPP = 32;
const int LEVELS = 8;
const int LEVEL_DURATION = 30.0;
const float SPAWNRATE_0 = 2.0;
const float SPAWNRATE_1 = 1.75;
const float SPAWNRATE_2 = 1.5;
const float SPAWNRATE_3 = 1.25;
const float SPAWNRATE_4 = 1.0;
const float SPAWNRATE_5 = 0.75;
const float SPAWNRATE_6 = 0.5;
const float SPAWNRATE_7 = 0.3;

/************* PLAYER ************/
const int PLAYER_WIDTH = 30;
const int PLAYER_HEIGHT = 50;
const float PLAYER_X_SPEED = 300.0;
const float PLAYER_Y_SPEED = 300.0;
const int DEFAULT_PLAYER_DIRECTION = -1;
const int DEFAULT_PLAYER_LIFE = 3;
const int PLAYER_HEALTH = 300;
const int PLAYER_SHOT_SPEED = 500;
const float DEFAULT_PLAYER_FIRERATE = 0.5;

/************* ENEMY ************/
const int DEFAULT_ENEMY_WIDTH = 30;
const int DEFAULT_ENEMY_HEIGHT = 50;
const float DEFAULT_ENEMY_X_SPEED = 50.0;
const float DEFAULT_ENEMY_Y_SPEED = 85.0;
const int DEFAULT_ENEMY_HEALTH = 100;
const int DEFAULT_ENEMY_STYLESHOT = 1;
const int DEFAULT_ENEMY_VALUE = 10;
const float COEF_0 = 1.4;
const float COEF_1 = 1.6;
const float COEF_2 = 1.8;
const float COEF_3 = 2.0;
const float COEF_4 = 2.2;
const float COEF_5 = 2.4;
const float COEF_6 = 2.6;
const float COEF_7 = 2.8;
const int DEFAULT_ENEMY_DIRECTION = 1;
const int ENEMY_SHOT_SPEED = 300;
const float DEFAULT_ENEMY_FIRERATE = 2.0;

/************* SHOTS ************/
const int DEFAULT_SHOT_WIDTH = 10;
const int DEFAULT_SHOT_HEIGHT = 30;
const float SHOT_0_DAMAGE = 70.0;
const float SHOT_1_DAMAGE = 80.0;
const float SHOT_2_DAMAGE = 90.0;
const float SHOT_3_DAMAGE = 100.0;
const float SHOT_4_DAMAGE = 120.0;
const float SHOT_5_DAMAGE = 140.0;
const float DEFAULT_SHOT_FIRERATE = 1.0;

#endif // ENTITIES_HPP_INCLUDED
