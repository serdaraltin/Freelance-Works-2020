/*****************************************
 * Circle.h                              *
 *****************************************
 * IDE : Xcode                           *
 * Author : Şafak AKINCI                 *
 * Experiment 4: Classes And Objects-I   *
 *****************************************/

class Circle
{
//Public members are accessible from anywhere where the object is visible.
public:
    //Constructor function of Circle class, when a new object is created, it will be called.
    Circle();
    //Destructor function of Circle class, when object is removed, it will be called.
    ~Circle();
    
//Those are member functions. They can call from an object that is created from Circle class.
    
/*
 ***Private members of a class are accessible only from within other members of the same class.
    -->  That's why we create getter functions(also called accessor functions) to reach private members of an object
    -->  via these functions on condition that don't change them (private members will be returned but won't be changed).
 */
    
    //Returns centerX (private member) as constant (doesn't change)
    float getCenterX() const;
    //Returns centerY (private member) as constant (doesn't change)
    float getCenterY() const;
    //Returns radius (private member) as constant (doesn't change)
    double getRadius() const;
    
    //Assigns given parameter (center_X) to object's private member centerX.
    void setCenterX(float center_X);
    //Assigns given parameter (center_Y) to object's private member centerY.
    void setCenterY(float center_Y);
    //Assigns given parameter (rad) to object's private member radius.
    void setRadius(double rad);

//Private members of a class are accessible only from within other members of the same class.
private:
    float centerX;
    float centerY;
    double radius;
};
