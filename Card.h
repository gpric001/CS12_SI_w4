#ifndef CARD_H
#define CARD_H
 
#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
 
class Card {
    public:
        Card(std::string, int, int, int);
        std::string getName() const;
        int getHealth() const;
        int getStrength() const;
        int getSpeed() const;
        int getAT() const;
        void setHealth(int);
        void setStrength(int);
        void setSpeed(int);
        void attack(Card&);
        bool isDead() const;
        bool canAct() const;
        void resetAT();
        void progressAT();
        void equipItem(Item&);
        void unequipItem(Item&);
        friend std::ostream& operator<<(std::ostream& os, const Card&);
    private:
        std::string name;
        int health;
        int strength;
        int speed;
        int actionTimer;
        std::vector<Item> items;
};
#endif
