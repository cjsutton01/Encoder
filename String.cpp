#include "String.h"
#include <iostream>
#include <string>

void StringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}
void StringAutomaton::S1(const std::string& input) {
    if(index == (int)input.size()){
        type = TokenType::UNDEFINED;
        //Serr();
        return;
    }
    else if (input[index] == '\'') {
        inputRead++;
        index++;
        S2(input);
    }
    else if(input[index] == '\n'){
        newLines++;
        inputRead++;
        index++;
        S1(input);
    }
    else if(input[index] != '\''){
        inputRead++;
        index++;
        S1(input);
    }

}
void StringAutomaton::S2(const std::string& input) {
    if(index == (int)input.size()){
        type = TokenType::UNDEFINED;
        //Serr();
        return;
    }
    else if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }

}