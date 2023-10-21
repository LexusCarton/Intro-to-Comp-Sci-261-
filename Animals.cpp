//
// Created by Lexus on 12/1/2019.
//

#include "Animals.h"


#include <ctime>
#include <cstdlib>
#include <string>





using namespace std;

//CONSTRUCTOR
Animal::Animal()
{
    supplies=0;
    age = 0;
    weight = 0.0;
    hair=0.0;
    cost=0.0;
    eye=0;
    User;
}




//CONSTRUCTOR
Animal::Animal(int Age,int newSupplies,  double newWeight, double newHair, int newEye, double newCost,  char choice)
{
    age = Age;
    supplies=newSupplies;
    weight= newWeight;
    User=choice;
    cost=newCost;
    hair=newHair;
    eye=newEye;

}


//IF USER WANTS A YOUNG DOG THEY PRESS 1, AND FOR OLD THEY PRESS 2
int Animal::getAge()
{
    if(User==1) {
        age = (rand()%(5-1+1)+1);
         //dog years to human
    }
    if(User==2) {
        age= (rand()%(14-6+1)+6);

    }else
      age=rand()%(14-5+1)+5;

    return age;
}

//THE LIST OF SUPPLIES IS RANDOM. A RANDOM NUMBER IS GENERATED AND BASED
//ON THE NUMBER A LIST OF SUPPLIES IS SENT TO THE FILE
int Animal::getSupplies() {

    supplies=rand()%(5-1+1)+1;
    return supplies;
}



//USER IS GIVEN TWO OPTOIONS, YOUNGER OR OLDER, WEIGHT IS BASED
//ON ACTIVITY LEVEL AND AGE OF PET
double Animal::getWeight()
{


    if((User=='A'||User=='a')&&(User==1)) {
        weight = rand()%(49-5+1)+5;
    }
    if((User=='A'||User=='a')&&(User==2)) {
        weight= rand()%(70-50+1)+50;

    }

    if((User=='S'||User=='s')&&(User==1)) {
        weight = rand()%(26-5+1)+5;
    }
    if((User=='S'||User=='s')&&(User==2)) {
        weight = rand()%(30-27+1)+27;

    }else{
        weight=rand()%(50-15+1)+15;
    }

    return weight;
}

//HAIR IS RANDOM TTRIBUTE
double Animal::getHair()
{

        hair = rand()%(50-5+1)+5;

    return hair;
}

//EYE IS RANDOM ATTRIBUTE
int Animal::getEye()
    {


            eye= rand()%(3-1+1)+1;

        return eye;
    }

//BASED ON THE WEIGHT AND AGE OF THE ANIMAL THAT IS RANDOMIZED FROM USER'S INITAL CHOICES
//THEN THE CONSTANT IS APPLIED
double Animal::getCost() {

    if((weight<=26)&&(age<=5)){
        cost=(rand()%(50-25+1)+25)*BASE_TINY;
    }
    if((weight<=26)&&(age>=5)) {
        cost = (rand()%(100-51+1)+51)*BASE_TINY;
    }

    if((weight>=26)&&(age>=5)) {
        cost = (rand()%(100-51+1)+51)*BASE_BIG;
    }
    if((weight>=26)&&(age<=5)) {
        cost = (rand()%(50-25+1)+25)*BASE_BIG;
    }
    return cost;
}


//void funtions
void Animal::setAge(int newAge)
{

    age = newAge;
}

void Animal::setSupplies(int newSupplies) {

    supplies=newSupplies;
}

// setPayoff function implementation
void Animal::setWeight(double newWeight)
{
    weight = newWeight;
}


void Animal::setHair(double newHair)
{
    hair = newHair;
}


void Animal::setEye(int newEye)
{
    eye = newEye;
}

void Animal::setCost(double newCost) {
    cost=newCost;
}