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
    cout<<"\t\t       0. logout                |\n";
    cout<<"\t\t|                              |\n";
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


    cout<<"Please enter the student username: ";
    cin>>username;

    cout<<"Please enter the password: ";
    cin>>pwd;

    //add data to the file
    ofs<<id<<" "<<username<<" "<<pwd;
    ofs<<endl;
    cout<<"Add successfully!"<<endl;
}

//view accounts
void Admin::view_acc(){

}

//view computer room info
void Admin::view_CR_info(){

}

//clear reservation records
void Admin::clear_file(){

}

void Admin::initVector(){
    //ensure the vector is empty
    vStu.clear();
    vTea.clear();

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
