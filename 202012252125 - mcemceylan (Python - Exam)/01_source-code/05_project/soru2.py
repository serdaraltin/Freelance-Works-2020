a=10

def yazdir():
    b=20
    #a global bir değişkendir ve fonksiyon içerisinden erişilebilir
    print("Yazdir fonksiyonu ici (a): ",a) 
    #b yerel bir değişkendir ve sadece tanımlandığı alan yani fonksiyon içerisinden erişilebilir
    print("Yazdir fonksiyonu ici (b): ",b) 


yazdir()
#a değişkeni global olduğu için erişilebilir
print("Global alan (a):",a) 

#buradaki tanımlama hatalıdır çünkü b değişkeni yazdir fonsiyonu içerisinde tanımlanmıştır ve dışında kullanılamaz
#print(b) 
