#include <iostream>
using namespace std;
#define PI 3.141592
#include <math.h>

struct Point
{
    float x;
    float y;
};

void Point_Display(const Point& p);
double Point_Distance(const Point& p1, const Point& p2);
double Point_OriginLength(const Point& p);
double Point_Angle(const Point& p);
void Point_CartesianToPolar(const Point& p, double& r, double& theta);

int main ()
{
    Point p1;
    cout<<"Please, enter the coordinates of the Point!"<<endl;
    cin>>p1.x>>p1.y;
    
    Point p2;
    cout<<"Please, enter the coordinates of the Point!"<<endl;
    cin>>p2.x>>p2.y;
    
    Point_Display(p1);
    Point_Display(p2);
    cout<<"Distance:\t"<<Point_Distance(p1, p2)<<endl;
    cout<<"Origin Distance (p1):\t"<<Point_OriginLength(p1)<<endl;
    cout<<"Origin Distance (p2):\t"<<Point_OriginLength(p2)<<endl;
    cout<<"Angle (p1):\t"<<Point_Angle(p1)<<endl;
    cout<<"Angle (p2):\t"<<Point_Angle(p2)<<endl;
    
    double r = Point_OriginLength(p1);
    double theta = Point_Angle(p1);
    cout<<"Cartesian To Polar (p1):";
    Point_CartesianToPolar(p1, r, theta);
    
    r=Point_OriginLength(p2);
    theta=Point_Angle(p2);
    cout<<"Cartesian To Polar (p2):";
    Point_CartesianToPolar(p2, r, theta);
    
    
    
    return 0;
}

void Point_Display(const Point& p)
{
    cout<<"(\t"<<p.x<<",\t"<<p.y<<")"<<endl;
}

double Point_Distance(const Point& p1, const Point& p2)
{
    return sqrt( pow( (p2.x - p1.x), 2) + pow( (p2.y - p1.y), 2) );
}

double Point_OriginLength(const Point& p)
{
    return sqrt( pow(p.x,2) + pow(p.y, 2) );
}

double Point_Angle(const Point& p)
{
    //atan function returns the result as RADIAN.
    return ( (180 * atan(p.y / p.x) / PI ) < 0 )?
    180+(180 * atan(p.y / p.x) / PI ) : (180 * atan(p.y / p.x) / PI );
}

void Point_CartesianToPolar(const Point& p, double& r, double& theta)
{
    cout<<"\tr:\t"<<Point_OriginLength(p)<<"\ttheta:\t"<<Point_Angle(p)<<endl;
}
