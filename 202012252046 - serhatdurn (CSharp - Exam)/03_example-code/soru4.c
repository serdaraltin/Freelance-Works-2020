#include <stdio.h>
#include <stdlib.h>

int a[2][2] = {{-1,3},{9,-3}};
int b[2][2] = {{0,5},{-2,4}};

void menu();

void matrisToplami(){
    int toplam[2][2];

    int i,j;

    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            toplam[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("Matris Toplami:\n");
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            printf("%3d ",toplam[i][j]);
        }
        printf("\n");
    }
}

void matrisCarpimi(){
    int carpim[2][2];

    int i,j,k;

    for(i=0;i<2;i++)    
    {    
        for(j=0;j<2;j++)    
        {    
            carpim[i][j]=0;    
            for(k=0;k<2;k++)    
            {    
                carpim[i][j]+=a[i][k]*b[k][j];    
            }    
        }    
    }
    printf("Matris Carpimi:\n");
    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            printf("%3d ",carpim[i][j]);
        }
        printf("\n");
    }

   
}

void altmenu(){
    printf("A matrisi 1. satir (orn > 5 3):");
    scanf("%d %d",&a[0][0],&a[0][1]);
    printf("A matrisi 2. satir (orn > 5 3):");
    scanf("%d %d",&a[1][0],&a[1][1]);

    printf("B matrisi 1. satir (orn > 5 3):");
    scanf("%d %d",&b[0][0],&b[0][1]);
    printf("B matrisi 2. satir (orn > 5 3):");
    scanf("%d %d",&b[1][0],&b[1][1]);
    return;
}

int main(){
    menu();
}


void menu(){
    printf("1-Matrislerin Toplami\n");
    printf("2-Matrislerin Carpimi\n");
    printf("3-Matrisleri ben girmek istiyorum\n");
    printf("4-Cikis\n\n");
    printf("Seciminiz:");
    int secim;
    scanf("%d",&secim);
    switch (secim)
    {
    case 1:
        matrisToplami();
        break;
    case 2:
        matrisCarpimi();
        break;
    case 3:
        altmenu();
        break;
    case 4:
        printf("Programdan cikiliyor...\n");
        exit(0);
        break;
    default:
        printf("Hatali secim, tekrar deneyiniz\n");
        break;
    }
    printf("\n");
    menu();

}