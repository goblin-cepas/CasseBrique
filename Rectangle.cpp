#include "Rectangle.h"
extern "C" {
#include <curses.h>
}
//Builder
RECTANGLE::RECTANGLE(double height,double width) : m_height(height), m_width(width){

}
//Destructor
RECTANGLE::~RECTANGLE(){

}
//Accessors
double RECTANGLE::getRectangleHeight() const{
  return m_height;

}

void RECTANGLE::setRectangleHeight(double NewRectangleHeight){
  m_height = NewRectangleHeight;
}

double RECTANGLE::getRectangleWidth() const{
  return m_width;
}

void RECTANGLE::setRectangleWidth(double NewRectangleWidth){
  m_width = NewRectangleWidth;
}
