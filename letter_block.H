#ifndef LETTER_BLOCK_H
#define LETTER_BLOCK_H

#include <iostream>
#include <string>
#include <cassert>

#include "color.H"

class letter_block {

private:
    char letter;
    std::string colorblock;
    double position;

public:
//default constructor
    letter_block()
        :letter{'A'},colorblock{"\u001b[47m"},position{0.0}
    {}

//constructor
    letter_block(char l, color& c, double p)
        :letter{l},colorblock{c.get_code()},position{p}
        {
            //assert((l>65 && l<90) || (l>97 && l<122));
            
        }

friend std::ostream& operator<< (std::ostream& os, const letter_block& l);
};

std::ostream& operator<< (std::ostream& os, const letter_block& l){
    os << l.colorblock << "\u001b[30m " << l.letter << " \u001b[0m";
    return os;
}

#endif