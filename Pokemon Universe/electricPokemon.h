#include "pokemon.h"
#include <iostream>
#pragma once
/* @Author
* Student Name: Uğurcan Kurtuluş
* Student ID : 150200082
*/


class ElectricPokemon : public Pokemon { // this class is inherited from pokemon class in public type.
public:
    ElectricPokemon(int, int); //constructor for electric pokemon.
    void set_confusion(bool);
    const bool get_confusion();
    void increase_cooldown();
    void set_confusion_cooldown(int);
    const int get_confusion_cooldown();
    void increase_confusion_cooldown();
private:
    bool confusion; // if the pokemon is confused or not.
    int confusion_cooldown; // to keep track of round number that the pokemon is confused.
};