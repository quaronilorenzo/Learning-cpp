#include <stdlib.h>
#include <iostream>
#include <cmath>
using namespace std;
const float pi = 3.1415926535897932384;
class Circle{
    private:
        float radius;
    public:
        Circle( float r = 0.0){
            radius = r;
        }
        float aerea(float aerea = 0.0){
            return aerea = pi * pow(radius, 2);
        }
        float circumference(float circumference = 0.0){
            return circumference = ( 2 * radius ) * pi;
        }
};
int main(){
    Circle x = { 2.0 };
    cout << "The aerea of the circle is:" << x.aerea() << endl;
    cout << "The circumference of the circle is:" << x.circumference() << endl;
    
} 