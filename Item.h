#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
    public:
        Item(std::string, int, int, int);
        std::string getDescription() const;
        int getHlthMod() const;
        int getStrMod() const;
        int getSpdMod() const;
    private:
        std::string description;
        int hlthMod;
        int strMod;
        int spdMod;
};

#endif
