/********************************************************************************************
 * Project: SpaceKill
 * File: main.cpp
 * ------------------------------------------------------------------------------------------
 * Authors: Valentin Mancier, Eliott Vincent
 * License: This work is licensed under the Creative Commons
 *          Attribution-NonCommercial-ShareAlike 4.0 International License.
 *********************************************************************************************/

#include "Game_Model.hpp"
#include "Entities.hpp"
#include "Game_View.hpp"

#include <cstdlib>
#include <iostream>

using namespace std;

using namespace sf;

int main()
{
    srand(time(NULL));
    Clock clock;
    float timedelta = 0.0;
    sf:Time elapsed;

    Game_Model *model = new Game_Model(MODEL_WIDTH, MODEL_HEIGHT);
    Game_View *view = new Game_View(VIEW_WIDTH,VIEW_HEIGHT, VIEW_BPP);
    view->setModel(model);

    view->drawIntro(clock);

    /*** Menu ***/
    view->playMusic(true);
    while(view->treatMenuEvents())
    {

        view->drawMenu();
    }
    /************/

    /*** Game ***/
    timedelta=0;
    while(view->treatEvents(timedelta))
    {
        clock.restart();
        view->drawGame();
        model->nextStep(timedelta);

        elapsed = clock.getElapsedTime();
        timedelta = elapsed.asSeconds();

        view->drawTransition(clock);
        view->drawGameOver();
    }
    /************/

    delete view;
    delete model;
    return 0;
}
