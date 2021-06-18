#include <string>
using namespace std;

class Student
{
public:
	void setStudent(string _name, int _id);
	void print();
private:
	string name;
	int id;
};
