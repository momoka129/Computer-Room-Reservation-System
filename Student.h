//
// Created by 24101 on 2024/8/26.
//

#ifndef COMPUTER_ROOM_RESERVATION_SYSTEM_STUDENT_H
#define COMPUTER_ROOM_RESERVATION_SYSTEM_STUDENT_H

#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"

class Student : public Identity{
public:
    Student();

    //constructor with parameters
    Student(int id, string name, string pwd);

    //implement parent pure virtual destructor
    //~Student();

    //student menu
    virtual void each_Menu();

    //apply for a reservation
    void apply_R();

    //check own reservations
    void view_my_R();

    //check all reservation
    void view_all_R();

    //cancel reservation
    void cancel_R();


    int ID;     //student id

};


#endif //COMPUTER_ROOM_RESERVATION_SYSTEM_STUDENT_H
