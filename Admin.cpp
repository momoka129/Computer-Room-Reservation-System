//
// Created by 24101 on 2024/8/26.0
//

#include "Admin.h"

Admin::Admin(){

}

//init admin info
Admin::Admin(string name, string pwd){
    this->username = name;
    this->pwd = pwd;

    this->initVector();
}

//Admin menu
void Admin::each_Menu(){
    cout<<"Welcome administrator: "<<this->username<<" login!"<<endl;
    cout<<"\t\t--------------------------------\n";
    cout<<"\t\t|                               |\n";
    cout<<"\t\t|      1. add account           |\n";
    cout<<"\t\t|                               |\n";
    cout<<"\t\t|      2. view accounts         |\n";
    cout<<"\t\t|                               |\n";
    cout<<"\t\t|      3. check computer room   |\n";
    cout<<"\t\t|                               |\n";
    cout<<"\t\t|      4. clear reservation     |\n";
    cout<<"\t\t|                               |\n";
    cout<<"\t\t|      0. logout                |\n";
    cout<<"\t\t|                               |\n";
    cout<<"\t\t--------------------------------\n";
    cout<<"Please enter your choice: ";
}

//add account
void Admin::add_Acc(){
    cout<<"Please enter the type of account to add"<<endl;
    cout<<"1. add student account"<<endl;
    cout<<"2. add teacher account"<<endl;

    string fileName;
    string tip;
    string repeatTip;
    ofstream ofs;

    int select = 0;
    cin>>select;

    if(select == 1){
        fileName = STUDENT_FILE;
        tip = "Please enter the student ID: ";
        repeatTip = "The student ID already exists, please select a different one.";
    }
    else if(select == 2){
        fileName = TEACHER_FILE;
        tip = "Please enter the teacher ID: ";
        repeatTip = "The teacher ID already exists, please select a different one.";
    }
    else{
        cout<<"wrong enter. Add account terminate."<<endl;
        return;
    }

    ofs.open(fileName, ios::out | ios::app);

    int id;     //student id or teacher id
    string username;
    string pwd;

    cout<<tip<<endl;
    while(true){
        cin>>id;
        bool res = checkRepeat(id, select);
        if(res){
            cout<<repeatTip<<endl;
        }
        //exit the infinite loop
        else{
            break;
        }
    }


    cout<<"Please enter the username: ";
    cin>>username;

    cout<<"Please enter the password: ";
    cin>>pwd;

    //add data to the file
    ofs<<id<<" "<<username<<" "<<pwd;
    ofs<<endl;
    cout<<"Add successfully!"<<endl;

    ofs.close();

    //update vector to fix the bug which will add people with the same id bcs the vector is not updated
    //this->initVector();

    //or no need to init vector, that will cost a lot and not efficient
    //manually add the one new user is more efficient
    if(select == 1){
        Student newStudent;
        newStudent.ID = id;
        newStudent.username = username;
        newStudent.pwd = pwd;
        vStu.push_back(newStudent);
    }
    else if(select == 2){
        Teacher newTeacher;
        newTeacher.ID = id;
        newTeacher.username = username;
        newTeacher.pwd = pwd;
        vTea.push_back(newTeacher);
    }

}

void printStudent(Student &s){
    cout<<"Student ID: "<<setw(2)<<s.ID<<"\t\tUsername: "<<setw(8)<<s.username<<"\t\tPassword: "<<setw(8)<<s.pwd<<endl;
}

//view accounts
void Admin::view_acc(){
    cout<<"Please select the content to view: "<<endl;
    cout<<"1. view all student"<<endl;
    cout<<"2. view all teacher"<<endl;

    int select = 0;
    cin>>select;

    if(select == 1){
        //student
        cout<<"All student info is as follows: "<<endl;
        for_each(vStu.begin(), vStu.end(), printStudent);
    }
    else if(select == 2){
        cout<<"All teacher info is as follows: "<<endl;
        for(vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++){
            cout<<"Teacher ID: "<<setw(2)<<it->ID<<"\t\tUsername: "<<setw(8)<<it->username<<"\t\tPassword: "<<setw(8)<<it->pwd<<endl;
        }
    }
    else{
        cout<<"Wrong enter......"<<endl;
        return;
    }
}

//view computer room info
void Admin::view_CR_info(){
    cout<<"The computer room info is as follows: "<<endl;

    for(vector<ComputerRoom>::iterator it = vCom_room.begin(); it != vCom_room.end(); it++){
        cout<<"Computer room ID: "<<setw(2)<<it->id<<"\t\tIts capacity: "<<setw(3)<<it->max_num<<endl;
    }
}

//clear reservation records
void Admin::clear_file(){
    cout<<"Are you sure you want to clear the reservation record?"<<endl;
    cout<<"1. YES"<<endl;
    cout<<"2. NO"<<endl;

    int select;
    cin>>select;

    if(select == 1){
        ofstream ofs;
        ofs.open(RESERVATION_FILE, ios::trunc);
        ofs.close();

        cout<<"Clear successfully!"<<endl;
    }
    else if(select == 2){
        cout<<"Clear reservation record to terminate."<<endl;
    }
    else{
        cout<<"Wrong enter. exit..."<<endl;
    }
}

void Admin::initVector(){
    //ensure the vector is empty
    vStu.clear();
    vTea.clear();
    vCom_room.clear();

    //read info: student
    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);
    if(!ifs.is_open()){
        cout<<"File read failed."<<endl;
        return;
    }

    Student s;
    while(ifs>>s.ID && ifs>>s.username && ifs>>s.pwd){
        vStu.push_back(s);
    }
    cout<<"Current student number: "<<vStu.size()<<endl;

    ifs.close();

    //read info: teacher
    ifs.open(TEACHER_FILE, ios::in);
    if(!ifs.is_open()){
        cout<<"File read failed."<<endl;
        return;
    }

    Teacher t;
    while(ifs>>t.ID && ifs>>t.username && ifs>>t.pwd){
        vTea.push_back(t);
    }
    cout<<"Current teacher number: "<<vTea.size()<<endl;

    ifs.close();

    //read info: computer room
    ifs.open(COMPUTER_FILE, ios::in);
    if(!ifs.is_open()){
        cout<<"File read failed."<<endl;
        return;
    }

    ComputerRoom cr;
    while(ifs>>cr.id && ifs>>cr.max_num){
        vCom_room.push_back(cr);
    }
    cout<<"Total computer room number: "<<vCom_room.size()<<endl;

    ifs.close();
}

bool Admin::checkRepeat(int id, int type) {
    if(type == 1){
        //detect student id
        for(vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++){
            if(id == it->ID){
                return true;
            }
        }
    }
    else if(type == 2){
        //detect teacher id
        for(vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++){
            if(id == it->ID){
                return true;
            }
        }
    }
    return false;

}
