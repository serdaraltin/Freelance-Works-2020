
while 1:
    girdi=int(input("Bir tamsayi giriniz:"))
    if girdi != 0:
        if girdi >= 100:
            print("Sicak")
        elif girdi <= 60:
            print("Soguk")
        else:
            print(girdi)
           
