#include <iostream>
using namespace std;

class Seat
{
private:
  string comfortabilityInfo;
  bool seatWarmer;

public:
  Seat(string _comInfo, bool _seatWaemer) : comfortabilityInfo(_comInfo), seatWarmer(_seatWaemer) {}

  void setComfortability(string _comInfo) { comfortabilityInfo = _comInfo; }
  void setSeatWarmer(bool _warmer) { seatWarmer = _warmer; }

  string getComfortability() { return comfortabilityInfo; }
  bool getSeatWarmer() { return seatWarmer; }

  void display()
  {
    cout << "Comfortability : " << comfortabilityInfo << '\n';
    string presence = seatWarmer ? "yes" : "no";
    cout << "Presence of Seat Warmer: " << presence << '\n';
  }
};

class Wheel
{
private:
  int circumference;

public:
  Wheel(int _circumference) : circumference(_circumference) {}

  void setCircumference(int _circumference) { circumference = _circumference; }

  int getCircumference() { return circumference; }

  void display()
  {
    cout << "Circumference: " << circumference << '\n';
  }
};

class Engine
{
private:
  double MaximumFuelConsumptionRate;
  double MaximumEnergyProductionRate;
  double AverageRPM;

public:
  Engine(double _maxFuel, double _maxEnergy, double _avgRPM) : MaximumFuelConsumptionRate(_maxFuel), MaximumEnergyProductionRate(_maxEnergy), AverageRPM(_avgRPM) {}

  void setMaxFuel(double _maxFuel) { MaximumFuelConsumptionRate = _maxFuel; }
  void setMaxEnergy(double _maxEnergy) { MaximumEnergyProductionRate = _maxEnergy; }
  void setAvgRPM(double _avgRPM) { AverageRPM = _avgRPM; }

  double getMaxFuel() { return MaximumFuelConsumptionRate; }
  double getMaxEnergy() { return MaximumEnergyProductionRate; }
  double getAvgRPM() { return AverageRPM; }

  void display()
  {
    cout << "Maximum Fuel Consumption Rate: " << MaximumFuelConsumptionRate << '\n';
    cout << "Maximum Energy Production Rate: " << MaximumEnergyProductionRate << '\n';
    cout << "Average RPM: " << AverageRPM << '\n';
  }
};

class Door
{
private:
  string openingMode;

public:
  Door(string _mode) : openingMode(_mode) {}

  void setOpeningMode(string _mode) { openingMode = _mode; }

  string getOpenngMode() { return openingMode; }

  void display()
  {
    cout << "Opening Mode: " << openingMode << '\n';
  }
};

class Car
{
private:
  Seat *seat;
  Wheel *wheel;
  Engine *engine;
  Door *door;
  double maximumAcceleration;
  double fuelCapacity;

public:
  Car(Seat *_seat, Wheel *_wheel, Engine *_engine, Door *_door, double _maxAcc, double _fuelCap) : seat(_seat), wheel(_wheel), engine(_engine), door(_door), maximumAcceleration(_maxAcc), fuelCapacity(_fuelCap) {}

  void setSeat(Seat *_seat) { seat = _seat; }
  void setWheel(Wheel *_wheel) { wheel = _wheel; }
  void setEngine(Engine *_engine) { engine = _engine; }
  void setDoor(Door *_door) { door = _door; }
  void setMaxAcc(double _maxAcc) { maximumAcceleration = _maxAcc; }
  void setFuelCap(double _fuelCap) { fuelCapacity = _fuelCap; }

  Seat *setSeat() { return seat; }
  Wheel *setWheel() { return wheel; }
  Engine *setEngine() { return engine; }
  Door *setDoor() { return door; }
  double setMaxAcc() { return maximumAcceleration; }
  double setFuelCap() { return fuelCapacity; }

  void display()
  {
    cout << "Seat Info: \n";
    seat->display();

    cout << "Wheel Info:\n";
    wheel->display();

    cout << "Engine Info:\n";
    engine->display();

    cout << "Door Info:\n";
    door->display();

    cout << "Maximum Acceleration: " << maximumAcceleration << '\n';
    cout << "Fuel Capacity: " << fuelCapacity << '\n';
  }
};
int main()
{
  Seat seat1(static_cast<string>("Pleasent"), true);
  Wheel wheel1(29);
  Engine engine1(12, 54, 250);
  Door door1(static_cast<string>("Sideways"));

  Car car1(&seat1, &wheel1, &engine1, &door1, 12, 40);

  car1.display();
}