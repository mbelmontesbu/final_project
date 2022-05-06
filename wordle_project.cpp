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
int number_of_guesses;

//initialize functions
std::vector<occ_of_letter> count_letters(std::string &word);
void print_word(std::vector<letter_block> &word);

int main() {
    std::cout << "\u001b[30m \u001b[47m A \u001b[0m : Letter is not in the word." << std::endl;
    std::cout << "\u001b[30m \u001b[43m A \u001b[0m : Letter is in the word, but not in the correct place." << std::endl;
    std::cout << "\u001b[30m \u001b[42m A \u001b[0m : Letter is in  the word and in the correct place." << std::endl;
    
    int state_of_game = 0;

    while (state_of_game == 0){
        number_of_guesses += 1;
        std::string answer{"sheep"};

        std::string raw_entry{"default"};
        while(raw_entry.size()<1 || raw_entry.size()>5){
            std::cout << "Enter a 5-letter word: ";
            std::cin >> raw_entry;
        }

        std::string entry;
        for (auto e:raw_entry){
            char c = tolower(e);
            entry.push_back(c);
        }

        std::vector<letter_block> blocked_word;


    //testing compare
        std::vector<letter_block> answer_word;
        for(int i = 0; i<5; ++i){
            letter_block letter(answer[i],white,i);
            answer_word.push_back(letter);
        }
        
        std::string comp_answer = answer;

        for(int i = 0; i < 5; ++i){
            letter_block letter(entry[i],white,i);
            auto pos = std::find(comp_answer.begin(), comp_answer.end(), entry[i]);
            if(pos-comp_answer.begin() == i){ //letter in word and correct position
                letter.change_color(green);
                comp_answer.replace(pos,pos+1,"A");
            }
            blocked_word.push_back(letter);
        }
        
        for(int i = 0; i <5; ++i){
            auto pos = std::find(comp_answer.begin(), comp_answer.end(), entry[i]);
            std::cout<< comp_answer <<std::endl;
            std::cout<< entry[i] << "," << pos-comp_answer.begin() << std::endl;
            if((pos-comp_answer.begin() != i) && (pos != comp_answer.end()) && (blocked_word[i].get_color().get_char() != green.get_char())){
                std::cout<< blocked_word[i] <<std::endl;
                comp_answer.replace(pos,pos+1,"A");
                blocked_word[i].change_color(yellow);
            }
        }

        previous_guesses.push_back(blocked_word);

        for (auto e: previous_guesses){
            print_word(e);
        }

        if(entry == answer){
            state_of_game = 1;
        }
        if(number_of_guesses == 6){
            state_of_game = 1;
        }
        
    }
}

//Define Functions

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