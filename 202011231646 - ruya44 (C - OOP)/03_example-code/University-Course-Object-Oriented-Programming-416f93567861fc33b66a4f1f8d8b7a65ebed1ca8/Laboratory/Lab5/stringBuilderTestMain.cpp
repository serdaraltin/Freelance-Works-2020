/*****************************************
 * StringBuilderTestMain.cpp             *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 5: Classes And Objects-II  *
 *****************************************/

#include "stringBuilder.h"          //Include header file to know function prototypes.
#include <iostream>                 //To use standart input output functions like cin and cout.
using namespace std;                //To use cin and cout functions under the std namespace.

void TEST_Append(StringBuilder& sb)
{
    cout << "+-------------+" << endl
         << "| APPEND TEST |" << endl
         << "+-------------+" << endl;
    
    //Appends given data to stream using cascade functions.
    sb.Append("TestName1").Append(" ").Append("TestSurname1").Append(" ").Append(25).Append(" ").Append(45.2).AppendNewLineCharacter();
    
    //Appends given data to stream using cascade functions.
    sb.Append("TestName2").Append(" ").Append("TestSurname2").Append(" ").Append(24).Append(" ").Append(47.45).AppendNewLineCharacter();
    
    //Prints the data to console.
    cout << sb.GetData() << endl;
    
    //Clear the data.
    sb.Clear();
}

void TEST_Clear(StringBuilder& sb)
{
    cout << "+-------------+" << endl
         << "| CLEAR TEST  |" << endl
         << "+-------------+" << endl;
    
    //Clear the data.
    sb.Clear();
    
    //Prints the data to console.
    cout << sb.GetData() << endl;
}

void TEST_Contains(StringBuilder& sb)
{
    cout << "+----------------+" << endl
         << "| CONTAINS TEST  |" << endl
         << "+----------------+" << endl;
    
    //Appends given string to data.
    sb.Append("ESOGU");
    
    //If the given string is found, contains function will return true.
    if (sb.Contains("OGU"))
    {
        cout << "StringBuilder contains the string 'OGU'" << endl;
    }
    else
    {
        cout << "StringBuilder does not contain the string 'OGU'" << endl;
    }
    
    //If the given string is found, contains function will return true.
    if (sb.Contains("Bilgisayar"))
    {
        cout << "StringBuilder contains the string 'Bilgisayar'" << endl;
    }
    else
    {
        cout << "StringBuilder does not contain the string 'Bilgisayar'" <<endl;
    }
    
    //Clear the data.
    sb.Clear();
}

void TEST_RemoveAt(StringBuilder& sb)
{
    cout<< "+-----------------+" << endl
        << "| REMOVE AT TEST  |" << endl
        << "+-----------------+" << endl;
    
    //Appends the given string to the data.
    sb.Append("ESOGU Bilgisayar");
    
    //Remove the character that is placed at given index.
    sb.RemoveAt(1);
    
    //Prints the data to console.
    cout << sb.GetData() << endl;
    
    //Clear the data.
    sb.Clear();
}

void TEST_RemoveChar(StringBuilder& sb)
{
    cout << "+------------------------+" << endl
         << "| REMOVE CHARACTER TEST  |" << endl
         << "+------------------------+" << endl;
    
    //Appends given string to the data.
    sb.Append("ESOGU Bilgisayar");
    
    //Removes the given character from data.
    sb.Remove('a');
    
    //Prints data to console.
    cout << sb.GetData() << endl;
    
    //Clear the data.
    sb.Clear();
}

void TEST_RemoveRange(StringBuilder& sb)
{
    cout<< "+--------------------+" << endl
        << "| REMOVE RANGE TEST  |" << endl
        << "+--------------------+" << endl;
    //Appends given string to the data.
    sb.Append("ESOGU BilgisayarBilgisayar");
    
    //Removes the 10 characters starting with 16 index.
    sb.Remove(16, 10);
    
    //Prints the data to console.
    cout << sb.GetData() << endl;
    
    //Clear the data.
    sb.Clear();
}

void TEST_RemoveString(StringBuilder& sb)
{
    cout <<"+---------------------+" << endl
        << "| REMOVE STRING TEST  |" << endl
        << "+---------------------+" << endl;
    
    //Appends given strings to data.
    sb.Append("ESOGU Bilgisayar, ESOGU Bilgisayar, ESOGU Bilgisayar");
    cout << "Before Remove : " << sb.GetData() << endl;
    
    //Removes given string from data.
    sb.Remove("Bilgisayar");
    cout << "After Remove : "  << sb.GetData() << endl;
    
    //Clear the data.
    sb.Clear();
}

void TEST_Replace(StringBuilder& sb)
{
    cout<< "+----------------------+" << endl
        << "| REPLACE STRING TEST  |" << endl
        << "+----------------------+" << endl;
    
    //Clear the data.
    sb.Clear();
    
    //Appends given string to data.
    sb.Append("ESOGU BILGI, ESOGU BILGI, ESOGU BILGI");
    cout << "Before Replace : " << sb.GetData() << endl;
    
    //Replaces given two strings.
    sb.Replace("BILGI", "Bilgisayar");
    cout << "After Replace : " <<sb.GetData() << endl;
    
    //Clear the data.
    sb.Clear();
}

void TEST_QUIZ(StringBuilder& sb)
{
    cout<<"+-----------------------+"<<endl
        <<"| Test Sentence Content |"<<endl
        <<"+-----------------------+"<<endl;
    
    //Appends given string to data.
    sb.Append("This   is a   test sentence for     the execution   that    ");
    
    //Split contents according to space, and function returns string vector.
    vector<string> rv = sb.Split(" ");
    for(int i=0; i<rv.size(); i++)
        cout<<i<<". word: "<<rv[i]<<endl;
    
    cout<<"+-----------+"<<endl
        <<"| Join Test |"<<endl
        <<"+-----------+"<<endl;
    
    //Merge , after the each word of the data.
    sb.Join(rv, ",");
    
    //Prints data to console.
    cout<<sb.GetData();
}

int main()
{
    StringBuilder strBuilder;
    
    TEST_Append(strBuilder);
    TEST_Clear(strBuilder);
    TEST_Contains(strBuilder);
    TEST_RemoveAt(strBuilder);
    TEST_RemoveChar(strBuilder);
    TEST_RemoveRange(strBuilder);
    TEST_RemoveString(strBuilder);
    TEST_Replace(strBuilder);
    TEST_QUIZ(strBuilder);
    
    return 0;
}//end main ()
