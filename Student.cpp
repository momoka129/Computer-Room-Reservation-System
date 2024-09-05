//
// Created by 24101 on 2024/8/26.
//

#include "Student.h"

Student::Student(){

}

//constructor with parameters
Student::Student(int id, string name, string pwd)
{
    this->ID = id;
    this->username = name;
    this->pwd = pwd;
}

//virtual

//student menu
void Student::each_Menu(){
    cout<<"Welcome student representative: "<<this->username<<" login!"<<endl;
    cout<<"\t\t-------------------------------------\n";
    cout<<"\t\t|                                    |\n";
    cout<<"\t\t|      1. apply for reservation      |\n";
    cout<<"\t\t|                                    |\n";
    cout<<"\t\t|      2. check my reservation       |\n";
    cout<<"\t\t|                                    |\n";
    cout<<"\t\t|      3. check all reservation      |\n";
    cout<<"\t\t|                                    |\n";
    cout<<"\t\t|      4. cancel my reservation      |\n";
    cout<<"\t\t|                                    |\n";
    cout<<"\t\t       0. logout                     |\n";
    cout<<"\t\t|                                    |\n";
    cout<<"\t\t-------------------------------------\n";
    cout<<"Please enter your choice: ";
}

//apply for a reservation
void Student::apply_R(){

}

//check own reservations
void Student::view_my_R(){

}

//check all reservation
void Student::view_all_R(){

}

//cancel reservation
void Student::cancel_R(){

}