#include <iostream>
using namespace std;
#include <limits>
#include "Identity.h"
#include <fstream>
#include "globalFile.h"
#include "Student.h"
#include "Teacher.h"
#include "Admin.h"

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
                logIn(STUDENT_FILE, 1);
                break;

            //teacher
            case 2:
                logIn(TEACHER_FILE, 2);
                break;

            //administrator
            case 3:
                logIn(ADMIN_FILE, 3);
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
