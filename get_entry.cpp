//File to get 5 letter guess from user
#include <iostream>
#include <string>

#include "get_entry.H"

std::string prompt_entry();

std::string get_entry() {
    
    std::string raw_entry = prompt_entry();

    
    std::string entry;
    for (auto e:raw_entry){
        char c = tolower(e);
        if ((c<97) || (c>122)){ //makes sure each character is a letter a-z
            raw_entry = prompt_entry();
        }
    }

    for (auto e:raw_entry){
        char c = tolower(e); //makes sure the input is all lower case
        if ((e>96) || (e<122)){
            entry.push_back(c);
        }
    }

    return entry;
}

std::string prompt_entry(){
    std::string raw_entry{"default"};

    while(raw_entry.size() != 5){//asserts a 5 letter word
        std::cout << "Enter a 5-letter word: ";
        std::cin >> raw_entry;
    }

    return raw_entry;
}
