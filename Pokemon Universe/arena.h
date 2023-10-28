#pragma once
#include <iostream>
#include "psychicPokemon.h"
#include "electricPokemon.h"
/* @Author
* Student Name: Uğurcan Kurtuluş
* Student ID : 150200082
*/

class Arena {
public:
    void addPokemon(char, std::string, int, int);
    void simulateBattle();
    void spawnTerrain();
    void restartTerrain();
    void printRoundStats(int round, int heads);
    void printMatchResults();
    void set_type_of_terrain(std::string);
    const std::string get_type_of_terrain();
private:
    std::string type_of_terrain; //electric, psychic, or none
    ElectricPokemon* new_epokemon; //pokemon pointers will be defined here to make changes on them in arena.cpp
    PsychicPokemon* new_ppokemon;
};