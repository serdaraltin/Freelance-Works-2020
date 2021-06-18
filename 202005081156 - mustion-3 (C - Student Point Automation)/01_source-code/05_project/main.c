#include <stdio.h>
#include <stdlib.h>

#define COURSE_NAME "Fundamentals of Computer Programming"
#define COURSE_CODE "CSE114"
#define STUDENT_ARR 5

struct Student
{
	int studentId;
	char name[15];
	char lastName[15];
	float mid1Grade;
	float mid2Grade;
	float finalGrade;
	float average;
};

struct Course
{
	char courseName[40];
	char coursecode[15];
	struct Student myStudentArray[STUDENT_ARR];
	int currentStudentCount;
};


void createNewStudent(struct Course *myCourse);
void setGradeOfStudent(struct Course *myCourse);
void findAndDisplayAverage(struct Course *myCourse);
struct Student * findStudentByID(int id, struct Course *myCourse);
void displayAverageOfAllStudents(struct Course *myCourse);
void displayAverageOfAllStudentsInInterval(struct Course *myCourse);

char *myStrCpy(char *des,char *source);

int main(){
	int i;

	struct Course * myCourse = (struct Course*)malloc(sizeof(struct Course));
	myStrCpy(myCourse->courseName,COURSE_NAME);
	myStrCpy(myCourse->coursecode,COURSE_CODE);
	
	myCourse->currentStudentCount = 0;


	while(1){

		printf("1. Create new student\n");
		printf("2. Set grade of a student\n");
		printf("3. Find and display average of a student\n");
		printf("4. Display average of all student\n");
		printf("5. Display students with average in an interval\n");
		printf("0. Exit\n");
		int choice;
		scanf("%d",&choice);

		switch(choice){
			case 0:
				return 0;
				break;
			case 1:
				createNewStudent(myCourse);
				break;
			case 2:
				setGradeOfStudent(myCourse);
				break;
			case 3:
				findAndDisplayAverage(myCourse);
				break;
			case 4:
				displayAverageOfAllStudents(myCourse);
				break;
			case 5:
				displayAverageOfAllStudentsInInterval(myCourse);
				break;	

		}
	}
} 

void createNewStudent(struct Course *myCourse){
	printf("Name: ");
	char name[15];
	scanf("%s",name);

	printf("Last Name: ");
	char lastName[15];
	scanf("%s",lastName);

	printf("Id: ");
	int studentId;
	scanf("%d",&studentId);

	int currentStudentCount = myCourse->currentStudentCount;

	myStrCpy(myCourse->myStudentArray[currentStudentCount].name,name);
	myStrCpy(myCourse->myStudentArray[currentStudentCount].lastName,lastName);
	myCourse->myStudentArray[currentStudentCount].studentId = studentId;

	myCourse->currentStudentCount += 1;
	return;
}

void setGradeOfStudent(struct Course *myCourse){
	printf("Id: ");
	int studentId;
	scanf("%d",&studentId);

	struct Student *student = findStudentByID(studentId,myCourse);

	printf("Midterm 1 Grade: ");
	float mid1Grade;
	scanf("%f",&mid1Grade);

	printf("Midterm 2 Grade: ");
	float mid2Grade;
	scanf("%f",&mid2Grade);

	printf("Final Grade: ");
	float finalGrade;
	scanf("%f",&finalGrade);

	student->mid1Grade = mid1Grade;
	student->mid2Grade = mid2Grade;
	student->finalGrade = finalGrade;

	float average = (mid1Grade + mid2Grade + finalGrade) / 3;

	student->average = average;

	return;
}

void findAndDisplayAverage(struct Course *myCourse){
	printf("Id: ");
	int studentId;
	scanf("%d",&studentId);

	printf("Average is: %f\n",findStudentByID(studentId,myCourse)->average);
			
	return;
}

void displayAverageOfAllStudents(struct Course *myCourse){
	printf("Course Name: %s\n", myCourse->courseName);
	printf("Course Code: %s\n", myCourse->coursecode);

	int i = 0;
	while(i < myCourse->currentStudentCount){
		printf("Name: %s\n",myCourse->myStudentArray[i].name);
		printf("Last Name: %s\n",myCourse->myStudentArray[i].lastName);
		printf("Id: %d\n",myCourse->myStudentArray[i].studentId);
		printf("Average: %f\n",myCourse->myStudentArray[i].average);
		i++;
	}
	return;
}

void displayAverageOfAllStudentsInInterval(struct Course *myCourse){
	printf("Lowest Avg: ");
	float lowetsAvg;
	scanf("%f",&lowetsAvg);
	printf("Highest Avg: ");
	float highestAvg;
	scanf("%f",&highestAvg);


	printf("Course Name: %s\n", myCourse->courseName);
	printf("Course Code: %s\n", myCourse->coursecode);

	int i = 0;
	while(i < myCourse->currentStudentCount){
		float average = myCourse->myStudentArray[i].average;
		if(average >= lowetsAvg && average <= highestAvg){
			printf("Name: %s\n",myCourse->myStudentArray[i].name);
			printf("Last Name: %s\n",myCourse->myStudentArray[i].lastName);
			printf("Id: %d\n",myCourse->myStudentArray[i].studentId);
			printf("Average: %f\n",myCourse->myStudentArray[i].average);
		}
		i++;
	}
	return;
}

struct Student * findStudentByID(int id, struct Course *myCourse){
	int i = 0;
	while(i < myCourse->currentStudentCount){
		if(myCourse->myStudentArray[i].studentId == id){
			return &myCourse->myStudentArray[i];
		}
		i++;
	}
	return NULL;
}

char *myStrCpy(char *des,char *source){
	char *start = des;

	while(*source != '\0'){
		*des = *source;
		des++;
		source++;
	}
	*des = '\0';
	return start;
}