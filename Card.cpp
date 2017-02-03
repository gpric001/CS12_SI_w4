#include "Card.h"

Card::Card(std::string name, int health, int strength, int speed) 
  : name(name), health(health), strength(strength), speed(speed), actionTimer(0) {}

std::string Card::getName() const {
    return name;
}

int Card::getHealth() const {
    return health;
}

int Card::getStrength() const {
    return strength;
}

int Card::getSpeed() const {
    return speed;
}

int Card:: getAT() const {
    return actionTimer;
}

void Card::setHealth(int health){
    this->health = health;
}

void Card::setStrength(int strength){
    this->strength = strength;
}

void Card::setSpeed(int speed){
    this->speed = speed;
}

void Card::attack(Card& enemy){
    enemy.setHealth(enemy.getHealth() - this->getStrength());
}

bool Card::canAct() const{
    return this->actionTimer >= 10;
}

bool Card::isDead() const{
    return this->getHealth() <= 0;
}

void Card::resetAT(){
    this->actionTimer = 0;
}

void Card::progressAT(){
    this->actionTimer += this->getSpeed();
}

void Card::equipItem(Item& item){
    //TODO: Implement this
    //This method should add an item to the equipment vector and modify the
    //cards statistics
    return;
}

void Card::unequipItem(Item& item){
    //TODO: Implement this
    //This method should remove an item from the equipment vector and modify the
    //cards statistics. Be careful about trying to remove an item that doesn't
    //exist.
    return;
}
std::ostream& operator<<(std::ostream& os, const Card&){
    //TODO: Implement this
    //This should output all relevant information about the card, including
    //information about the name, health, strength, speed, action timer, and
    //items
    return os;
}
