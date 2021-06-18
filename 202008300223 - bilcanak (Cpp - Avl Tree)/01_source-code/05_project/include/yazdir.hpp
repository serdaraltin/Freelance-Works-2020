//parametre olarak gelen düğümdeki tüm elemanları post order yöntemi ile gezip yığındaki tüm elemanlar bitene kadar yazdırma
void yazdirAgac(Dugum *kok){  
    if(kok != NULL)  {  
        //düğümün önce solu sonra sağının aynı işlemlere tabi tutulması
    	yazdirAgac(kok->dugumSol);  
        yazdirAgac(kok->dugumSag);  
        //insan bilgilerinin yazdırılması
        cout << kok->insan->isim << ", " << kok->insan->yas << ", " << kok->insan->agirlik;
        cout << "   Yigit: ";
        //yığıttaki tüm elemanlar bitene dek pop etme ve yazdırma
        while (!kok->cSt.empty()) 
	    { 
	        cout << kok->cSt.top() << " "; 
	        kok->cSt.pop(); 
	    } 
	    cout << endl;
    }  
}  
