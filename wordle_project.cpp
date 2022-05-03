#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "color.H"
#include "letter_block.H"

struct occ_of_letter
{
    char c;
    int count;
};

//initialize constants
//colors
color green('g');
color yellow('y');
color white('w');
//other
std::vector<std::vector<letter_block>> previous_guesses;

//initialize functions
std::vector<occ_of_letter> count_letters(std::string &word);
void print_word(std::vector<letter_block> &word);

int main() {
    std::cout << "\u001b[30m \u001b[47m A \u001b[0m : Letter is not in the word." << std::endl;
    std::cout << "\u001b[30m \u001b[43m A \u001b[0m : Letter is in the word, but not in the correct place." << std::endl;
    std::cout << "\u001b[30m \u001b[42m A \u001b[0m : Letter is in  the word and in the correct place." << std::endl;
    

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

    //count instances of letters
    std::vector<occ_of_letter> entry_counts = count_letters(entry);

    for (auto e: entry_counts){
    std::cout << e.c << std::endl;
    std::cout << e.count << std::endl;
    }
    
    std::vector<letter_block> blocked_word;
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
        blocked_word.push_back(letter);
    }
    previous_guesses.push_back(blocked_word);
    
    for(int i = 0; i < 5; ++i){
        letter_block letter(entry[i],white,i);
        auto pos = std::find(answer.begin(), answer.end(), entry[i]);
        if(pos == answer.end()){ //letter not in word
            std::cout << letter;
            //continue;
        }
        else if(pos-answer.begin() == i){ //letter in word and correct position
            letter.change_color(green);
            std::cout << letter;
            //continue;
        }
        else{
            letter.change_color(yellow); //letter in word but no correct position
            std::cout << letter;
        }
        blocked_word.push_back(letter);
    }
    previous_guesses.push_back(blocked_word);
    std::cout<<std::endl;

    for (auto e: previous_guesses){
        print_word(e);
    }
}

std::vector<occ_of_letter> count_letters(std::string &word){
    std::vector<occ_of_letter> occ_of_letters;
    for (auto it = word.begin(); it < word.end(); ++it) {
        occ_of_letter state{};
        int count = std::count(word.begin(), word.end(), *it);
        state.c = *it;
        state.count = count;
        occ_of_letters.push_back(state);   
    }
    return occ_of_letters;
};

void print_word(std::vector<letter_block> &word){
    for (auto e:word){
        std::cout<<e;
    }
    std::cout<<std::endl;
};