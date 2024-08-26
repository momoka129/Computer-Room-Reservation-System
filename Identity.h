//
// Created by 24101 on 2024/8/26.
//

#ifndef COMPUTER_ROOM_RESERVATION_SYSTEM_IDENTITY_H
#define COMPUTER_ROOM_RESERVATION_SYSTEM_IDENTITY_H

#pragma once
#include <iostream>
using namespace std;

class Identity{
public:

    //each identity's different menu   using pure virtual function to implement
    virtual void each_Menu() = 0;

    string username;    //username

    string pwd;     //password
};

#endif //COMPUTER_ROOM_RESERVATION_SYSTEM_IDENTITY_H
