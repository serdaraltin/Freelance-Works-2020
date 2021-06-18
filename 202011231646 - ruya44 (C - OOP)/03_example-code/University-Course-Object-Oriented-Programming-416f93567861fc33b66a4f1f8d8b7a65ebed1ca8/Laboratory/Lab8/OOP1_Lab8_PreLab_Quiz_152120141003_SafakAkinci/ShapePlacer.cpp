/*****************************************
 * ShapePlacer.cpp                       *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/

#include "ShapePlacer.h"        //To know function prototypes of ShapePlacer Class.


//Constructor Function of ShapePlacer Class.
ShapePlacer::ShapePlacer()
{
    
}

//Destructor Function of ShapePlacer Class.
ShapePlacer::~ShapePlacer()
{
    
}

//Given newShape the type of Shape* will be added to vector.
void ShapePlacer::AddNewShape(Shape* newShape)
{
    m_shapeList.push_back(newShape);
}

//Prints all shapes which are held the vector to console.
void ShapePlacer::VisualizeAllShapes()
{
    for(int i=0; i<m_shapeList.size(); i++)
        cout<<m_shapeList[i]->GetShapeDescription()<<endl;
    
}

//Finds the most proper shape according to the given area and returns it as Shape*.
Shape* ShapePlacer::FindTheMostProperShape(double area)
{
    double* differenceArray = new double [m_shapeList.size()];
    
    //There should be one more array that will hold the differences between shape's area and given area.
    for(int i=0; i<m_shapeList.size(); i++)
    {
        differenceArray[i] = m_shapeList[i]->CalculateSurfaceArea() - area;
        
        //There can be negative numbers in the differenceArray, we should take absolute of them.
        if(differenceArray[i] < 0 )
            differenceArray[i] *= -1;
    }
    
    //Then, we should find the minimum number in the array, actually INDEX its number.
    double minimumNumberInTheArray  = differenceArray[0];
    int index = 0;
    
    for(int i=0; i<m_shapeList.size(); i++)
        if( differenceArray[i]< minimumNumberInTheArray )
        {
            minimumNumberInTheArray = differenceArray[i];
            index = i;
        }
    
    //The minimum difference and its index are found!
    
    return m_shapeList[ index ];
}
