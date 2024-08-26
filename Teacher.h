//
// Created by 24101 on 2024/8/26.
//

#ifndef COMPUTER_ROOM_RESERVATION_SYSTEM_TEACHER_H
#define COMPUTER_ROOM_RESERVATION_SYSTEM_TEACHER_H
#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"

class Teacher : public Identity{
public:
    Teacher();

    Teacher(int id, string name, string pwd);

    //teacher menu
    virtual void each_Menu();

    //view all reservation
    void view_all_R();

    //review reservation
    void valid_R();

    int ID;     //Employee No.
};


#endif //COMPUTER_ROOM_RESERVATION_SYSTEM_TEACHER_H
