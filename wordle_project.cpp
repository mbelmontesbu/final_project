#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

#include "rand.H"
#include "get_entry.H"
#include "letter_block.H"

//initialize constants
std::vector<std::vector<letter_block>> previous_guesses;
int number_of_guesses;

//initialize functions
void print_word(std::vector<letter_block> &word);

int main() {
    //Srart game and give instructions
    std::cout << "Welcome to Wordle! Here are the rules:" << std::endl;
    std::cout << "\u001b[30m \u001b[47m A \u001b[0m : Letter is not in the word." << std::endl;
    std::cout << "\u001b[30m \u001b[43m A \u001b[0m : Letter is in the word, but not in the correct place." << std::endl;
    std::cout << "\u001b[30m \u001b[42m A \u001b[0m : Letter is in the word and in the correct place." << std::endl;
    int state_of_game = 0;

    //generate random word from txt file
    std::string answer{};
    answer = gen_rand_word();

    //forece answer to be "sheep" if in DEBUG mode
    #ifdef DEBUG
        answer = "sheep";
        std::cout << answer << std::endl;
    #endif
    
    //loop till game end or 6 guesses
    while (state_of_game == 0){
        number_of_guesses += 1;

        //get guess from user
        std::string entry = get_entry();

        //test guess
        std::vector<letter_block> blocked_word;
        std::string comp_answer = answer;

        for(int i = 0; i < 5; ++i){ //tests for green and white squares
            letter_block letter(entry[i],white,i); //defaults to incorrect (white)
            auto pos = std::find(comp_answer.begin(), comp_answer.end(), entry[i]);
            if(comp_answer[i] == entry[i]){ //letter in word and correct position
                letter.change_color(green);
                comp_answer.replace(pos,pos+1,"A");
            }
            blocked_word.push_back(letter);
        }

        for(int i = 0; i <5; ++i){ //tests yellow squares
            auto pos = std::find(comp_answer.begin(), comp_answer.end(), entry[i]);
            if((pos-comp_answer.begin() != i) && (pos != comp_answer.end())){
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
            std::cout << "CONGRATULATIONS!" << std::endl;
        }
        if(number_of_guesses == 6 && entry != answer){
            state_of_game = 1;
            std::cout << "The word was: " << answer << std::endl;
            std::cout << "TRY AGAIN NEXT TIME!" << std::endl;
        }
        
    }
}

//Define Functions
void print_word(std::vector<letter_block> &word){ //print string of letter_blocks to console
    for (auto e:word){
        std::cout<<e;
    }
    std::cout<<std::endl;
}