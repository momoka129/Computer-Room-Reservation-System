#include <iostream>
using namespace std;
#include <limits>
#include "Identity.h"
#include <fstream>
#include "globalFile.h"
#include "Student.h"
#include "Teacher.h"
#include "Admin.h"

//the admin submenu
void adminMenu(Identity * &admin) {
    while (true) {
        //call admin submenu
        admin->each_Menu();

        //Convert the parent class pointer to a subclass pointer and call other interfaces in the subclass
        Admin *ad = (Admin *) admin;

        int select = 0;
        cin >> select;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;

        }

        if (select == 1) {    //add account
            //cout << "Add account" << endl;
            ad->add_Acc();
        } else if (select == 2) {   //check accounts
            //cout << "View accounts" << endl;
            ad->view_acc();
        } else if (select == 3) {   //check computer room
            //cout << "Check computer room" << endl;
            ad->view_CR_info();
        } else if (select == 4) {   //clear reservation
            //cout << "Clear reservation" << endl;
            ad->clear_file();
        } else if (select == 0) {   //logout
            delete admin;       //destroy heap objects
            cout << "Logout successful" << endl;
            return;
        } else {
            cout << "Wrong enter..." << endl;
        }

    }
}


//log in function: operator file, operator identity
void logIn(string fileName, int type){
    //Parent class pointer, used to point to the child class object
    Identity * person = NULL;

    //read file
    ifstream ifs;
    ifs.open(fileName, ios::in);

    //determine whether the file exists
    if(!ifs.is_open()){
        string p;
        if(type == 1){
            p = "STUDENT";
        } else if(type == 2){
            p = "TEACHER";
        } else{
            p = "ADMIN";
        }
        cout<<"The "<<p<<" file is missing. Login failed."<<endl;
        ifs.close();
        return;
    }

    //prepare account info
    int id = 0;
    string userName;
    string pwd;

    //determine identity type
    if(type == 1){
        cout<<"Please enter your student id: "<<endl;
        cin>>id;
    }
    else if(type == 2){
        cout<<"Please enter your teacher id: "<<endl;
        cin>>id;
    }

    cout<<"Please enter your username: "<<endl;
    cin >> userName;

    cout<<"Please enter your password: "<<endl;
    cin>>pwd;

    if(type == 1){
        //student identity check
        int fId;    //The id number obtained from the file
        string fUsername;
        string fPwd;
        while(ifs>>fId && ifs>>fUsername && ifs>>fPwd){
            if(fId == id && fUsername == userName && fPwd == pwd){
                cout<<"Student login verification successful!"<<endl;

                person = new Student(id, userName, pwd);

                //go to the student submenu
                return;
            }
        }
    }
    else if(type == 2){
        //teacher identity verification
        int fId;    //The id number obtained from the file
        string fUsername;
        string fPwd;
        while(ifs>>fId && ifs>>fUsername && ifs>>fPwd){
            if(fId == id && fUsername == userName && fPwd == pwd){
                cout<<"Teacher login verification successful!"<<endl;

                person = new Teacher(id, userName, pwd);

                //go to the teacher submenu
                return;
            }
        }
    }
    else if(type == 3){
        //admin identity verification
        string fUsername;   //The id username obtained from the file
        string fPwd;
        while(ifs>>fUsername && ifs>>fPwd){
            if(fUsername == userName && fPwd == pwd){
                cout<<"Admin login verification successful!"<<endl;

                person = new Admin(userName, pwd);

                //go to the admin submenu
                adminMenu(person);

                return;
            }
        }
    }

    cout<<"Verification login failed."<<endl;

}

int main() {

    int select = 0;

    while(1){
        cout<<"Welcome to the computer room reservation system"<<endl;
        cout<<endl<<"\t\tChoose your identity: "<<endl;
        cout<<"\t\t--------------------------------\n";
        cout<<"\t\t|                               |\n";
        cout<<"\t\t|   1. Student Representative   |\n";
        cout<<"\t\t|                               |\n";
        cout<<"\t\t|   2. Teacher                  |\n";
        cout<<"\t\t|                               |\n";
        cout<<"\t\t|   3. Administrator            |\n";
        cout<<"\t\t|                               |\n";
        cout<<"\t\t|   0. Exit                     |\n";
        cout<<"\t\t|                               |\n";
        cout<<"\t\t--------------------------------\n";
        cout<<"Please enter your choice: ";

        cin>>select;

        // check if the input is valid
        if (cin.fail()) {
            // 清除错误状态
            cin.clear();
            // 丢弃缓冲区中的错误输入
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;   // 在循环中跳过当前迭代中剩余的代码，并立即开始下一次迭代。
        }

        switch (select) {
            //student
            case 1:
                logIn(STUDENT_FILE, select);
                break;

            //teacher
            case 2:
                logIn(TEACHER_FILE, select);
                break;

            //administrator
            case 3:
                logIn(ADMIN_FILE, select);
                break;

            //exit
            case 0:
                cout<<"Welcome next use."<<endl;
                return 0;
                //break;

            default:
                cout<<"Invalid input!\tENTER A VALID INPUT!"<<endl;
                break;

        }
    }






    return 0;
}
