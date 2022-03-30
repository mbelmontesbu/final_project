#include <iostream>
#include <string>

class letter_block {

private:
    char letter;
    std::string color;
    double position;

public:
//default constructor
    letter_block()
        :letter{'A'},color{"\u001b[30m"},position{0.0}
    {}
friend std::ostream& operator<< (std::ostream& os, const letter_block& l);
};

std::ostream& operator<< (std::ostream& os, const letter_block& l){
    os << l.color << "\u001b[47m " << l.letter << " \u001b[0m";
    return os;
}