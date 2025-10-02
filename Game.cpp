#include "Game.h"
#include <iostream>


void Game::updateGrid(const std::vector<std::unique_ptr<Action>>& moves){
    for(const std::unique_ptr<Action> &move:moves){
        std::string type = move->get_type();
        if(type=="MOVE"){

        }else if(type=="FOG"){

        }else if(type=="SHOOT"){

        }
    }
}
