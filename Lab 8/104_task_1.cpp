#include <iostream>
#include <ctime>
using namespace std;

time_t t = time(NULL);
tm *t_ptr = localtime(&t);

class Animal
{
private:
  string nameOfAnimal, habitat_area, sound;
  int weight, height, birthYear;

public:
  Animal() : nameOfAnimal(""), habitat_area(""), sound(""), weight(0), height(0), birthYear(2021) {}
  Animal(string _name, string _habitat, string _sound, int _weight, int _height, int _birth) : nameOfAnimal(_name), habitat_area(_habitat), sound(_sound), weight(_weight), height(_height), birthYear(_birth > 2021 ? 2021 : _birth) {}

  void setNameOfAnimal(string _nameOfAnimal) { nameOfAnimal = _nameOfAnimal; }
  void setHabitatArea(string _habitatArea) { habitat_area = _habitatArea; }
  void setSound(string _sound) { sound = _sound; }
  void setWeight(int _weight) { weight = _weight; }
  void setHeight(int _height) { height = _height; }
  void setBirthYear(int _birhYear)
  {
    if (_birhYear > 2021)
    {
      cout << "Birth Year can't be geater than 2021!\n";
      return;
    }
    birthYear = _birhYear;
  }

  string getNameOfAnimal() { return nameOfAnimal; }
  string getHabitatArea() { return habitat_area; }
  string getSound() { return sound; }
  int getWeight() { return weight; }
  int getHeight() { return height; }
  int getBirthYear() { return birthYear; }
  int getAge() { return birthYear - (t_ptr->tm_year + 1900); }
  void getInformation()
  {
    cout << "Name of Animal: " << nameOfAnimal << '\n';
    cout << "Habitat Area: " << habitat_area << '\n';
    cout << "Sound: " << sound << '\n';
    cout << "Weight: " << weight << '\n';
    cout << "Height: " << height << '\n';
    cout << "Birth Year: " << birthYear << '\n';
  }
  void changeWeight(int _pounds) { weight = _pounds; }
  void vocalize() { cout << sound; }
};

class Cow : public Animal
{
public:
  Cow() { setSound("moo"); }
  Cow(string _name, string _habitat, string _sound, int _weight, int _height, int _birth) : Animal(_name, _habitat, _sound, _weight, _height, _birth) {}
};

class Chicken : public Animal
{
public:
  Chicken() { setSound("buck buck"); }
  Chicken(string _name, string _habitat, string _sound, int _weight, int _height, int _birth) : Animal(_name, _habitat, _sound, _weight, _height, _birth) {}
};

class Cat : public Animal
{
public:
  Cat() { setSound("meow"); }
  Cat(string _name, string _habitat, string _sound, int _weight, int _height, int _birth) : Animal(_name, _habitat, _sound, _weight, _height, _birth) {}
};

int main()
{
  Animal am;
  cout << am.getBirthYear() << "\n";
  cout << am.getAge() << "\n";
  Cow c1;
  cout << c1.getSound() << '\n';
  Cat cat1;
  cout << cat1.getSound() << '\n';
  Chicken ch1;
  cout << ch1.getSound() << '\n';
  cout << ch1.getBirthYear() << '\n';
  Cow cow2(static_cast<string>("simbu"), static_cast<string>("book shelf"), static_cast<string>("meow"), 8, 17, 2017);
  cow2.getInformation();
  return 0;
}