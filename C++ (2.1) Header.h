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

protected:
    double x;
    double y;
    double fuelTank;
    double fuelEfficiency;
    double fuelAmount;
};

class Bus : public Car {
public: 
    Bus(double x_, double y_, double fuelTank_, double fuelEfficiency_, int maxPassengers_, std::vector<int> stopNumbers_, double gasPenalty_));
    Bus(const Bus & other);

    // std::list<> generateRoute();
};




typedef struct Provider {
    std::string provider;
    std::string role;
} Provider;

typedef struct Patient {
    std::string patient;
    std::string condition;
} Patient;

class MedicalCenter {
public:
    MedicalCenter();
    MedicalCenter(const MedicalCenter & other);
    ~MedicalCenter();
    std::list<Provider> getProviders();
    std::list<Patient> getPatients();
    void appendPatient(Patient patient_);
    void appendProvider(Provider provider_);
    

protected:
    std::list<Provider> providers;
    std::list<Patient> patients;
};



class Ambulance : 
