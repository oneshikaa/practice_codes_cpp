#include <iostream>
using namespace std;
class Shape {                                                                           Output 
protected:
                  int width;                                                               
                  int height;
public:
      void setWidth(int w) {
                    width = w;    }
      void setHeight(int h) {
                       height = h;  } } ; 
class Rectangle: public Shape {
  public:
              int getArea() { 
              return (width * height); } }
 int main {
  Rectangle Rect;
  Rect.setWidth(5);
  Rect.setHeight(7);
  cout << "Total area: " << Rect.getArea() << endl;     //   Print the area of the object.
  return 0;
               }
