//File to get 5 letter guess from user
#include <iostream>
#include <string>

#include "get_entry.H"

std::string get_entry() {
    std::string raw_entry{"default"};

    while(raw_entry.size() != 5){//asserts a 5 letter word
        std::cout << "Enter a 5-letter word: ";
        std::cin >> raw_entry;
    }

    //makes sure the input is all lower case
    std::string entry;
    for (auto e:raw_entry){
        char c = tolower(e);
        entry.push_back(c);
    }
    return entry;
}
