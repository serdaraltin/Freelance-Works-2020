/**
* @file people.hpp
* @description Class'ın özeti
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 2020.08.28
* @author Emre Uysal
*/
using namespace std;
class People{
	public:
		People();
		People *nprsn(string pnm, int pbt, int pwei);
		string nm;
		int btd,wei;
}; 
