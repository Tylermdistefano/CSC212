#include "Animal.h"

Animal::Animal(float initial_hunger , float initial_thirst){
    this->hunger = initial_hunger;
    this->thirst = initial_thirst;
}

float Animal::GetHunger(){
    return this->hunger;
}

void Animal::Eat(float sustenance){
    this->hunger += sustenance;
}

float Animal::GetThirst(){ 
    return this->thirst;
}

void Animal::Drink(float sustenance){
    this->thirst += sustenance;
}