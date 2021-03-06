#include "vex.h"

void FieldTemplate(){

  Brain.Screen.setPenWidth(1);
  Brain.Screen.setPenColor(black);

  Brain.Screen.setFillColor(black);
  Brain.Screen.drawRectangle(1, 1, 2, 148);
  Brain.Screen.drawRectangle(1, 1, 148, 2);
  Brain.Screen.drawRectangle(1, 147, 148, 2);
  Brain.Screen.drawRectangle(147, 1, 2, 148);
  
  Brain.Screen.setFillColor(white);
  Brain.Screen.drawRectangle(3, 3, 24, 24);
  Brain.Screen.drawRectangle(51, 3, 24, 24);
  Brain.Screen.drawRectangle(75, 3, 24, 24);
  Brain.Screen.drawRectangle(123, 3, 24, 24);

  Brain.Screen.drawRectangle(27, 27, 24, 24);
  Brain.Screen.drawRectangle(51, 27, 24, 24);
  Brain.Screen.drawRectangle(75, 27, 24, 24);
  Brain.Screen.drawRectangle(99, 27, 24, 24);

  Brain.Screen.drawRectangle(3, 51, 24, 24);
  Brain.Screen.drawRectangle(27, 51, 24, 24);
  Brain.Screen.drawRectangle(51, 51, 24, 24);
  Brain.Screen.drawRectangle(75, 51, 24, 24);
  Brain.Screen.drawRectangle(99, 51, 24, 24);
  Brain.Screen.drawRectangle(123, 51, 24, 24);

  Brain.Screen.drawRectangle(3, 75, 24, 24);
  Brain.Screen.drawRectangle(27, 75, 24, 24);
  Brain.Screen.drawRectangle(51, 75, 24, 24);
  Brain.Screen.drawRectangle(75, 75, 24, 24);
  Brain.Screen.drawRectangle(99, 75, 24, 24);
  Brain.Screen.drawRectangle(123, 75, 24, 24);

  Brain.Screen.drawRectangle(3, 99, 24, 24);
  Brain.Screen.drawRectangle(27, 99, 24, 24);
  Brain.Screen.drawRectangle(51, 99, 24, 24);
  Brain.Screen.drawRectangle(75, 99, 24, 24);
  Brain.Screen.drawRectangle(99, 99, 24, 24);
  Brain.Screen.drawRectangle(123, 99, 24, 24);

  Brain.Screen.drawRectangle(3, 123, 24, 24);
  Brain.Screen.drawRectangle(27, 123, 24, 24);
  Brain.Screen.drawRectangle(51, 123, 24, 24);
  Brain.Screen.drawRectangle(75, 123, 24, 24);
  Brain.Screen.drawRectangle(99, 123, 24, 24);
  Brain.Screen.drawRectangle(123, 123, 24, 24);

  Brain.Screen.setFillColor(red);
  Brain.Screen.drawRectangle(27, 3, 24, 24);
  Brain.Screen.drawRectangle(3, 27, 24, 24);

  Brain.Screen.setPenWidth(0);
  Brain.Screen.drawRectangle(3, 13, 15, 2);
  Brain.Screen.drawRectangle(18, 3, 2, 10);

  Brain.Screen.drawRectangle(3, 135, 10, 2);
  Brain.Screen.drawRectangle(13, 137, 2, 10);

  Brain.Screen.setPenWidth(1);
  Brain.Screen.setFillColor(blue);
  Brain.Screen.drawRectangle(99, 3, 24, 24);
  Brain.Screen.drawRectangle(123, 27, 24, 24);

  Brain.Screen.setPenWidth(0);
  Brain.Screen.drawRectangle(130, 3, 2, 10);
  Brain.Screen.drawRectangle(132, 13, 15, 2);

  Brain.Screen.drawRectangle(137, 135, 10, 2);
  Brain.Screen.drawRectangle(135, 137, 2, 10);

  Brain.Screen.setFillColor(black);
  Brain.Screen.drawRectangle(18, 13, 2, 2);
  Brain.Screen.drawRectangle(13, 135, 2, 2);
  Brain.Screen.drawRectangle(130, 13, 2, 2);
  Brain.Screen.drawRectangle(135, 135, 2, 2);
  }

  void RobotTemplate(double preMidX, double preMidY, double deg){
    
    double midX = preMidX;
    double midY = preMidY;
    float rotatedeg = ((deg + 270)*3.1415926545)/180;
    double currentX1 = (midX - 9); 
    double currentY1 = (midY + 9); 
    double currentX2 = currentX1 + 18; 
    double currentY2 = currentY1; 
    double currentX3 = currentX1 + 18; 
    double currentY3 = currentY1 - 18; 
    double currentX4 = currentX1;
    double currentY4 = currentY1 - 18;
    

    int newCurrentX1 = (((currentX1 - midX) * (cos(rotatedeg))) - ((currentY1 - midY) * (sin(rotatedeg))) + midX);
    int newCurrentY1 = (((currentX1 - midX) * (sin(rotatedeg))) + ((currentY1 - midY) * (cos(rotatedeg))) + midY);

    int newCurrentX2 = (((currentX2 - midX) * (cos(rotatedeg))) - ((currentY2 - midY) * (sin(rotatedeg))) + midX);
    int newCurrentY2 = (((currentX2 - midX) * (sin(rotatedeg))) + ((currentY2 - midY) * (cos(rotatedeg))) + midY);

    int newCurrentX3 = (((currentX3 - midX) * (cos(rotatedeg))) - ((currentY3 - midY) * (sin(rotatedeg))) + midX);
    int newCurrentY3 = (((currentX3 - midX) * (sin(rotatedeg))) + ((currentY3 - midY) * (cos(rotatedeg))) + midY);

    int newCurrentX4 = (((currentX4 - midX) * (cos(rotatedeg))) - ((currentY4 - midY) * (sin(rotatedeg))) + midX);
    int newCurrentY4 = (((currentX4 - midX) * (sin(rotatedeg))) + ((currentY4 - midY) * (cos(rotatedeg))) + midY);

    


    Brain.Screen.setFillColor(green);
    Brain.Screen.setPenColor(purple);
    Brain.Screen.setPenWidth(5);
    Brain.Screen.drawLine(newCurrentX1, newCurrentY1, newCurrentX2, newCurrentY2);
    Brain.Screen.setPenColor(green);
    Brain.Screen.drawLine(newCurrentX2, newCurrentY2, newCurrentX3, newCurrentY3);
    Brain.Screen.drawLine(newCurrentX3, newCurrentY3, newCurrentX4, newCurrentY4);
    Brain.Screen.drawLine(newCurrentX4, newCurrentY4, newCurrentX1, newCurrentY1);
}
