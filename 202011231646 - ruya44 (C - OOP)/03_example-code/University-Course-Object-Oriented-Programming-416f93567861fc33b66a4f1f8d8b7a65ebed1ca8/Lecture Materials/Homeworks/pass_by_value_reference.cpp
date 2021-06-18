#include <iostream>
using namespace std;

int increment (int i);
int decrement (int& );
int main (){
//    int value = 3;
//    int &ref = value;
//    cout<<value<<endl<<ref<<endl;
//    cout<<&value<<endl<<&ref<<endl;

    //Değer parametresi (pass by value)
    //Fonksiyonun ayrı bir değişkeni olur ve verilen değişken ona kopyalanır.
    //Verilen değişkende herhangi bir değişiklik olmaz.
    
    int value = 5, result;
    result = increment(value);
    cout<<"The address of the result:\t"<<&result<<endl;
    cout<<"The value of the result is:\t"<<result<<endl;
    decrement(result);
    cout<<"The value of the result is:\t"<<result<<endl;
    
    return 0;
}
    //Eğer referans olarak bir değişken tanımlanırsa, fonksiyonda ayrıca bir eleman oluşturulup kopyalanmaz.
    //Verilen parametreye direkt olarak başka bir adla erişilebilir.

int increment (int i){
    cout<<"The address of the i:\t"<<&i<<endl;
    cout<<"The value of the i is:\t"<<++i<<endl;
    return i;
    
}

int decrement (int& ayse){
    ayse--;
    cout<<endl<<ayse<<endl;
    return 0;
}
