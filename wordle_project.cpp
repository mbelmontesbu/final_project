#include <iostream>
#include "letter_block.H"

#include "color.H"

int main() {
    std::cout << "\u001b[30m \u001b[47m A \u001b[0m : Letter is not in the word." << std::endl;
    std::cout << "\u001b[30m \u001b[43m A \u001b[0m : Letter is in the word, but not in the correct place." << std::endl;
    std::cout << "\u001b[30m \u001b[42m A \u001b[0m : Letter is in  the word and in the correct place." << std::endl;

    letter_block letter1;
    std::cout << letter1 << std::endl;

    color green('g');
    std::cout << green.get_char() << std::endl;

    letter_block letter2('A', green, 1);
    std::cout << letter2 << std::endl;

}