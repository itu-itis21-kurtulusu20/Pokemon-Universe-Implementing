#include "pokemon.h"
#include <iostream>
/* @Author
* Student Name: Uğurcan Kurtuluş
* Student ID : 150200082
*/
Pokemon::Pokemon(int hp, int damage){ //constructor for pokemon class, both electric and psychic pokemons use this constuctor.
    this->damage = damage;
    this->hp = hp;
}
const int Pokemon::get_hp(){ //getter for hp, since it doesnt change anything, it is const.
    return this->hp;
}
void Pokemon::set_hp(int new_hp){ //setter for hp
    this->hp = new_hp;
}
void Pokemon::set_damage(int new_damage){ //setter for damage
    this->damage = new_damage;
}
const std::string Pokemon::get_name(){ //getter for name, since it doesnt change anything, it is const.
    return this->name;
}
void Pokemon::set_name(std::string name){ //setter for name
    this->name = name;
}
const int Pokemon::get_damage(){ //getter for damage, since it doesnt change anything, it is const.
    return this->damage;
}
void Pokemon::set_cooldown(int cooldown){ //setter for cooldown, it will be used while counting the power up cooldown.
    this->cooldown = cooldown;
}
const int Pokemon::get_cooldown(){ //getter for damage, since it doesnt change anything, it is const.
    return this->cooldown;
}
void Pokemon::set_power_up(bool power_up_check){ //setter for power up, it will be used while checking if that pokemon initiated a power up or not.
    this->power_up = power_up_check;
}
const bool Pokemon::get_power_up(){ //getter for power up, since it doesnt change anything, it is const.
    return this->power_up;
}
