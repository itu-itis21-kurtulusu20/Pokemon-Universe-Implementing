#include "pokemon.h"
#include <iostream>
#pragma once
/* @Author
* Student Name: Uğurcan Kurtuluş
* Student ID : 150200082
*/

class PsychicPokemon : public Pokemon { // this class is inherited from pokemon class in public type.
public:
    PsychicPokemon(int, int); // constructor for psychic pokemon
    void increase_cooldown();
private:
};