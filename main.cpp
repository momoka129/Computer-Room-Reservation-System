#include <iostream>
using namespace std;
#include <limits>

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
                cout<<"1";
                break;

            //teacher
            case 2:
                break;

            //administrator
            case 3:
                break;

            //exit
            case 0:
                break;

            default:
                cout<<"Invalid input!\tENTER A VALID INPUT!"<<endl;
                break;

        }
    }






    return 0;
}
