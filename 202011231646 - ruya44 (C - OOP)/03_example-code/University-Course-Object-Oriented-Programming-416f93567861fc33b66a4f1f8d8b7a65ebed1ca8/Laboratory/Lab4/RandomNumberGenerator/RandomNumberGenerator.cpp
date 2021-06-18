/*****************************************
 * RandomNumberGenerator.cpp             *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 4: Classes And Objects-I   *
 *****************************************/

#include "RandomNumberGenerator.h"  //To know function prototypes of RandomNumberGenerator class.
#include <time.h>                   //To use srand() function.
#include <iostream>                 //To use standart input output functions.
#include <math.h>                   //To use pow() and sqrt() functions.
using namespace std;                //To use standart input and output functions under the "std" namespace.

//Constructor Function is called when an object is created.
RandomNumberGenerator::RandomNumberGenerator()
{
    //To don't get the same random numbers.
    srand((unsigned) time (NULL));
}

RandomNumberGenerator::~RandomNumberGenerator()
{
    
}

//Generates integer number randomly between lowerBound and upperBound and returns it.
int RandomNumberGenerator::getRandomInteger(int lowerBound, int upperBound)
{
    int randomInteger;
    
    //For example, lowerBound=5, upperBound=8, To get random number between 5 and 8,
    //Firstly, get a random number from rand() function,
    //  Then, divide it to 4(upperBound-lowerBound+1).
    //  That means, random number can be 0,1,2,3 which are the possible remainder values of division.
    //      Then, add 5(lowerBound) to the remainder (0,1,2,3).
    //          Now, random number can be 5,6,7,8. (lowerBound and upperBound)
    randomInteger = lowerBound + rand()%(upperBound-lowerBound+1);
    
    return randomInteger;
}//end RandomNumberGenerator::getRandomInteger ()

//Generates float number randomly between lowerBound and upperBound
//and its fractional part is defined by precision (it can be integer value respectively 1,2,3,4).
float RandomNumberGenerator::getRandomFloat(float lowerBound, float upperBound, Precision precision)
{
    float randomFloat;
    
    int multiplied_lower_bound;
    int multiplied_upper_bound;
    
    //The size of the number's fractional part will be one.
    if(precision == ONE)
    {
        //Multiplies both lower and upper bound variables by pow(10,precision) and stores them different variables of type integer.
        multiplied_lower_bound = lowerBound * pow(10, precision);
        multiplied_upper_bound = upperBound * pow(10, precision);
        
        //Obtains a random integer value using multiplied boundaries and stores it in a float variable.
        randomFloat = getRandomInteger(multiplied_lower_bound, multiplied_upper_bound);
        
        //Divides obtained float value by pow(10,precision).
        randomFloat = randomFloat / pow(10,precision);
    }
    //The size of the number's fractional part will be two.
    else if(precision == TWO)
    {
        //Multiplies both lower and upper bound variables by pow(10,precision) and stores them different variables of type integer.
        multiplied_lower_bound = lowerBound * pow(10, precision);
        multiplied_upper_bound = upperBound * pow(10, precision);
        
        //Obtains a random integer value using multiplied boundaries and stores it in a float variable.
        randomFloat = getRandomInteger(multiplied_lower_bound, multiplied_upper_bound);
        
        //Divides obtained float value by pow(10,precision).
        randomFloat = randomFloat / pow(10, precision);
    }
    //The size of the number's fractional part will be three.
    else if(precision == THREE)
    {
        //Multiplies both lower and upper bound variables by pow(10,precision) and stores them different variables of type integer.
        multiplied_lower_bound = lowerBound * pow(10, precision);
        multiplied_upper_bound = upperBound * pow(10, precision);
        
        //Obtains a random integer value using multiplied boundaries and stores it in a float variable.
        randomFloat = getRandomInteger(multiplied_lower_bound, multiplied_upper_bound);
        
        //Divides obtained float value by pow(10,precision).
        randomFloat = randomFloat / pow(10, precision);
    }
    //The size of the number's fractional part will be four.
    else if(precision == FOUR)
    {
        //Multiplies both lower and upper bound variables by pow(10,precision) and stores them different variables of type integer.
        multiplied_lower_bound = lowerBound * pow(10, precision);
        multiplied_upper_bound = upperBound * pow(10, precision);
        
        //Obtains a random integer value using multiplied boundaries and stores it in a float variable.
        randomFloat = getRandomInteger(multiplied_lower_bound, multiplied_upper_bound);
        
        //Divides obtained float value by pow(10,precision).
        randomFloat = randomFloat / pow(10, precision);
    }
    
    return randomFloat;
}//end RandomNumberGenerator::getRandomFloat ()

//Generates double number randomly between lowerBound and upperBound
//and its fractional part is defined by precision (it can be integer value respectively 1,2,3,4).
double RandomNumberGenerator::getRandomDouble(double lowerBound, double upperBound, Precision precision)
{
    float randomDouble;
    
    int multiplied_lower_bound;
    int multiplied_upper_bound;
    
    //The size of the number's fractional part will be one.
    if(precision == ONE)
    {
        //Multiplies both lower and upper bound variables by pow(10,precision) and stores them different variables of type integer.
        multiplied_lower_bound = lowerBound * pow(10, precision);
        multiplied_upper_bound = upperBound * pow(10, precision);
        
        //Obtains a random integer value using multiplied boundaries and stores it in a float variable.
        randomDouble = getRandomInteger(multiplied_lower_bound, multiplied_upper_bound);
        
        //Divides obtained float value by pow(10,precision).
        randomDouble = randomDouble / pow(10,precision);
    }
    //The size of the number's fractional part will be two.
    else if(precision == TWO)
    {
        //Multiplies both lower and upper bound variables by pow(10,precision) and stores them different variables of type integer.
        multiplied_lower_bound = lowerBound * pow(10, precision);
        multiplied_upper_bound = upperBound * pow(10, precision);
        
        //Obtains a random integer value using multiplied boundaries and stores it in a float variable.
        randomDouble = getRandomInteger(multiplied_lower_bound, multiplied_upper_bound);
        
        //Divides obtained float value by pow(10,precision).
        randomDouble = randomDouble / pow(10, precision);
    }
    //The size of the number's fractional part will be three.
    else if(precision == THREE)
    {
        //Multiplies both lower and upper bound variables by pow(10,precision) and stores them different variables of type integer.
        multiplied_lower_bound = lowerBound * pow(10, precision);
        multiplied_upper_bound = upperBound * pow(10, precision);
        
        //Obtains a random integer value using multiplied boundaries and stores it in a float variable.
        randomDouble = getRandomInteger(multiplied_lower_bound, multiplied_upper_bound);
        
        //Divides obtained float value by pow(10,precision).
        randomDouble = randomDouble / pow(10, precision);
    }
    //The size of the number's fractional part will be four.
    else if(precision == FOUR)
    {
        //Multiplies both lower and upper bound variables by pow(10,precision) and stores them different variables of type integer.
        multiplied_lower_bound = lowerBound * pow(10, precision);
        multiplied_upper_bound = upperBound * pow(10, precision);
        
        //Obtains a random integer value using multiplied boundaries and stores it in a float variable.
        randomDouble = getRandomInteger(multiplied_lower_bound, multiplied_upper_bound);
        
        //Divides obtained float value by pow(10,precision).
        randomDouble = randomDouble / pow(10, precision);
    }
    
    return randomDouble;
    
}//end RandomNumberGenerator::getRandomDouble ()

//Generates a character randomly intended character type (it is defined by CharacterType enum).
char RandomNumberGenerator::getRandomCharacter(CharacterType characterType)
{
    char randomCharacter;
    //  In the ASCII table:
    //  The upper letters are between 65(A) and 90(Z)
    //  The lower letters are between 97(a) and 122(z)
    //  The digits are between 48(0) and 57(9)

    if(characterType == UPPER_LETTER)
    {
        randomCharacter =(char)getRandomInteger(65, 90);;
    }
    else if(characterType == LOWER_LETTER)
    {
        randomCharacter = (char)getRandomInteger(97, 122);
    }
    else if(characterType == DIGIT)
    {
        //  getRandomInteger(0, 9);
        randomCharacter = (char)getRandomInteger(48, 57);
    }
    
    return randomCharacter;
}//end RandomNumberGenerator::getRandomCharacter ()

//Generates a circle whose radius will be between given parameters minRadius and maxRadius
//and its fractional part is defined by precision (it can be integer value respectively 1,2,3,4).
Circle RandomNumberGenerator::getRandomCircle(float minRadius, float maxRadius, Precision precision)
{
    Circle circ;
    
    //circ.setRadius( getRandomDouble(minRadius, maxRadius, precision) );
    double random_Radius = getRandomDouble(minRadius, maxRadius, precision);
    circ.setRadius(random_Radius);
    
    //circ.setCenterX( getRandomFloat(minRadius, maxRadius, precision) );
    float random_Center_X = getRandomFloat(minRadius, maxRadius, precision);
    circ.setCenterX(random_Center_X);
    
    //circ.setCenterY( getRandomFloat(minRadius, maxRadius, precision) );
    float random_Center_Y = getRandomFloat(minRadius, maxRadius, precision);
    circ.setCenterY(random_Center_Y);
    
    return circ;
}//end RandomNumberGenerator::getRandomCircle ()
