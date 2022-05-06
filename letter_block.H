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
    int position;

public:
//default constructor
    letter_block()
        :letter{'A'},colorblock{"\u001b[47m"},position{}
    {}

//constructor
    letter_block(char l, color& c, int p)
        :letter{l},colorblock{c.get_code()},position{p}
        {
            assert((tolower(l)>96) && (tolower(l)<122)); 
        }

    void change_color(color& c){
        colorblock = c.get_code();
    }

    char get_char(){
        return letter;
    }

    char get_pos(){
        return position;
    }

    color get_color(){
        if (colorblock == "\u001b[42m"){
            return green;
        }
        else if (colorblock == "\u001b[43m"){
            return yellow;
        }
        else if (colorblock == "\u001b[47m"){
            return white;
        }
        else{
            return white;
        }
    }

    friend std::ostream& operator<< (std::ostream& os, const letter_block& l);

};

std::ostream& operator<< (std::ostream& os, const letter_block& l){
    assert(l.letter > char(0));
    os << l.colorblock << "\u001b[30m " << char(toupper(l.letter)) << " \u001b[0m";
    return os;
}

#endif