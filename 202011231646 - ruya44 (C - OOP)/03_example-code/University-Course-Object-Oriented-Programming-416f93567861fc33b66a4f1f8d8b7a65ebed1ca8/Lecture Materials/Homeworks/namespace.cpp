#include <iostream>

namespace MATH2D{

	struct Coord{
		int x;
		int y;
	};

	void print(Coord c){
		std::cout<<"("<<c.x<<","<<c.y<<")"<<"\n";
	}
}

namespace MATH3D{

	struct Coord{
		int x;
		int y;
		int z;
	};

	void print(Coord c){
		std::cout<<"("<<c.x<<","<<c.y<<","<<c.z<<")"<<"\n";
	}
}

using namespace MATH2D;
int main()
{
	Coord coord1;
	coord1.x=1;
	coord1.y=2;

	print(coord1);


	MATH3D::Coord coord2;
	coord2.x=1;
	coord2.y=2;
	coord2.z=3;

	print(coord2);

	return 0;

}
