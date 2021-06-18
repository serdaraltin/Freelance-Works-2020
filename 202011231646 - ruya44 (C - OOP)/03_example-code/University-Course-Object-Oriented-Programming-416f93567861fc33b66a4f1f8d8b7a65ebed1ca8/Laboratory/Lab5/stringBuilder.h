/*****************************************
 * StringBuilder.h                       *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 5: Classes And Objects-II  *
 *****************************************/

#include <sstream>                  //  To create an object from sstream class.
#include <vector>                   //  To create an object from vector class.
using namespace std;                //  To use cin and cout functions under the std namespace.

//Performs string appending, removing operations for some primitive data types (int, float, double, char)
class StringBuilder
{
    stringstream stream;        //stream objects is created from stringstream class.
    
public:
    //All append functions are used to perform string appending operation.
    StringBuilder& Append (const string& data);
    StringBuilder& Append (int data);
    StringBuilder& Append (float data);
    StringBuilder& Append (double data);
    StringBuilder& Append (char data);
    StringBuilder& AppendNewLineCharacter ();
    
    //Removes the content of the stream object.
    StringBuilder& Clear ();
    
    //Checks the stream object contents and returns true if given string is located in the stream, otherwise false.
    bool Contains (const string& str);
    
    //Removes the character at the given index.
    StringBuilder& RemoveAt (int index);
    
    //Returns the content of the stream object
    string GetData ();
    
    //Removes all characters which is equal to the given character in the stream objects.
    StringBuilder& Remove (char removeChar);
    
    //Removes characters starting from the given index until given charCount removed.
    StringBuilder& Remove (int startIndex, int charCount);
    
    //Removes all occurrences of the given string from the stream.
    StringBuilder& Remove (const string& removeString);
    
    //Replaces all occurrences of the given string by the newstring.
    StringBuilder& Replace (const string& replacedString, const string& newString);
    
    //Splits the  
    vector<string> Split(const string& character);
    
    //Adds the given string to stringVector.
    void Join (const vector<string>& stringVector, const string& mergeCharacter);
    
    StringBuilder();
    ~StringBuilder();
};
