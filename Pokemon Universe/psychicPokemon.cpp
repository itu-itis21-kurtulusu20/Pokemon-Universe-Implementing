#include "psychicPokemon.h"
#include <iostream>
/* @Author
* Student Name: Uğurcan Kurtuluş
* Student ID : 150200082
*/
PsychicPokemon::PsychicPokemon(int hp, int damage) : Pokemon{hp, damage} //constructor for psychic pokemon
{}
void PsychicPokemon::increase_cooldown(){ //cooldown increaser for psychic pokemons' power up.
    if(this->get_cooldown() != 5){
        this->set_cooldown(this->get_cooldown() + 1);
    }
}