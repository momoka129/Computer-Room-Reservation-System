//
// Created by 24101 on 2024/8/26.
//

#include "Teacher.h"

Teacher::Teacher(){

}

Teacher::Teacher(int id, string name, string pwd){
    this->ID = id;
    this->username = name;
    this->pwd = pwd;
}

//teacher menu
void Teacher::each_Menu(){
    cout<<"Welcome teacher: "<<this->username<<" login!"<<endl;
    cout<<"\t\t-------------------------------------\n";
    cout<<"\t\t|                                    |\n";
    cout<<"\t\t|      1. check all reservations     |\n";
    cout<<"\t\t|                                    |\n";
    cout<<"\t\t|      2. review reservation         |\n";
    cout<<"\t\t|                                    |\n";
    cout<<"\t\t|      0. logout                     |\n";
    cout<<"\t\t|                                    |\n";
    cout<<"\t\t-------------------------------------\n";
    cout<<"Please enter your choice: ";
}

//view all reservation
void Teacher::view_all_R(){
    ReadReservation rr;

    if(rr.m_size == 0){
        cout<<"No records!"<<endl;
        return;
    }

    for(int i = 0; i < rr.m_size; i++){
        cout<<i+1<<". ";

        string day;
        if(rr.m_R_data[i]["date"] ==  "1"){
            day = "Monday";
        }
        else if(rr.m_R_data[i]["date"] ==  "2"){
            day = "Tuesday";
        }
        else if(rr.m_R_data[i]["date"] ==  "3"){
            day = "Wednesday";
        }
        else if(rr.m_R_data[i]["date"] ==  "4"){
            day = "Thursday";
        }
        else{
            day = "Friday";
        }
        cout<<"Date: "<<day;
        cout<<"   Interval: "<<(rr.m_R_data[i]["interval"] == "1" ? "Morning" : "Afternoon");
        cout<<"   Student ID: "<<rr.m_R_data[i]["reservationStudentId"];
        cout<<"   Name: "<<rr.m_R_data[i]["name"];
        cout<<"   Computer room ID: "<<rr.m_R_data[i]["computerRoomId"];

        string status = "   Status: ";
        if(rr.m_R_data[i]["status"] == "1"){
            status += "under review";
        }
        else if(rr.m_R_data[i]["status"] == "2"){
            status += "Reservation successful";
        }
        else if(rr.m_R_data[i]["status"] == "-1"){
            status += "Reservation failed";
        }
        else if(rr.m_R_data[i]["status"] == "0"){
            status += "Reservation canceled";
        }
        else{
            cout<<"\nUnable to identify the reservation status, try it later."<<endl;
        }
        cout<<status;
        cout<<endl;
    }
}

//review reservation
void Teacher::valid_R(){
    ReadReservation rr;

    if(rr.m_size == 0){
        cout<<"No records."<<endl;
        return;
    }

    cout<<"The reservation records to be reviewed are as follows:"<<endl;

    vector<int> v;
    int index = 1;

    for(int i = 0; i < rr.m_size; i++){
        if(rr.m_R_data[i]["status"] == "1"){

            v.push_back(i);

            cout<<index++<<". ";
            string day;
            if(rr.m_R_data[i]["date"] ==  "1"){
                day = "Monday";
            }
            else if(rr.m_R_data[i]["date"] ==  "2"){
                day = "Tuesday";
            }
            else if(rr.m_R_data[i]["date"] ==  "3"){
                day = "Wednesday";
            }
            else if(rr.m_R_data[i]["date"] ==  "4"){
                day = "Thursday";
            }
            else{
                day = "Friday";
            }
            cout<<"Date: "<<day;
            cout<<"   Interval: "<<(rr.m_R_data[i]["interval"] == "1" ? "Morning" : "Afternoon");
            cout<<"   Student ID: "<<rr.m_R_data[i]["reservationStudentId"];
            cout<<"   Name: "<<rr.m_R_data[i]["name"];
            cout<<"   Computer room ID: "<<rr.m_R_data[i]["computerRoomId"];
            cout<<endl;
        }
    }

    int select = 0;
    int decide = 0;

    while(true){
        cout<<"Please enter the number of the reservation record to be reviewed: (1 record once; Press 0 to return)";
        cin>>select;

        if(select > 0 && select <= v.size()){
            cout<<"1. Approve"<<endl;
            cout<<"2. Reject"<<endl;
            cin>>decide;

            if(decide == 1){
                rr.m_R_data[v[select-1]]["status"] = "2";
                rr.updateR();
                cout<<"This reservation has been approved."<<endl;
            }
            else if(decide == 2){
                rr.m_R_data[v[select-1]]["status"] = "-1";
                //actually writing to the file
                rr.updateR();
                cout<<"This reservation has been rejected."<<endl;
            }
            else{
                cout<<"...\nenter 1 or  2 \tunderstand?"<<endl;
            }
        }
        else if(select == 0){
            return;
        }
        else{
            cout<<"Invalid input! try again."<<endl;
        }
    }

}
