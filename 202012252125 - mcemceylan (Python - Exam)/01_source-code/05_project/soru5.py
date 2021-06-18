def sum_elements(A,m,n):
    toplam=0
    for satir in range(m):
        for sutun in range(n):
            toplam = toplam + A[satir][sutun]
    return toplam


A = [[1, 3], [1,1]]

print(sum_elements(A,2,2))
