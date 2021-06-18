#String(katar) türünde tanımlanan bir değer değişkene atanır ve Python yorumlayıcısı bunun türünü otomatik olarak algılar
a="Ahmet"
#Integer(tam sayi) türünde tanımlanan bir değer değişkene atanır ve Python yorumlayıcısı bunun türünü otomatik olarak algılar
b=5
#Float(tgerçel sayi) türünde tanımlanan bir değer değişkene atanır ve Python yorumlayıcısı bunun türünü otomatik olarak algılar
c=3.2
#Boolean(doğru/yanlış) türünde tanımlanan bir değer değişkene atanır ve Python yorumlayıcısı bunun türünü otomatik olarak algılar
d=True

#tip değerlerini(sınıf) ekranda görebilmek için type fonksiyonu kullanılarak tip değeri alınmak istenen değişken parametre olarak verilir
print("Deger:",a,"\tTip:",type(a)) #a değişkeni str sınıfına dahildir yani bir string ifadedir
print("Deger:",b,"\tTip:",type(b)) #b değişkeni int sınıfına dahildir yani bir integer ifadedir
print("Deger:",c,"\tTip:",type(c)) #c değişkeni float sınıfına dahildir yani bir float ifadedir
print("Deger:",d,"\tTip:",type(d)) #d değişkeni bool sınıfına dahildir yani bir bool ifadedir

#Derlemeli dillerde (örnek C dili) değişkenin türü önceden belirtilmelidir, python programlama dilinde dinamik olduğundan ve
#otomatik olarak belirlendiğinden esneklik sağlamaktadır