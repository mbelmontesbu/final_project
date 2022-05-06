#ifndef WORD_H
#define WORD_H

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

#include "letter_block.H"

class word {

private:
    std::vector<letter_block> word__;

public:
//default constructor
    word()
        :word__{}
    {}

//constructor
    word(std::vector<letter_block> w)
        :word__{w}
        {}

    char get_char_at(int pos){
        for(auto e: word__){
            if(e.get_pos() == pos){
                return e.get_char();
            }
        }
    }

};
#endif