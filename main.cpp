
//Lexus Carton
//CSCI 261 --12/3/2019
//THIS IS A PROGRAM THAT MATCHES USERS WITH A DOG
//IT OPENS A FILE WITH INFORMATION ABOUT THEIR NEW DOG AND A SUPPLY COST
//IT ALSO RANDOMLY GENERATES THE SUPPIIES NEEDED


#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

#include "Animals.h"
#include <cmath>
#include <vector>
#include <fstream>



using namespace std;

int currentBalcance= 0;



int main() {
    srand(time(NULL));


    //random function to determine the price
    const int BASE_CAT_COST = 5;
    const int BASE_DOG_COST = 10;
    Animal W;  //weight
    Animal A;  //age
    Animal F;
    Animal S;
    Animal T;
    Animal E;
    Animal H;


    char User;

    cout << "\" *** .D.O.G...M.A.T.C.H. ***" << endl << endl;
    cout << fixed << setprecision(2);


    cout << "Hello. Welcome to animal match." << endl;
    cout<<"press any button to continue"<<endl;
    cin >> User;

    //NAME OF DOG IS OBTAIN FOR THE FILE
    cout << "What do you want to name your new dog? " << endl;
    string userInputName;
    cin >> userInputName;

    cout << "Are you active or sedentary? (A/S) ";
    cin >> User;


    //INPUT GOES IN TO THE WEIGHT OF DOG AND AGE
    cout << "What kind of dog are you looking for? Here are the price ranges:\n";
    cout << "Option 1: younger \n";
    cout << "Option 2: older\n";
    cin >> User;
    W.setWeight(User);

    A.setAge(User);



    //OPENING THE FILE CALLED RECIPT

    ofstream receiptFile("receipt.txt", ios::app);

//if the file does not open
    if (receiptFile.fail()) {
        cout << "Could not open the file. " << endl;
    }


    //HEADER
    receiptFile << " *** .D.O.G...M.A.T.C.H. ***" << endl;
    receiptFile << fixed << setprecision(2);


    receiptFile << setfill('-') << setw(35);
//title
    receiptFile << "\n" << " * .S.P.E.C.I.F.I.C.A.T.I.O.N.S. *" << endl;
    //line
    receiptFile << "\n" << setfill('-') << setw(35);


    //COMES FROM THE FUNCTION GET SUPPLIES
    //IF GET SUPPLIES PRINTS OUT (5,4,3,2, OR 1) THE RESPONCE IN THE FILE WILL
    //BE INCLUDED
        receiptFile << "\n" << "Supplies needed:" << right ;

    if (S.getSupplies() == 5) {

        receiptFile <<setfill('-') << setw(35)<< "leash, bed, toys";
    } else if (S.getSupplies() == 4) {

        receiptFile << setfill('-') << setw(35)<<"medicine,sweaters,toys";
    } else if (S.getSupplies()== 3) {
        receiptFile << setfill('-') << setw(35)<<"leash, tennis balls";
    } else if (S.getSupplies() == 2) {

        receiptFile<< setfill('-') << setw(35)<<"dog treats, bed, pet bath";
    }else if (S.getSupplies() == 1){

        receiptFile << setfill('-') << setw(35)<<"sweaters, collar, toys";
    }


    //NAME
    receiptFile << "\n" << "Name:" << right << setfill(' ') << setw(25) << userInputName << right << "\n";


    //AGE
    receiptFile << "\n" << "Age: " << right << setfill(' ') << setw(25) << A.getAge() << " years";

    //WEIGHT
    receiptFile << "\n" << "Weight" << setfill(' ') << setw(25) << W.getWeight() << " lbs";

//HAIR LENGTH
    receiptFile << "\n" << "Hair Length" << setfill(' ') << setw(22) << H.getHair() << "cm";

//EYE COLOR
    receiptFile << "\n" << "Eye Color" << setfill(' ') << setw(25);


    //COMES FROM THE FUNCTION GET EYE COLOR
    //IF GET SUPPLIES PRINTS OUT (5,4,3,2, OR 1) THE RESPONCE IN THE FILE WILL
    //BE INCLUDED
    if (E.getEye() == 3) {

        receiptFile << "blue";
    } else if (E.getEye() == 2) {

        receiptFile << "green";
    } else if (E.getEye() == 1) {
        receiptFile << "brown";
    } else {
        receiptFile << "black";
    }

    //Total cost of supplies
    receiptFile << "\n" << "Total Cost" << setfill(' ') << setw(19)<<"$" <<fabs(S.getCost());

//PRINTS OUT PICTURE USING A STRING VECTOR
    receiptFile << "\n" << " **..Y.O.U.R..NEW..P.E.T.***";
    //line
    receiptFile << "\n" << setfill('-') << setw(35);

    receiptFile << "\n" << setfill('*') << setw(35);
//shipping fee

    receiptFile << setfill('-') << setw(35);


    //USES INPUT STRINGED INPUT FROM USER TO SAY "SPECIAL MESAGE FROM PET
    receiptFile << "\n" << "Special message from   " << setfill('-') << setw(5)<< userInputName<< endl;

    vector<string> dogge
            {

                    R"(      ~WoOF WoOf! )",
                    R"(     __ )",
                    R"(   o-''|\_____/ ) )",
                    R"(     \_/|_)     ) )",
                    R"(       \   __  / )",
                    R"(       (_/  (_/   )",


            };

    for (auto s : dogge)
        receiptFile << s << "\n";


    return 0;
}











