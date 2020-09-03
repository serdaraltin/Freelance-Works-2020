#include <iostream> 
#include <stack> 
#include <fstream>
#include "dugum.hpp"

using namespace std;

int h(Dugum *N){  
    if (N == NULL)  
        return 0;  
    return N->h;  
}  

int m(int a, int b)  { 
    if(a != b) {
        if(a < b)
            return b;
        else
            return a;       
    }
    else if (a == b)
        return a;
    return b; 
}  

int b(Dugum *N){  
    if (N == NULL)  
        return 0;  
    return h(N->nl) - h(N->nr);  
}  

Dugum* cn(Kisi* k)  {  
    Dugum* nd = new Dugum(); 
    nd-> k =  k;  
    nd->nl = NULL;  
    nd->nr = NULL;  
    nd->h = 1; 
    nd->ss.push("O");
    return(nd);  
}  

Dugum *rr(Dugum *z){  
	
    Dugum *w = z->nl;  
    Dugum *T2 = w->nr;  
    w->nr = z;  
    z->nl = T2;  
    z->h = m(h(z->nl), h(z->nr)) + 1;  
    w->h = m(h(w->nl), h(w->nr)) + 1;  
    return w;  
}  

Dugum *rl(Dugum *w){  
    Dugum *z = w->nr;  
    Dugum *T2 = z->nl;  
    z->nl = w;  
    w->nr = T2;  
    w->h = m(h(w->nl), h(w->nr)) + 1;  
    w->ss.push("A");
    z->h = m(h(z->nl), h(z->nr)) + 1;  
 	z->ss.push("Y");
    return z;  
}  
  
int ca(Kisi *k){
    int year = 2020;
    int age = year-k->b;
    return age;
}   

Dugum* ni(Dugum* nd, Kisi* k){  
	
    if (nd == NULL)  {
    	Dugum * nf = cn(k);
        return(nf);  
    }
    if (ca(k) < ca(nd->k)){
    	nd->ss.push("D");
    	nd->nr->ss.push("D");
        nd->nl = ni(nd->nl, k);  
    }	
    else if (ca(k) > ca(nd->k))
        nd->nr = ni(nd->nr, k);  
    else
        return nd;  
    nd->h = 1 + m(h(nd->nl), h(nd->nr));  
    int balance = b(nd);  
    if (balance > 1 && ca(k) < ca(nd->nl->k))
        return rr(nd);  
    if (balance < -1 && ca(k) > ca(nd->nr->k)){
    	nd->ss.push("D");
        return rl(nd);  
    }
    if (balance < -1 && ca(k) < ca(nd->nr->k)){  
    	nd->nr = rr(nd->nr); 
        return rl(nd);  
    }  
     if (balance > 1 && ca(k) > ca(nd->nl->k)){ 
        nd->nl = rl(nd->nl);  
        return rr(nd);  
    }  
    return nd;  
}  

void ord(Dugum *firstNode){  
    if(firstNode != NULL)  {  
    	ord(firstNode->nl);  
        ord(firstNode->nr);  

        cout << firstNode->k->na << ", " << firstNode->k->b << ", " << firstNode->k->w;
        cout << "   Yigit: ";

        while (!firstNode->ss.empty()) 
	    { 
	        cout << firstNode->ss.top() << " "; 
	        firstNode->ss.pop(); 
	    } 
	    cout << endl;
    }  
}  

Kisi *cp(string pna, int pb, int pw){
	Kisi *nf = new Kisi();
	nf->na = pna;
	nf->b = pb;
	nf->w = pw;
	return (nf);
} 

void fp(){
 	Dugum *fn = NULL;  
    ifstream fre("Kisiler.txt");

    string na;
    string sb;
    string sw;

    while(!fre.eof())
    {
        getline(fre,na,'#');
        getline(fre,sb,'#');
        getline(fre,sw,'\n');
        int b = stoi(sb);
        int w = stoi(sw);	
        fn = ni(fn, cp(na,b,w));
    }
    fre.close();

    ord(fn);   
} 

int main(){
    fp();
}
