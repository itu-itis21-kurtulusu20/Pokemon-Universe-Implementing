#include <iostream>
#include "electricPokemon.h"
/* @Author
* Student Name: Uğurcan Kurtuluş
* Student ID : 150200082
*/

ElectricPokemon::ElectricPokemon(int hp, int damage) : Pokemon{hp, damage} //constructor for electric pokemon, it uses the Pokemon class' 
{}                                                                        //constructor for assigning hp and damage because they're mutual for 
                                                                            //both electric and psychic pokemons.

void ElectricPokemon::set_confusion(bool confusion){ //setter for confusion, when psychic pokemon is initiate a power up and if the                        
    this->confusion = confusion;                    //terrain is not electric, we will use this function to set electric pokemon to confused.
}
const bool ElectricPokemon::get_confusion(){ //getter for confusion, since it doesnt change anything it is const.
    return this->confusion;
}
void ElectricPokemon::increase_cooldown(){ //function for increasing the cooldown for electric pokemons' power up.
    if(this->get_cooldown() != 3){          //no need to increase after 3, the confusion will be set to false and counter will be reseted.(arena.cpp)
        this->set_cooldown(this->get_cooldown() + 1); 
    }
}
void ElectricPokemon::set_confusion_cooldown(int conf_cooldown){ //setter for confusion cooldown, at the first, it will be set to 3
    this->confusion_cooldown = conf_cooldown;                  // and will be reseted when the confusion is disappeared.
}
const int ElectricPokemon::get_confusion_cooldown(){ //getter for confusion cooldown, since it doesnt change anything, it is const.
    return this->confusion_cooldown;
}
void ElectricPokemon::increase_confusion_cooldown(){  //function for increasing the cooldown for electric pokemons' confusion.
    if(this->get_confusion_cooldown() == 3){ //confusion will be disappeared after 3 rounds.
        this->set_confusion(false);
    }
    else{//no need to increase after 3
        this->set_confusion_cooldown(this->get_confusion_cooldown() + 1);
    }
}