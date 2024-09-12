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

    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);

    ComputerRoom cr;
    while(ifs>>cr.id && ifs>>cr.max_num){
        vCR.push_back(cr);
    }

    ifs.close();
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
    int date = 0;
    int interval = 0;
    int roomID = 0;

    cout<<"The computer room is open from Monday to Friday."<<endl;
    cout<<"Please enter your desired time:"<<endl;
    cout<<"1. Monday"<<endl;
    cout<<"2. Tuesday"<<endl;
    cout<<"3. Wednesday"<<endl;
    cout<<"4. Thursday"<<endl;
    cout<<"5. Friday"<<endl;
    cin>>date;

    cout<<"Please enter your preferred time interval: "<<endl;
    cout<<"1. Morning"<<endl;
    cout<<"2. Afternoon"<<endl;
    while(1){
        cin>>interval;
        if(interval == 1 || interval == 2){
            break;
        }
    }

    cout<<"Please choose the computer room: "<<endl;
    for(int i = 0; i < vCR.size(); i++){
        cout<<"No."<<vCR[i].id<<" computer room capacity: "<<vCR[i].max_num<<endl;
    }
    cin>>roomID;

    ofstream ofs;
    ofs.open(RESERVATION_FILE, ios::app);

    ofs<<"date:"<<date<<"   ";
    ofs<<"interval:"<<interval<<"   ";
    ofs<<"reservationStudentId:"<<this->ID<<"   ";
    ofs<<"name:"<<this->username<<"   ";
    ofs<<"computerRoomId:"<<roomID<<"   ";
    ofs<<"status:"<<1;
    ofs<<endl;

    ofs.close();

    cout<<"Your reservation request has been successfully submitted and is under review. Please wait patiently."<<endl;

}

//check own reservations
void Student::view_my_R(){
    ReadReservation rr;

    if(rr.m_size == 0){
        cout<<"No reservation records!"<<endl;
        return;
    }

    //convert string to int
    //first convert cpp type string to c type string, then into int
    for(int i = 0; i < rr.m_size; i++){
        if(this->ID == atoi(rr.m_R_data[i]["reservationStudentId"].c_str())){
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
            cout<<"   Computer room ID: "<<rr.m_R_data[i]["computerRoomId"];

            string status = "   Reservation status: ";
            if(rr.m_R_data[i]["status"] == "1"){
                status += "Under review";
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
}

//check all reservation
void Student::view_all_R(){
    ReadReservation rr;

    if(rr.m_size == 0){
        cout<<"No reservation records."<<endl;
        return;
    }

    for(int i = 0; i < rr.m_size; i++){
        cout<<"No. "<<i + 1<<". ";
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

//cancel reservation
void Student::cancel_R(){
    ReadReservation rr;

    if(rr.m_size == 0){
        cout<<"No reservation records."<<endl;
        return;
    }

    cout<<"Records that are under review or have been successfully scheduled can be canceled."<<endl;

    vector<int> v;      //the index of the largest container where the data is stored
    int index = 1;
    for(int i = 0; i < rr.m_size; i++){
        //First determine whether it is your own student number
        if(this->ID == atoi(rr.m_R_data[i]["reservationStudentId"].c_str())){
            // Second screen the status
            if(rr.m_R_data[i]["status"] == "1" || rr.m_R_data[i]["status"] == "2"){
                //
                v.push_back(i);         //储存底层全局容器的符合条件的记录对应编号
                //
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
                cout<<"   Computer room ID: "<<rr.m_R_data[i]["computerRoomId"];

                string status = "   Reservation status: ";
                if(rr.m_R_data[i]["status"] == "1"){
                    status += "Under review";
                }
                else if(rr.m_R_data[i]["status"] == "2"){
                    status += "Reservation successful";
                }
                else{
                    cout<<"\nUnable to identify the reservation status, try it later."<<endl;
                }
                cout<<status;
                cout<<endl;
            }
        }
    }

    cout<<"Please select the record you want to cancel. Press 0 to return."<<endl;
    int select = 0;

    while(true){
        cin>>select;
        if(select == 0){
            break;
        }
        else if(select > 0 && select <= v.size()){
            rr.m_R_data[v[select-1]]["status"] = "0";
            rr.updateR();
            cout<<"Reservation have been canceled."<<endl;
            break;
        }
        else{
            cout<<"Wrong enter."<<endl;
            cout<<"Enter again."<<endl;
        }
    }

}