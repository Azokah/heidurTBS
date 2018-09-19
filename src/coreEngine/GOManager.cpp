#include "GOManager.hpp"
#include "../gameobject/components/Sprite.hpp"

GOManager::~GOManager(){};
GOManager::GOManager(){};

GOManager& GOManager::getInstance(){
    static GOManager instance;
    return instance;
};

