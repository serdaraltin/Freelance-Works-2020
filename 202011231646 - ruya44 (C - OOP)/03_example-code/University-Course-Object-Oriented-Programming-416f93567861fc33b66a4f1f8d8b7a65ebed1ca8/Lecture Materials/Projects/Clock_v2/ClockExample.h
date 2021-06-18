#include <iostream>
#include <string>

class Clock {
    int hour, minute, second;
    std::string ad;
    
public:
    Clock(std::string adi){                //Constructor, başlangıç değişkenlerini atadı.
        hour = minute = second = 0;
        ad = adi;
    }
    ~Clock(){               //Nesne yok edilirken çağrılacak fonksiyon.
        std::cout<<"Aha,"<<ad<<" yok oldu!\n";
    }
    
    void setTime(int forHour,int forMinute, int forSecond);                //Zamanı atama işlemi
    void getTime(int& forHour,int& forMinute, int& forSecond)const;             //Zamana erişim
    void printTime()const;                      //Zamanı gösterme
    void incrementSeconds();                    //Birer saniye arttırsın.
    void incrementMinutes();                    //Birer dakika arttırsın.
    void incrementHours();                      //Birer saat arttırsın.
    bool equalTime(const Clock& )const;         //İki zamanın eşitlik durumunu karşılaştırma işlemi
};
