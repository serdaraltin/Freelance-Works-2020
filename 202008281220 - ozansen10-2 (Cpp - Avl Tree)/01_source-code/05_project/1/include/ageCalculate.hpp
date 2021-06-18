#include "person.hpp"

int ageCalculate(CPerson *pPerson){
    int deliv = pPerson->pDeliv;
    int res = 2020 - deliv;
    return res;
} 