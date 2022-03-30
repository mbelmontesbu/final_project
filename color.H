#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include <string>
#include <cassert>

class color {

private:
    char color_char;

public:
    //default constructor
    color()
        :color_char{'w'}
    {}

    //constructor
    color(char c){
        color_char = c;
    }

    //get color word
    char get_char(){
        return color_char;
    }

    //get color code
    std::string get_code() {
        switch (color_char){

            case 'w':
                return "\u001b[47m";

            case 'g':
                return "\u001b[42m";

            case 'y':
                return "\u001b[43m";

            default:
                return "\u001b[47m";

        }
    }
};
#endif