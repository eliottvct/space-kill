/********************************************************************************************
 * Project: SpaceKill
 * File: Game_Model.hpp
 * ------------------------------------------------------------------------------------------
 * Authors: Valentin Mancier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#ifndef GAME_MODEL_HPP_INCLUDED
#define GAME_MODEL_HPP_INCLUDED

#include "Player.hpp"
#include "Enemy.hpp"
#include "Shot.hpp"

#include <vector>

class Game_Model
{
private:
    int _w, _h;
    int m_score;
    int _levelStyle;
    int _spawnRateMax;
    float _spawnRate;
    float _levelProgress;
    float _lastSpawn;
    bool _level_change;
    Player * m_player;
    std::vector<Enemy*> enemies;

public:
    Game_Model(int w, int h);
    ~Game_Model();

    void nextStep(float timedelta);
    void Level(int levelStyle);
    void createEnemy(float timedelta);
    void moveEnemies(float timedelta);
    void shootEnemy(float timedelta);
    void moveShots(float timedelta);
    void manageCollisions();
    bool detectCollisions(const Ship* a, const Ship* b, int i);
    void loadLevel();

    Player* getPlayer() const;
    void getPlayerSettings(int &x, int &y, int &w, int &h) const;

    Enemy* getEnemy(int nb) const;
    int getEnemiesSize() const;
    void getEnemySettings(int &x, int &y, int &w, int &h, int i) const;

    int getLevelNumber() const;
    int getScore() const;
    bool getLevelChange() const;
    void setLevelChange(bool level_change);
};

#endif // GAME_MODEL_HPP_INCLUDED
