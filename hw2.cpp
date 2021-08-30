////////////////////////  HW2   /////////////////////////
#include <iostream>
#include <cstdint>
#include <cmath>
#include <string>
//////////////////////// part 1 /////////////////////////
class Person {

private : 
  std::string int_name;
  int         int_age;
  char        int_gender;
  int         int_weight;
  
public :
 
  friend class Student;
  
  Person(std::string name = "", int age = 0, char gender = '0', int weight = 0) : int_name(name), int_age(age), int_gender(gender), int_weight(weight) {}  

  void print() const {std::cout << "   Name: " << int_name << "   Age: " << int_age << "   Gender: " << int_gender << "   Weight: " << int_weight;}
  
  void cName    (std::string in_name)  {int_name = in_name;}
  void cAge     (int in_age)           {int_age = in_age;}
  void cWeight  (int in_weight)        {int_weight = in_weight;}
 
  std::string getName () const {return int_name;}
  int          getAge () const {return int_age;}
  char      getGender () const {return int_gender;}
  int       getWeight () const {return int_weight;}
  
  void setName   (std::string name) {int_name = name;}
  void setAge    (int age)          {int_age = age;}  
  void setGender (char gender)      {int_gender = gender;}
  void setWeight (int weight)       {int_weight = weight;}
};

int number = 0;

class Student : public Person {
  public:
    int int_year;
    int int_number;
  
  Student(int year = 0) : int_year(year) {}
  
  void cYear (int in_year) {int_year = in_year;}
  void pYear ()            {int_year++;}
  
  void cStudent(Person in_person, int year) {
    number++;
    int_number = number;
    setName    (in_person.int_name);
    setAge     (in_person.int_age);
    setGender  (in_person.int_gender);
    setWeight  (in_person.int_weight);
  }
  
  void sprint() const {
    std::cout  << int_number;
    print();
    std::cout << "   Year: " << int_year << "\n";
  }
};
//////////////////////// part 2 /////////////////////////
class Fruit {
protected :

  std::string int_name;
  std::string int_color;

public :
  
  Fruit (std::string name = "null", std::string color = "null") : int_name(name), int_color(color){}
  
  std::string   getName () const {return int_name;}
  std::string  getColor () const {return int_color;} 
  
  void  setName  (std::string name) {int_name = name;} 
  void  setColor (std::string color) {int_color = color;}
};

class Banana : public Fruit {
public :
  Banana () : Fruit("banana", "yellow"){}
};

class Apple : public Fruit {
public :
  Apple (std::string color) : Fruit("apple", color){}
};

class GrannySmith : public Apple {
public:
  GrannySmith () : Apple("Granny Smith green"){}
};
//////////////////////// part 3 /////////////////////////
class Game {};

class Players : public Game{};

class Score : public Players{};
class Player : public Players{};
class PC : public Players{};

class Deck : public Game{};
class Cards : public Deck{};
///////////////////////// main //////////////////////////
int main (int argc, const char** argv) {

  std::cout << "\nPart 1\n";

  Person p1("Aa", 18, 'm', 70);
  Person p2("Bb", 19, 'f', 71);
  Person p3("Cc", 20, 'm', 72);
  Person p4("Dd", 21, 'f', 73); 
  Person p5("Ee", 22, 'm', 74);

  std::cout << "Making students from persons..." << "\n";  
  Student s1, s2, s3, s4, s5;
  s1.cStudent(p1, 1);
  s2.cStudent(p2, 2);
  s3.cStudent(p3, 3);
  s4.cStudent(p4, 4);
  s5.cStudent(p5, 5);
  
  s1.pYear();
  s1.sprint();
  s2.sprint();
  s3.sprint();
  s4.sprint();
  s5.sprint();
  
  std::cout << "adding year to student 1" << "\n";
  s1.sprint();
  
  std::cout << "\nPart 2\n";
  
  Apple a("red");
  Banana b;
  GrannySmith c;
  
  std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";  
  std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
  std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
  
return 0;
}
