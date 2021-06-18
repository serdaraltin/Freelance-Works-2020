#include <iostream>
#include <fstream>
#include <list>

#define DOSYA "words.txt"

using namespace std;

//"Erişmekistedikleribirhedefiolmayanlarçalışmaktanzevkalmazlar"

string cumle = "Erişmekistedikleribirhedefiolmayanlarçalışmaktanzevkalmazlar";


void DosyaOku(list<string>& kelimeler);

int main()
{

   list<string> kelimeler;
   DosyaOku(kelimeler);

   for (auto kelime=kelimeler.rend(); kelime!=kelimeler.begin(); kelime++)
   {
       cout << kelime->c_str() << endl;
   }
   

}

void DosyaOku(list<string>& kelimeler)
{
    int i = 0;
    ifstream girdi(DOSYA);
    
    string kelime;
    while (getline(girdi,kelime))
    {
        kelimeler.push_back(kelime);
    }
    


    return;
}