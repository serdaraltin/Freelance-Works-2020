/*****************************************
 * ShapePlacer.h                         *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 8: Polymorphism            *
 *****************************************/

#ifndef ShapePlacer_h
#define ShapePlacer_h

#include "Shape.h"              //To use Shape type variables.
#include <vector>               //To declare vector type array.

//Shape description must be in the following form.
// <shape type>  -<color>-
// <Visibility>  -<Center of Mass> -
// <Additional Properties>

class ShapePlacer
{
    //Private variable IS NOT ACCESSIBLE out of the class.
private:
    
    //m_shapeList vector holds lots of shapes.
    vector <Shape* > m_shapeList;
    
    //Public variables ARE ACCESSIBLE out of the class.
public:
    
    //Constructor Function of ShapePlacer Class.
    ShapePlacer();
    
    //Destructor Function of ShapePlacer Class.
    ~ShapePlacer();
    
    //Given newShape the type of Shape* will be added to vector.
    void AddNewShape(Shape* newShape);
    
    //Prints all shapes which are held the vector to console.
    void VisualizeAllShapes();
    
    //Finds the most proper shape according to the given area and returns it as Shape*.
    Shape* FindTheMostProperShape(double area);
    
};


#endif /* ShapePlacer_h */
