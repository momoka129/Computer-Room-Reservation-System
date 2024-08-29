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