
#include <iostream>

#pragma once
/* @Author
* Student Name: Uğurcan Kurtuluş
* Student ID : 150200082
*/

class Pokemon {
public:
    Pokemon(int, int);
    const int get_hp();
    void set_hp(int);
    void set_damage(int);
    const std::string get_name();
    const int get_damage();
    void set_name(std::string);
    void set_cooldown(int);
    const int get_cooldown();
    void set_power_up(bool);
    const bool get_power_up();
private:
//essential attributes for both electric and psychic pokemons.
    int hp;
    int damage;
    std::string name;
    int cooldown;
    bool power_up; // if the pokemon is initiated a power up or not. 
};