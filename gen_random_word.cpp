//Generates Random Word from dictionary.txt
#include <iostream>
#include <fstream>
#include <string>
#include <random>

#include "rand.H"

std::string gen_rand_word () {
    std::random_device rd; //gen random seed

    std::mt19937 generator(rd()); //generator from seed

    std::ifstream in("dictionary.txt");
    std::vector<std::string> words;

    std::string word;
    while(std::getline(in,word)){
        if (word.size() > 0){
            words.push_back(word);
        }  
    }

    // our random number distribution
    std::uniform_int_distribution<int> uniform(0, words.size());

    return words[uniform(generator)];
}
