#include <iostream>
using namespace std;


int main(){
	for(int i=1; i<= 10; i++){
		if(i<6)
			continue;
		else
			break;
		cout << "Merhaba"<<endl;
	}
} 
