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
    ofstream ofs;

    int select = 0;
    cin>>select;

    if(select == 1){
        fileName = STUDENT_FILE;
        tip = "Please enter the student id: ";
    }
    else if(select == 2){
        fileName = TEACHER_FILE;
        tip = "Please enter the teacher id: ";
    }

    ofs.open(fileName, ios::out | ios::app);

    int id;     //student id or teacher id
    string username;
    string pwd;

    cout<<tip;
    cin>>id;

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