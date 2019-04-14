#include <iostream>
#include <list>
#include <sstream>

int count = 0;

void submessage(std::ostream& out){}

template <typename Head, typename ...Args>
void submessage(std::ostream& out, Head head, Args ...args){
    if (count == 0){
        out << head;
        count++;
    }
    else{
        count--;
        submessage(out, args...);
        count++;
    }
}

template <typename ...Args>
bool message(std::ostream& out, std::string phrase, Args ...args){
    int argcount = 0;
    for (char letter : phrase){
        if (letter == '%'){
            argcount++;
        }
    }
    if (sizeof...(args) != argcount){
        std::cout << "Error: args overflow/outflow" << std::endl;
        return false;
    }    

    for (char letter : phrase){
        if (letter != '%'){
            out << letter;
        }
        else{
            submessage(out, args...);
        }
    }
    count = 0;
    return true;
}

