#include "vex.h"

int xPosCounter;
int yPosCounter;


double newStartX;
double newStartY;
double newStartRotation;

double newStartX2;
double newStartY2;
double newStartRotation2;

void StartVirtualField(int startX, int startY, int startRotation){
   LB.resetRotation();
  RB.resetRotation();
  FieldTemplate();
  RobotTemplate(startX, startY, startRotation);

  newStartX = startX;
  newStartY = startY;
  newStartRotation = startRotation;
}

void VirtualField(){
  LB.resetRotation();
  RB.resetRotation();
  //int newMoveX = newStartX + virtualFieldX;
  //int newMoveY = newStartY + virtualFieldY;
  int rotationAmount = 90 - (newStartRotation + virtualFieldRotation);

  int xPos = (virtualFieldX * cos(rotationAmount)) + newStartX;
  int yPos = newStartY - (virtualFieldY * sin(rotationAmount));
  

  StartVirtualField(xPos, yPos, rotationAmount);
  
  newStartX = xPos;;
  newStartY = yPos;
  newStartRotation = rotationAmount;
}