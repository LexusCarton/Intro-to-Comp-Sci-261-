//
// Created by Lexus on 12/1/2019.
//

#ifndef UNTITLED21_ANIMALS_H
#define UNTITLED21_ANIMALS_H



#include <ctime>
#include <cstdlib>
#include <string>


using namespace std;


class Animal
{
public:

    const int BASE_TINY=2;
    const int BASE_BIG= 3;

    Animal();
    Animal(int Age, int supplies, double newWeight,  double newHair, int newEye, double newCost,  char User); //double weight

    // getter functions
    int getAge();
    int getSupplies();
    double getWeight();
    double getCost();
    double getHair();
    int getEye();
    char User;



    // setter functions
    void setAge(int Age);
    void setSupplies(int newSupplies);
    void setWeight(double newWeight);
    void setCost(double newCost);
    void setHair(double newHair);
    void setEye(int newEye);

private:
    // member variables
    int age;
    int supplies;
    double weight;
    double hair;
    double cost;
    int eye;


};



#endif //UNTITLED21_ANIMALS_H
