#include "C++ (2.1) Header.h"
#include <cmath>
#include <iostream>

Car::Car(double x_, double y_, double fuelTank_, double fuelEfficiency_){
    x = x_;
    y = y_;
    fuelTank = fuelTank_;
    fuelEfficiency = fuelEfficiency_;
    fuelAmount = fuelTank_; // fuel tank starts full
}
Car::Car(const Car & other) {
    x = other.getX();
    y = other.getY();
    fuelTank = other.getFuelTank();
    fuelEfficiency = other.getFuelEfficiency();
    fuelAmount = other.getFuelAmount();
}

double Car::getX(){
    return x;
}
double Car::getY(){
    return y;
}
double Car::getFuelTank(){
    return fuelTank;
}
double Car::getFuelEfficiency(){
    return fuelEfficiency;
}
double Car::getFuelAmount(){
    return fuelAmount;
}
void Car::setX(double newX){
    x = newX;
}
void Car::setY(double newY){
    y = newY;
}
void Car::setFuelAmount(double newFuelAmount){
    fuelAmount = newFuelAmount;
}

double Car::getDistance(double dstX, double dstY) {
    return sqrt((getX() - dstX)*(getX() - dstX) + (getY() - dstY)*(getY() - dstY));
}
double Car::fuelAfterDrive(double dstX, double dstY) {
    double distanceToMove = distance(this, lx, ly);
    double carRange = getFuelEfficiency()*getFuelAmount();
    return distanceToMove <= carRange ? carRange - distanceToMove : 0;
}

int Car::moveTo(double dstX, double dstY){
    double FAD = fuelAfterDrive();
    if(FAD != 0.0){
        setFuelAmount(FAD);
        setX(dstX);
        setY(dstY);
        return 1;
    }
    return 0;
}