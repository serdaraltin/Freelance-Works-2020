/*****************************************
 * TestMain.cpp                          *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/

#include "Circle.h"                 //To create Circle type objects.
#include "ShapePlacer.h"            //To create ShapePlacer type objects.
#include "CustomRectangle.h"        //To create CustomRectangle type objects.
#include "RectangularPrism.h"       //To create RectangularPrism type objects.
#include "Sphere.h"                 //To create Sphere type objects.

//Holds the center of mass for two dimensional objects which are Circle and CustomRectangle.
double two_centerOfMass[2] = { 2,2 };

//Holds the center of mass for two dimensional objects which are Sphere and RectangularPrism.
double three_centerOfMass[3] = { 3,3,3 };

int main ()
{
    //Holds the shapes. (Container)
    ShapePlacer test_shapePlacer;
    
    //Shapes will be created.
    Shape* shapeForTest;
    
    //Two Dimensional Shapes
    shapeForTest = new Circle(3      ,two_centerOfMass,"Orange",true);
    test_shapePlacer.AddNewShape(shapeForTest);
    
    shapeForTest = new CustomRectangle(4,5,two_centerOfMass,"Blue",true);
    test_shapePlacer.AddNewShape(shapeForTest);
    
    
    //Three Dimensional Shapes
    shapeForTest = new Sphere(4     ,three_centerOfMass,"Red",true);
    test_shapePlacer.AddNewShape(shapeForTest);
    
    shapeForTest = new RectangularPrism(3,4,5,three_centerOfMass,"Dark Blue",true);
    test_shapePlacer.AddNewShape(shapeForTest);
    
    
    //Then print all of them to console.
    test_shapePlacer.VisualizeAllShapes();
    
    
    //Find the most proper shape according to the given area, in this case it is 50.
    shapeForTest = test_shapePlacer.FindTheMostProperShape(50);
    cout<<"Given area is:\t\t50\n"
        <<"The most proper shape is:\t\t"<<shapeForTest->GetShapeDescription()<<endl;
    
}//end main ()
