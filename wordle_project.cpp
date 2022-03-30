#include <iostream>
#include <string>
#include <algorithm>

#include "color.H"
#include "letter_block.H"

int main() {
    std::cout << "\u001b[30m \u001b[47m A \u001b[0m : Letter is not in the word." << std::endl;
    std::cout << "\u001b[30m \u001b[43m A \u001b[0m : Letter is in the word, but not in the correct place." << std::endl;
    std::cout << "\u001b[30m \u001b[42m A \u001b[0m : Letter is in  the word and in the correct place." << std::endl;
    //initialize colors
    color green('g');
    color yellow('y');
    color white('w');

    /*
    char character_in;
    std::cout << "Enter Letter: ";
    std::cin >> character_in;

    letter_block letter3(character_in, yellow, 1);
    std::cout << letter3 << std::endl;
    letter3.change_color(green);
    std::cout << letter3 << std::endl;

    
    std::string string_in{"default"};
    while(string_in.size()<1 || string_in.size()>5){
        std::cout << "Enter a 5-letter word: ";
        std::cin >> string_in;
    }

    //std::string answer{"sheep"};
    for (auto& s : string_in){
        std::cout << letter_block(s,white,1);
    }
    std::cout<<std::endl;
    */

    std::string answer{"shemp"};
    /*
    auto pos1 = std::find(answer.cbegin(), answer.cend(), 'e');
    std::cout << "element found: " << *pos1 << std::endl;
    */
    std::string entry{"default"};
    while(entry.size()<1 || entry.size()>5){
        std::cout << "Enter a 5-letter word: ";
        std::cin >> entry;
    }

    /*
    auto pos2 = std::find(entry.cbegin(), entry.cend(), 'e');
    std::cout << "element found: " << *pos2 << std::endl;

    if(pos1 - answer.cbegin() == pos2 - entry.cbegin()){
        std::cout<< "AHH" << std::endl;
    }*/

    for (auto it = entry.begin(); it < entry.end(); ++it) {
        letter_block letter(*it,white,it-entry.begin());
        auto pos = std::find(answer.begin(), answer.end(),*it);
        if(pos == answer.end()){
            std::cout << letter;
            //continue;
        }
        else if(pos-answer.begin() == it-entry.begin()){
            letter.change_color(green);
            std::cout << letter;
            //continue;
        }
        else{
            letter.change_color(yellow);
            std::cout << letter;
        }
        
    }
    std::cout<<std::endl;
}