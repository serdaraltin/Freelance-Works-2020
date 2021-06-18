/*****************************************
 * StringBuilder.cpp                     *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 5: Classes And Objects-II  *
 *****************************************/

#include "stringBuilder.h"          //Include header file to know function prototypes.
#include <iostream>                 //To use standart input output functions like cin and cout.

//Constructor function of StringBuilder class.
StringBuilder::StringBuilder()
{
    
}//StringBuilder()

//Destructor function of StringBuilder class.
StringBuilder::~StringBuilder()
{
    
}//~StringBuilder()

//Appends given string called data to the "stream" that is created stringstream class.
StringBuilder& StringBuilder::Append (const string& data)
{
    stream<<data;
    
    //Function's return type is StringBuilder& (Th reference of the object that is created by StringBuilder class).
    //This means that function will return the object(not its copy) that called this function.
    //Returning object enables using cascade functions.

    return (*this);
}

//Appends given int number called data to the "stream" that is created stringstream class.
StringBuilder& StringBuilder::Append (int data)
{
    stream<<data;
    
    //Function's return type is StringBuilder& (Th reference of the object that is created by StringBuilder class).
    //This means that function will return the object(not its copy) that called this function.
    //Returning object enables using cascade functions.
    
    return (*this);
}

//Appends given float number called data to the "stream" that is created stringstream class.
StringBuilder& StringBuilder::Append (float data)
{
    stream<<data;
    
    //Function's return type is StringBuilder& (Th reference of the object that is created by StringBuilder class).
    //This means that function will return the object(not its copy) that called this function.
    //Returning object enables using cascade functions.
    
    return (*this);
}

//Appends given double number called data to the "stream" that is created stringstream class.
StringBuilder& StringBuilder::Append (double data)
{
    stream<<data;
    
    //Function's return type is StringBuilder& (Th reference of the object that is created by StringBuilder class).
    //This means that function will return the object(not its copy) that called this function.
    //Returning object enables using cascade functions.
    
    return (*this);
}

//Appends given char called data to the "stream" that is created stringstream class.
StringBuilder& StringBuilder::Append (char data)
{
    stream<<data;
    
    //Function's return type is StringBuilder& (Th reference of the object that is created by StringBuilder class).
    //This means that function will return the object(not its copy) that called this function.
    //Returning object enables using cascade functions.
    
    return (*this);
}

//Appends a new line character to the "stream" that is created stringstream class.
StringBuilder& StringBuilder::AppendNewLineCharacter ()
{
    stream<<endl;               //stream<<"\n";
    
    //Function's return type is StringBuilder& (Th reference of the object that is created by StringBuilder class).
    //This means that function will return the object(not its copy) that called this function.
    //Returning object enables using cascade functions.
    
    return (*this);
}

//Erases the contents of the string, which becomes an empty string (with a length of 0 characters).
StringBuilder& StringBuilder::Clear ()
{
    //The str function of stream takes string parameter and assigns it to stream.
    stream.str("");             //string s1;        stream.str(s1);
    
    //Function's return type is StringBuilder& (Th reference of the object that is created by StringBuilder class).
    //This means that function will return the object(not its copy) that called this function.
    //Returning object enables using cascade functions.
    
    return (*this);
}

//Checks if the string contains the given string, if it is returns true.
bool StringBuilder::Contains (const string& str)
{
    //npos is a static member constant value with the greatest possible value for an element of type size_t.
    //As a return value, it is usually used to indicate no matches.
    
//size_t is an alias of one of the fundamental unsigned integer types.
//It is a type able to represent the size of any object in bytes.
    
    //The meaning of pos is "Position of the first character in the string" to be considered in the search.
    
    //If the given string is found, find function returns the pos the type of size_t.
    if(stream.str().find(str) != string::npos)
        return true;
    
    return false;
}

//Removes the character at the given index.
StringBuilder& StringBuilder::RemoveAt (int index)
{
    
    string s1 = stream.str();
    
    //Erase function erases the character according to the given position.
//If used like s1.erase(index), it will erase from given index to the end of string.
    s1.erase(s1.begin()+index);
    stream.str(s1);
    
    //Function's return type is StringBuilder& (Th reference of the object that is created by StringBuilder class).
    //This means that function will return the object(not its copy) that called this function.
    //Returning object enables using cascade functions.
    
    return (*this);
}

//Removes all characters which is equal to the given character in the stream objects.
StringBuilder& StringBuilder::Remove (char removeChar)
{
    //Gets data and assigns it to s1.
    string s1 = stream.str();
    
    //If the given character is found, find function returns the pos the type of size_t.
    size_t pos = s1.find(removeChar);
    
    while(pos != string::npos)              //If there is given character.
    {
        s1.erase( s1.begin()+pos );         //Erase the character at given position.
        pos = s1.find(removeChar);
    }
    

    stream.str(s1);
    
    //Function's return type is StringBuilder& (Th reference of the object that is created by StringBuilder class).
    //This means that function will return the object(not its copy) that called this function.
    //Returning object enables using cascade functions.
    
    return (*this);
}

//Removes charCount times character starting with startIndex.
StringBuilder& StringBuilder::Remove(int startIndex, int charCount)
{
    //Gets data and assigns it to s1.
    string s1 = stream.str();
    
    //Erases charCount times characters starting with given position.
    s1.erase(startIndex, charCount);
    
    //s1 is assigned to data not appended.
    stream.str(s1);
    
    //Function's return type is StringBuilder& (Th reference of the object that is created by StringBuilder class).
    //This means that function will return the object(not its copy) that called this function.
    //Returning object enables using cascade functions.
    
    return (*this);
}

//Removes given string(if there is more than one string, then remove all of them)  from data.
StringBuilder& StringBuilder::Remove (const string& removeString)
{
    //Gets data and assigns it to s1.
    string s1 = stream.str();
    
    //If the given character is found, find function returns the pos the type of size_t.
    size_t startIndex = s1.find(removeString);
    
    while(startIndex != string::npos)
    {
        //Erases removeString.length() times character starting with startIndex # s1.find(removestring) #
        s1.erase(startIndex, removeString.length());
        startIndex = s1.find(removeString);
    }
    
    //s1 is assigned to data not appended.
    stream.str(s1);
    
    //Function's return type is StringBuilder& (Th reference of the object that is created by StringBuilder class).
    //This means that function will return the object(not its copy) that called this function.
    //Returning object enables using cascade functions.
    
    return (*this);
}


//Removes replacedString.length() times character starting with startIndex from s1,
//and copy the given string #newString# starting with startIndex.
StringBuilder& StringBuilder::Replace (const string& replacedString, const string& newString)
{
    //Gets data and assigns it to s1.
    string s1 = stream.str();
    
    //If the given string is found, find function returns the pos the type of size_t.
    size_t startIndex = s1.find(replacedString);
    
    while(startIndex!= string::npos)
    {
        //Removes replacedString.length() times character starting with startIndex from s1,
        //and copy the given string #newString# starting with startIndex.
        s1.replace(startIndex, replacedString.length(), newString);
        startIndex = s1.find(replacedString);
    }
    
    //s1 is assigned to data not appended.
    stream.str(s1);
    
    //Function's return type is StringBuilder& (Th reference of the object that is created by StringBuilder class).
    //This means that function will return the object(not its copy) that called this function.
    //Returning object enables using cascade functions.
    
    return (*this);
}

//Returns the string data which is encapculated in stream.
string StringBuilder::GetData ()
{
    return stream.str();
}

//Splits the content of the string builder into parts according to the given split character string.
vector<string> StringBuilder::Split(const string& character)
{
    //Function will split the data as words, and they will store in a matrix, but we don't know how many words our data have.
    //We can store them into dynamic matrix, and vector class helps us here to store values without knowing the size of the matrix.
    //We also know the matrix's size using size function ( return_value.size() ).
    vector<string> return_value;
    
    //Gets data and is assigned to content.
    string content = stream.str();
    
    //The index of given character at the string.
    int idx;
    
    //If find function doesn't find the place of given character, it will return -1.
    while( ( idx=content.find(character) ) != -1)
    {
        //substr function returns a sub-string of content that starts from 0 and ends with idx(end of the word).
        string word = content.substr(0,idx);
        
        //After the sub-string is got, erase this word from content.
        content.erase(0,idx+1);
        
        //If word (the type of string) is full, push it to return_value using vector's push_back function.
        if(!word.empty())
            return_value.push_back(word);
    }
    
    //If there is still word in the content, (it is the last word) push it to return_value.
    if( ! content.empty() )
        return_value.push_back(content);
    
    //Returns a string vector not its reference.
    //Because, return_value is a local variable of this function, after it finishes, local variables will be removed.
    return return_value;
}

//Joins the given vector members by the merge character string.
void StringBuilder::Join(const vector<string>& stringVector, const string& mergeCharacter)
{
    //Clear the data.
    (*this).Clear();
    
    //Appends mergeCharacter to data after the each word that are stored in the stringVector.
    for(int i=0; i<stringVector.size(); i++)
    {
        stream<<stringVector[i];
        stream<<mergeCharacter;
    }
}
