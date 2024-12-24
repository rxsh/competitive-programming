#include<iostream>
#include<string>
#include<stack>


using namespace std;

int main(){

    int N;
    cin >> N; 
    stack<string> dreamStack;
    string name, command;

    for(int i=0; i<N;i++){
        cin >> command;
        if(command == "Sleep"){
            cin >> name;
            dreamStack.push(name);

        }
        else if(command == "Kick"){
            if(!dreamStack.empty()){
                dreamStack.pop();
            }

        }
        else if(command == "Test"){
            if(dreamStack.empty()){
                cout << "Not in a dream" << endl;
            }
            else {
                cout << dreamStack.top() << endl;
            }
        }
    }

    return 0;
}

