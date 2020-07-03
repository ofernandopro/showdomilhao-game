#ifndef UTIL_H
#define UTIL_H

#include <string>

using namespace std;

inline string get_letra(int letra){
    switch(letra){
        case 1: return "a";
        case 2: return "b";
        case 3: return "c";
        case 4: return "d";
        default: return "";
    }
}

#endif