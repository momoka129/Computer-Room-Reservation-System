//
// Created by 24101 on 2024-09-10.
//

#ifndef COMPUTER_ROOM_RESERVATION_SYSTEM_READRESERVATION_H
#define COMPUTER_ROOM_RESERVATION_SYSTEM_READRESERVATION_H

#pragma once
#include <iostream>
using namespace std;
#include "globalFile.h"
#include <fstream>
#include <map>


class ReadReservation {
public:
    ReadReservation();

    //update reservation records   mainly for status
    void updateR();


    //number of reservation
    int m_size = 0;

    //key: the number of reservation    value: store the reservation data
    map<int, map<string, string>> m_R_data;
};


#endif //COMPUTER_ROOM_RESERVATION_SYSTEM_READRESERVATION_H
