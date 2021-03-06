#include <iostream>
#include <vector>
#include "Constantes.hpp"
#include "coreEngine/SDLHandler.hpp"
#include "coreEngine/InputManager.hpp"
#include "coreEngine/GOManager.hpp"
#include "coreEngine/Camera.hpp"
#include "gameobject/Player.hpp"
#include "gameobject/Scenario.hpp"
#include "gameobject/components/Sprite.hpp"


using namespace std;

int main(int argc, char * argv[]){
    cout << "Starting game...." << endl;
    
    SDLHandler * sdl = &SDLHandler::getInstance();
    Camera * camera = &Camera::getInstance();
    InputManager input;

    Player player;
    Scenario * map = &Scenario::getInstance();;
    GOManager * gom = &GOManager::getInstance();

    SDL_EventType inputAction;
    while (inputAction != SDL_QUIT){
        float delta = sdl->getDelta();

        inputAction = input.processInput(&player); //Input
        
        //Update entities
        player.update(delta);
        gom->update(delta);
        camera->update(&player);

        //Drawing sequence
        sdl->cleanRender();
        map->draw();
        player.draw();
        gom->draw();
        sdl->draw();
    }
    return 0;
};