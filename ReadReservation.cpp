//
// Created by 24101 on 2024-09-10.
//

#include "ReadReservation.h"


void readIntoMap1(map<string, string> &map, string &data){
    string key;
    string value;
    int pos = data.find(":");
    if(pos != -1){
        key = data.substr(0, pos);
        value = data.substr(pos+1);
        //value = date.substr(pos+1, date.size()-pos-1);

        map.insert(make_pair(key, value));
    }
}


ReadReservation::ReadReservation() {
    ifstream ifs;

    ifs.open(RESERVATION_FILE, ios::in);

    string date;
    string interval;
    string stuID;
    string stuName;
    string roomID;
    string status;

    this->m_size = 0;

    while(ifs>>date && ifs>>interval && ifs>>stuID && ifs>>stuName && ifs>>roomID && ifs>>status){
        //insert reservation data into small map
        map<string, string> map1;

        readIntoMap1(map1, date);
        readIntoMap1(map1, interval);
        readIntoMap1(map1, stuID);
        readIntoMap1(map1, stuName);
        readIntoMap1(map1, roomID);
        readIntoMap1(map1, status);

        //put small map container into bigger map container
        this->m_R_data.insert(make_pair(this->m_size, map1));
        this->m_size++;

        //clear map1
        map1.clear();
    }

    ifs.close();

    for(map<int, map<string, string>>::iterator it = m_R_data.begin(); it != m_R_data.end(); it++){
        cout<<"Reservation No."<<it->first<<" value = "<<endl;
        for(map<string, string>::iterator it2 = (*it).second.begin(); it2 != (*it).second.end(); it2++){
            cout<<"key: "<<it2->first<<" value: "<<it2->second<<"  ";
        }
        cout<<endl;
    }

}

void ReadReservation::updateR() {

}
