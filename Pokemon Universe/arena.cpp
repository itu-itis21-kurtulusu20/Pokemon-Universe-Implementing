
#include "arena.h"

#include <iostream>
/* @Author
* Student Name: Uğurcan Kurtuluş
* Student ID : 150200082
*/
void Arena::addPokemon(char type, std::string name, int hp, int damage) {
    if (type == 'e') { 
        /*Electric pokemon will be added. It cooldown for power up and confusion will be 3. At first, confusion and power up bool parameters
        are false. */
        this -> new_epokemon = new ElectricPokemon(hp, damage);
        new_epokemon -> set_name(name);
        new_epokemon -> set_cooldown(3);
        new_epokemon -> set_confusion_cooldown(3);
        new_epokemon->set_confusion(false);
        new_epokemon->set_power_up(false);
        std::cout << "Electric Pokemon " << new_epokemon -> get_name() << " has entered the arena." << std::endl;
        std::cout << "Class: Electric" << std::endl;
        std::cout << "Name: " << new_epokemon -> get_name() << std::endl;
        std::cout << "HP: " << new_epokemon -> get_hp() << std::endl;
        std::cout << "Damage: " << new_epokemon -> get_damage() << std::endl;
    } else if (type == 'p') {
        /*Psychic pokemon will be added. It cooldown for power up will be 5. At first, power up bool parameter is false. */
        this -> new_ppokemon = new PsychicPokemon(hp, damage);
        new_ppokemon -> set_name(name);
        new_ppokemon -> set_cooldown(5);
        new_ppokemon->set_power_up(false);
        std::cout << "Psychic Pokemon " << new_ppokemon -> get_name() << " has entered the arena." << std::endl;
        std::cout << "Class: Psychic" << std::endl;
        std::cout << "Name: " << new_ppokemon -> get_name() << std::endl;
        std::cout << "HP: " << new_ppokemon -> get_hp() << std::endl;
        std::cout << "Damage: " << new_ppokemon -> get_damage() << std::endl;
    }
}
//setter for type of terrain.
void Arena::set_type_of_terrain(std::string terrain) {
    this -> type_of_terrain = terrain;
}
void Arena::spawnTerrain() { 
    /* a function to determine the type of terrain with %20 chances of psychic or electric and %60 chance for none of them.
    for this purpose a random number will be used between 0 and 9. 0 and 1 means it is electric and 8 and 9 means it is psychic.
    other numbers mean type of terrain is none of them.*/
    int random = rand() % 10;
    if (random < 2) {
        set_type_of_terrain("electric");
    } else if (random > 7) {
        set_type_of_terrain("psychic");
    } else {
        set_type_of_terrain("none");
    }
}

const std::string Arena::get_type_of_terrain() { //getter for type of terrain, since it doesnt change anything it is const.
    return this -> type_of_terrain;
}

void Arena::simulateBattle() {
    this -> spawnTerrain(); // first we'll assign the terrain.
    int round = 1;
    int electric_terrain_check = 0; //this counters will be used to check if the terrain type is electric or psychic for 5 rounds or not.
    int psychic_terrain_check = 0;
    while (new_epokemon -> get_hp() > 0 && new_ppokemon -> get_hp() > 0) { // battle will continue until one of the pokemons hp will fall to 0 or below.

        int heads = rand() % 2; // a random number will be assigned to check which pokemon will strike first. (0->electric, 1->psychic)
        int power_up_num = rand() % 100; // another random number will be used to initiate power ups.

        if (power_up_num < 20 && new_epokemon->get_cooldown() == 3) { //both number and cooldown will be checked to initate a power up.
            this -> new_epokemon -> set_power_up(true);
            this->new_epokemon ->set_cooldown(0); // cooldown will be reseted if pokemon initiate a power up. 
        }
        if (power_up_num < 30 && new_ppokemon->get_cooldown() == 5) {
            this -> new_ppokemon -> set_power_up(true);
            this->new_ppokemon ->set_cooldown(0);
        }
        if (get_type_of_terrain() == "electric") {
            if(new_epokemon->get_confusion() == true){
            new_epokemon->set_confusion(false); // if theres an early confusion, it will be disappeared if the type of terrain is electric. 
            new_epokemon->set_confusion_cooldown(3);//and the cooldown will be reseted.
            }
            if (heads == 0) { // it means electric pokemon will strike first
                if (new_epokemon -> get_power_up() == true) { // first we will check if it is initiated a power up or not.
                    new_ppokemon -> set_hp(new_ppokemon -> get_hp() - (new_epokemon -> get_damage() * 3)); // if it is initiate a power up
                } else {                                                                //it will cause 3 times more damage. 
                    new_ppokemon -> set_hp(new_ppokemon -> get_hp() - new_epokemon -> get_damage());
                }
                if (new_ppokemon -> get_hp() <= 0) { // after each strike, we will check if the other pokemons' hp is above 0 or not.
                    printRoundStats(round,  heads);
                    printMatchResults(); //in the case of below 0, round status and match results will be written and we will exit the while loop.
                    break;
                }
                new_epokemon -> set_hp(new_epokemon -> get_hp() - new_ppokemon -> get_damage()); //after electric pokemon
                if (new_epokemon -> get_hp() <= 0) {                            //now psychic pokemon will strike., we wont even check if
                    printRoundStats(round,  heads);                             //it initiated a power up or not because we are in the electric terrain.
                    printMatchResults();
                    break;
                }
            } else {
                new_epokemon -> set_hp(new_epokemon -> get_hp() - new_ppokemon -> get_damage()); //first psychic pokemon will strike and 
                if (new_epokemon -> get_hp() <= 0) {                    // electric pokemons' hp will be checked.
                    printRoundStats(round,  heads);
                    printMatchResults();
                    break;
                }
                if (new_epokemon -> get_power_up() == true) {  //after electric pokemon will strike(first by checking if its initiated a power up or not.)
                    new_ppokemon -> set_hp(new_ppokemon -> get_hp() - (new_epokemon -> get_damage() * 3));
                } else {
                    new_ppokemon -> set_hp(new_ppokemon -> get_hp() - new_epokemon -> get_damage());
                }
                if (new_ppokemon -> get_hp() <= 0) {
                    printRoundStats(round,  heads);
                    printMatchResults();
                    break;
                }
            }
            electric_terrain_check++; //electric terrain check will be increased after a round in a electric arena.
        } else if (get_type_of_terrain() == "psychic") {
            if (heads == 0) {
                if (new_epokemon -> get_confusion() == false) { // first we will check if it is confused or not, if it confused, it cant strike.
                    if (new_epokemon -> get_power_up() == true) {
                        new_ppokemon -> set_hp(new_ppokemon -> get_hp() - (new_epokemon -> get_damage() * 3));
                    } else {
                        new_ppokemon -> set_hp(new_ppokemon -> get_hp() - new_epokemon -> get_damage());
                    }
                    if (new_ppokemon -> get_hp() <= 0) {
                        printRoundStats(round,  heads);
                        printMatchResults();
                        break;
                    }
                }
                new_epokemon -> set_hp(new_epokemon -> get_hp() - (2 * new_ppokemon -> get_damage())); // in the psychic arena, psychic pokemon will
                if (new_epokemon -> get_hp() <= 0) {                                        // cause twice as damage as normal.
                    printRoundStats(round,  heads);
                    printMatchResults();
                    break;
                }
            } else {
                if (new_ppokemon -> get_power_up() == true) {
                    new_epokemon -> set_confusion(true); // electric pokemon will be confused and confusion cooldown will be reseted.
                    new_epokemon->set_confusion_cooldown(0);                    
                }
                new_epokemon -> set_hp(new_epokemon -> get_hp() - (2 * new_ppokemon -> get_damage()));
                if (new_epokemon -> get_hp() <= 0) {
                    printRoundStats(round,  heads);
                    printMatchResults();
                    break;
                }
                if (new_epokemon -> get_confusion() == false) {
                    if (new_epokemon -> get_power_up() == true) {
                        new_ppokemon -> set_hp(new_ppokemon -> get_hp() - (new_epokemon -> get_damage() * 3));
                    } else {
                        new_ppokemon -> set_hp(new_ppokemon -> get_hp() - new_epokemon -> get_damage());
                    }
                    if (new_ppokemon -> get_hp() <= 0) {
                        printRoundStats(round,  heads);
                        printMatchResults();
                        break;
                    }
                }
            }
            psychic_terrain_check++; //psychic terrain check will be increased after a round in a psychic arena.
        } else { // none of the terrain are activated. both pokemons will strike as usual.
            if (heads == 0) {
                if (new_epokemon -> get_confusion() == false) { //it can strike if its not confused.
                    if (new_epokemon -> get_power_up() == true) {
                        new_ppokemon -> set_hp(new_ppokemon -> get_hp() - (new_epokemon -> get_damage() * 3));
                    } else {
                        new_ppokemon -> set_hp(new_ppokemon -> get_hp() - new_epokemon -> get_damage());
                    }
                    if (new_ppokemon -> get_hp() <= 0) {
                        printRoundStats(round,  heads);
                        printMatchResults();
                        break;
                    }
                }
                if (new_ppokemon -> get_power_up() == true) {
                    new_epokemon -> set_confusion(true); //electric pokemon will be confused and confusion cooldown will be reseted.
                    new_epokemon->set_confusion_cooldown(0);
                }
                new_epokemon -> set_hp(new_epokemon -> get_hp() - (new_ppokemon -> get_damage()));
                if (new_epokemon -> get_hp() <= 0) {
                    printRoundStats(round,  heads);
                    printMatchResults();
                    break;
                }
            } else {
                if (new_ppokemon -> get_power_up() == true) {//electric pokemon will be confused and confusion cooldown will be reseted.
                    new_epokemon -> set_confusion(true);
                    new_epokemon->set_confusion_cooldown(0);
                }
                new_epokemon -> set_hp(new_epokemon -> get_hp() - new_ppokemon -> get_damage());
                if (new_epokemon -> get_hp() <= 0) {
                    printRoundStats(round,  heads);
                    printMatchResults();
                    break;
                }
                if (new_epokemon -> get_confusion() == false) { //it may only attack if its not confused.
                    if (new_epokemon -> get_power_up() == true) {
                        new_ppokemon -> set_hp(new_ppokemon -> get_hp() - (new_epokemon -> get_damage() * 3));
                    } else {
                        new_ppokemon -> set_hp(new_ppokemon -> get_hp() - new_epokemon -> get_damage());
                    }
                    if (new_ppokemon -> get_hp() <= 0) {
                        printRoundStats(round,  heads);
                        printMatchResults();
                        break;
                    }
                }
            }
        }
        if(new_epokemon->get_cooldown() != 3){ // if its cooldown is different than 3, that means it is initiated a power up and now is in the cooldown.
            new_epokemon->increase_cooldown();  // so we will increase it.
        }
        if(new_ppokemon->get_cooldown() != 5){// if its cooldown is different than 5, that means it is initiated a power up and now is in the cooldown.
            new_ppokemon->increase_cooldown();// so we will increase it.
        }

        if(new_epokemon->get_confusion() == true){ // if its confused we will increase its confusion cooldown.
            new_epokemon->increase_confusion_cooldown();
        }
        printRoundStats(round,  heads); // we will print the round status after each round.
        new_epokemon->set_power_up(false); // after a round, power up status are reseted.
        new_ppokemon->set_power_up(false);
        round = round + 1; // after a round, round number will be increased. 
        if (get_type_of_terrain() == "none") { //a new terrain will be spawned after a round in the "none" type terrain.
            this -> spawnTerrain();
        } else if (psychic_terrain_check == 5 || electric_terrain_check == 5) { // electric and psychic terrains will stay for 5 rounds.
            this -> spawnTerrain();
        }
    }
    restartTerrain(); //after new pokemons added to the arena, type will be assigned again.
}

void Arena::printRoundStats(int round, int heads) { //function for printing the round status after each round.
    std::cout << "Round: " << round << std::endl;
    std::cout << "Current Terrain: " << this -> get_type_of_terrain() << std::endl;
    if (heads == 0) { // head will decide the first pokemon.
        std::cout << new_epokemon -> get_name() << " goes first" << std::endl;
    } else {
        std::cout << new_ppokemon -> get_name() << " goes first" << std::endl;
    }
    if (new_epokemon -> get_power_up() == true) { // if any of the two pokemons initiate a power up, it will be written.
        std::cout << new_epokemon -> get_name() << " has initiated a power up." << std::endl;
    }
    if (new_ppokemon -> get_power_up() == true) {
        std::cout << new_ppokemon -> get_name() << " has initiated a power up." << std::endl;
    }
    if(new_epokemon->get_hp() < 0){ // no negative numbers will written, so we will set them to 0 if theres any.
        new_epokemon->set_hp(0);
    }
    if(new_ppokemon->get_hp() < 0){
        new_ppokemon->set_hp(0);
    }    
    std::cout << new_epokemon -> get_name() << " HP: " << new_epokemon -> get_hp() << std::endl; //pokemons hp will be written.
    std::cout << new_ppokemon -> get_name() << " HP: " << new_ppokemon -> get_hp() << std::endl; 
    if (new_epokemon -> get_hp() > new_ppokemon -> get_hp()) {
        std::cout << new_epokemon -> get_name() << " is in the lead!" << std::endl; //the pokemon with the higher hp will be in the lead.
    } else {
        std::cout << new_ppokemon -> get_name() << " is in the lead!" << std::endl;
    }

}

void Arena::printMatchResults(){ //at the end, match results will written.
    if(new_epokemon->get_hp() > 0){
        std::cout << new_epokemon -> get_name() <<" has won the match!" <<std::endl;
    }
    else{
        std::cout << new_ppokemon -> get_name() <<" has won the match!" <<std::endl;
    }
}

void Arena::restartTerrain(){ // arena type will assigned to none after new pokemons added to the arena.
    this->set_type_of_terrain("None");
}