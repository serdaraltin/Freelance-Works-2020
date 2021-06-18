#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "studentID.txt" //dosya adi burada belirleniyor

typedef struct StudentMark
{
	char name[20];
	char surname[20];
	int midterm;
	int final;

	struct StudentMark* Next;
}STUDENT_MARK;

STUDENT_MARK* Students;

void FileRead();
void FileWrite();
void NewStudent();
void AddStudent(char*,char*,int,int);
void List();
void PrintStudent(STUDENT_MARK*);
void Menu();

int main(){
	Students = NULL;
	
	FileRead();
	Menu();
	
	return 0;
} 

void Menu(){
	FileWrite();//menu her çağrıldığında verilerde değişim ihtimaline karşı veriler dosyaya yazılıyor
	printf("\n=================================================\n");
	printf("1) Ogrencileri Listele\n");
	printf("2) Yeni Ogrenci Ekle\n");
	printf("0) Cikis\n");
	printf("=================================================\n");
	//seçim
	printf("\n\nSeciniz : ");
	int sec;
	scanf("%d",&sec);
	printf("\n");
	//seçeneğe göre işlem kısmı
	switch(sec){
		case 0:
			printf("Programdan cikiliyor...\n");
			exit(0);//programın sonlandırılması, hatasız olarak
			break;
		case 1:
			printf("------> LISTELE\n");
			List();//listeleme fonksiyonu çağrılarak veriler listeleniyor
			Menu();
			break;
		case 2:
			printf("------> EKLE\n");
			NewStudent();//yeni öğrenci eklemek için fonksiyon çağrılıyor
			Menu();
			break;	
		default:
			printf("Hatali bir secim yaptiniz !!!\n");
			Menu();
			break;
	}
	
}

void NewStudent(){
	printf("Name: ");
	char name[20];
	scanf("%s",name);

	printf("Surname: ");
	char surname[20];
	scanf("%s",surname);

	setmidterm:
	printf("Midterm: ");
	int midterm;
	scanf("%d",&midterm);
	if(midterm < 0 || midterm > 100){
		printf("Midterm 1-100 !\n");
		goto setmidterm;
	}

	setfinal:
	printf("Final: ");
	int final;
	scanf("%d",&final);
	if(final < 0 || final > 100){
		printf("Final 1-100 !\n");
		goto setfinal;
	}

	AddStudent(name,surname,midterm,final);
	return;
}

void AddStudent(char* name, char* surname, int midterm, int final){

	if(Students == NULL){
		Students = (STUDENT_MARK*)malloc(sizeof(STUDENT_MARK));
	    strcpy(Students->name,name);
		strcpy(Students->surname,surname);
		Students->midterm = midterm;
		Students->final = final;
		Students->Next = NULL;		
		return;
	}
	STUDENT_MARK *iter = Students;

	while(iter->Next != NULL)
		iter = iter->Next;
	
	STUDENT_MARK* newStudent = (STUDENT_MARK*)malloc(sizeof(STUDENT_MARK));
	strcpy(newStudent->name,name);
    strcpy(newStudent->surname,surname);
	newStudent->midterm = midterm;
	newStudent->final = final;
	newStudent->Next = NULL;
	iter->Next = newStudent;
	return;
}

void List(){
	STUDENT_MARK *iter = Students;//Ogrenciler iter adında bir STUDENT_MARK structına atanıyor

	if(iter == NULL){//Liste boş ise
		printf("Hic kayit yok !!!\n");
		return;
	}
	printf("\n=============OGRENCI LISTESI=============\n");
	while(iter != NULL){//Listenin sonuna kadar giden bir döngü oluşturuluyor
		PrintStudent(iter);//Ogrenci bilgileri yazdırılıyor
		iter = iter->Next;
	}

}

void PrintStudent(STUDENT_MARK* student){
	//parametre olarak gelen ogrenci bilgisine göre ekrana yazdırma işlemi yapılıyor
	float average = (student->midterm * 0.4) + (student->final * 0.6);
	printf("Name\t: %s\nSurname : %s\nMidterm : %d\nFinal\t: %d\nAverage : %0.2f\n",
		student->name,student->surname,student->midterm,student->final,average);
	printf("=====================================\n");
}

void FileRead(){
	if(!fopen(FILE_NAME,"r")){
		printf("Dosya okunamadi!\n");
		return;
	}
	FILE *file;
	file = fopen(FILE_NAME,"r");

	while(!feof(file)){
		char *name = (char*)malloc(sizeof(char)*20);
		char *surname = (char*)malloc(sizeof(char)*20);
		int midterm;
		int final;
		fscanf(file,"%s %s %d %d",name,surname,&midterm,&final);
		if(strcmp(name,"") != 0)
			AddStudent(name,surname,midterm,final);
	}
	fclose(file);
	return;
}

void FileWrite(){
	if(!fopen(FILE_NAME,"w")){
		printf("Dosya yazilamadi!\n");
		return;
	}
	FILE *file;
	file = fopen(FILE_NAME,"w");

	STUDENT_MARK *iter = Students;

	while(iter != NULL){
		if(strcmp(iter->name,"") != 0)	
			fprintf(file, "%s %s %d %d \n",iter->name,iter->surname,iter->midterm,iter->final);
		iter = iter->Next;		
	}
	fclose(file);
	return;
}
