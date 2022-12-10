class Car {
public:
    Car(double x_, double y_, double fuelTank_, double fuelEfficiency_); // constructor
    Car(const Car & other); // copy constructor

    double getDistance(double dstX, double dstY);
    double fuelAfterDrive(double dstX, double dstY);
    int moveTo(double dstX, double dstY); // m

    // basic functions
    double getX();
    double getY();
    double getFuelTank();
    double getFuelEfficiency();
    double getFuelAmount();
    void setX(double newX);
    void setY(double newY);
    void setFuelAmount(double newFuelAmount);
private:
    double x;
    double y;
    double fuelTank;
    double fuelEfficiency;
    double fuelAmount;
};

class Bus {
public: 
    Bus(double x_, double y_, double fuelTank_, double fuelEfficiency_, int maxPassengers_, std::vector stopNumbers_, double gasPenalty_));
    Bus(const Bus & other);

    std::list<> generateRoute();
};
