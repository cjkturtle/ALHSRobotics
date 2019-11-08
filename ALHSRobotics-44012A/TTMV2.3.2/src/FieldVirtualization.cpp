#include "vex.h"

int xPosCounter;
int yPosCounter;


double newStartX;
double newStartY;
double newStartRotation;

double newStartX2;
double newStartY2;
double newStartRotation2;

double xPos;
double yPos;

void StartVirtualField(int startX, int startY, int startRotation){
  FieldTemplate();
  RobotTemplate(startX + 3, startY + 3, startRotation);

  newStartX = startX + 3;
  newStartY = startY + 3;
  newStartRotation = startRotation;
}

void VirtualField(){
  FieldTemplate();
  GyroCurrent();
  //int preRotationAmount = newStartRotation + virtualFieldRotation;
  //int rotationAmount = preRotationAmount;
  int rotationAmount = currentGyro;

  if((rotationAmount > 0) && (rotationAmount < 90)){
    
    xPos = newStartX + (virtualFieldX * sin(rotationAmount));
    yPos = newStartY + (virtualFieldY * cos(rotationAmount));
  

    RobotTemplate(xPos, yPos, rotationAmount);
  
    newStartX = xPos;
    newStartY = yPos;
    newStartRotation = rotationAmount;
    virtualFieldX = 0;		
    virtualFieldY = 0;
    virtualFieldRotation = 0;
   }

  else if((rotationAmount > 90) && (rotationAmount < 180 )){

    xPos = newStartX - fabs(virtualFieldX * cos((rotationAmount - 90)));
    yPos = newStartY + fabs(virtualFieldY * sin((rotationAmount - 90)));
  

    RobotTemplate(xPos, yPos, rotationAmount);
  
    newStartX = xPos;
    newStartY = yPos;
    newStartRotation = rotationAmount;
    virtualFieldX = 0;		
    virtualFieldY = 0;
    virtualFieldRotation = 0;
    }

  else if((rotationAmount > 180) && (rotationAmount < 270)){

    xPos = newStartX - fabs(virtualFieldX * sin((rotationAmount - 180)));
    yPos = newStartY - fabs(virtualFieldY * cos((rotationAmount - 180)));
  

    RobotTemplate(xPos, yPos, rotationAmount);
  
    newStartX = xPos;
    newStartY = yPos;
    newStartRotation = rotationAmount;
    virtualFieldX = 0;		
    virtualFieldY = 0;
    virtualFieldRotation = 0;
    }

  else if((rotationAmount > 270) && (rotationAmount < 360)){

    xPos = newStartX - (virtualFieldX * (sin(rotationAmount)));
    yPos = newStartY - (virtualFieldY * (cos((rotationAmount))));
  

    RobotTemplate(xPos, yPos, rotationAmount);
  
    newStartX = xPos;
    newStartY = yPos;
    newStartRotation = rotationAmount;
    virtualFieldX = 0;		
    virtualFieldY = 0;
    virtualFieldRotation = 0;
   }
  else if(rotationAmount == 0){
    
    xPos = newStartX + (virtualFieldX * 1);
    yPos = newStartY;
  

    RobotTemplate(xPos, yPos, rotationAmount);
  
    newStartX = xPos;
    newStartY = yPos;
    newStartRotation = rotationAmount;
    virtualFieldX = 0;		
    virtualFieldY = 0;
    virtualFieldRotation = 0;
   }
   else if(rotationAmount == 90){
      xPos = newStartX;
      yPos = newStartY + (virtualFieldY);
  

      RobotTemplate(xPos, yPos, rotationAmount);
  
      newStartX = xPos;
      newStartY = yPos;
      newStartRotation = rotationAmount;
      virtualFieldX = 0;		
      virtualFieldY = 0;
      virtualFieldRotation = 0;
   }

   else if(rotationAmount == 180){
      xPos = newStartX - virtualFieldX;
      yPos = newStartY;
  

      RobotTemplate(xPos, yPos, rotationAmount);
  
      newStartX = xPos;
      newStartY = yPos;
      newStartRotation = rotationAmount;
      virtualFieldX = 0;		
      virtualFieldY = 0;
      virtualFieldRotation = 0;
   }
   

  else{
    
  }

  Brain.Screen.setFillColor(transparent);
  Brain.Screen.setPenColor(white);
  Brain.Screen.printAt(151, 20, "A: %1.0d", rotationAmount);
  Brain.Screen.printAt(151, 40, "X: %1.0f", xPos);
  Brain.Screen.printAt(151, 60, "Y: %1.0f", yPos);
}