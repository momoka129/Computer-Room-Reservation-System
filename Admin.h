//
// Created by 24101 on 2024/8/26.
//

#ifndef COMPUTER_ROOM_RESERVATION_SYSTEM_ADMIN_H
#define COMPUTER_ROOM_RESERVATION_SYSTEM_ADMIN_H

#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
#include <fstream>
#include "globalFile.h"
#include <vector>
#include "Student.h"
#include "Teacher.h"
#include <algorithm>
#include <iomanip>
#include "computerRoom.h"


class Admin : public Identity{
public:
    Admin();

    Admin(string name, string pwd);

    //Admin menu
    virtual void each_Menu();

    //add account
    void add_Acc();

    //view accounts
    void view_acc();

    //view computer room info
    void view_CR_info();

    //clear reservation records
    void clear_file();

    void initVector();

    //detecting duplicates
    bool checkRepeat(int id, int type);

    vector<Student> vStu;

    vector<Teacher> vTea;

    //store computer room info
    vector<ComputerRoom> vCom_room;

};


#endif //COMPUTER_ROOM_RESERVATION_SYSTEM_ADMIN_H
