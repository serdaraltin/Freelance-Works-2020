def print_pass(dictA,dictB):
    for anahtar in dictB:
        if dictB.get(anahtar) >= 70:
            print(dictA.get(anahtar),dictB.get(anahtar))

dictA = {"AVeli": "Ali Veli", "OBulbul": "Osman Bülbül", "ZTekin": "Zeynep Tekin"}
dictB = {"AVeli": 85, "OBulbul": 90, "ZTekin": 55}

print_pass(dictA,dictB)