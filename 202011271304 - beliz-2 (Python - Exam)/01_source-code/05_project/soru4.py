def crack_iphone():
    for sayi in range(0,10000):
        hane_sayisi=len(str(sayi))
        eklenecek_adet=4-hane_sayisi
        eklenecek_sifir=eklenecek_adet*"0"
        yeni_sayi=eklenecek_sifir+str(sayi)
        if test_password(yeni_sayi) != False:
            print("Sifre:",yeni_sayi)
            return

def test_password(sayi):
    if sayi == "0217":
        return [5,4,2,3]
    else:
        return False

crack_iphone()