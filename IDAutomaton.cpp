#include "IDAutomaton.h"
#include <cctype>

void IDAutomaton::S0(const std::string& input) {
    if (isalpha(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void IDAutomaton::S1(const std::string& input) {
    if (isalnum(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
}
