#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

void cleanScreen(){
    system("clear");
}

class Task{

public: 

    string nameTask;
    string description;
    bool isDone;
    string timeLimit;


    Task(const string& _nameTask, const string& _description, const string& _timeLimit) : nameTask(_nameTask), description(_description), timeLimit(_timeLimit), isDone(false) {}

};

class TaskManager{

private:

    vector<Task> tasks;
    const string filename="tasks.txt";

    void saveTasksToFile(){
        ofstream file(filename);
        for(const auto& task : tasks){
            file << task.nameTask << "\n" << task.description << "\n" << task.isDone << "\n" << task.timeLimit << "\n";
        }

        file.close();

    }

    void loadTasksFromFile(){
        ifstream file(filename);
        string nameTask, description, timeLimit;
        bool isDone;
        while(getline(file,nameTask)){
            getline(file, description);
            file >> isDone;
            file.ignore();
            getline(file, timeLimit);
            tasks.emplace_back(nameTask, description, timeLimit);
            tasks.back().isDone = isDone;
        }
        file.close();
    }

public: 

    TaskManager(){
        loadTasksFromFile();
    }

    void addTask(const string& nameTask, const string& description, const string& timeLimit){
        tasks.emplace_back(nameTask, description, timeLimit);
        saveTasksToFile();
    }

    void deleteTask(int index){
        if(index >= 0 && index < tasks.size()){
            tasks.erase(tasks.begin() + index);
            saveTasksToFile();
        }
    }

    void markAsDone(int index){
        if(index >= 0 && index < tasks.size()){
            tasks[index].isDone = true;
            saveTasksToFile();
        }
    }

    void showTasks(){

        int i = 0;
        for(const auto& task : tasks){
            cout << "[" << i++ << "]" << endl;
            cout << "Title of task: " << task.nameTask << endl;
            cout << "Description of task: " << task.description << endl;
            cout << "Time limit of task: " << task.timeLimit << endl;
            cout << "Task is Done? -> " << (task.isDone ? "Yes" : "No") << endl;

        }
    }
};

int main(){

    // Add tasks
    // Delete tasks
    // Update tasks
    // Show tasks
    // Mark task as done 
    
    TaskManager taskManager;

    int choice;
    string nameTask, description, timeLimit;

    do{

        cout << "Welcome to Task Management Application \n";
        cout << "1. Add task\n";
        cout << "2. Delete task\n";
        cout << "3. Mark task as Done\n";
        cout << "4. Show Task\n";
        cout << "5. Exit\n";
        cout << "Enter you choice: "; cin >> choice;

        switch(choice){
        
        case 1: 
                cout << "Enter the name task: ";
                cin.ignore();
                getline(cin, nameTask);
                cout << "Enter the description of task: ";
                getline(cin, description);
                cout << "Enter the due date of the task (e.g., YYYY-MM-DD): ";
                getline(cin, timeLimit);
                taskManager.addTask(nameTask,description,timeLimit);
                cin.get();
                cleanScreen();
                break;

        case 2:
                cout << "Enter the task index to delete: ";
                int index; cin >> index;
                taskManager.deleteTask(index);
                cin.ignore();
                cin.get();
                cleanScreen();
                break;
        case 3:
                cout << "Mark Task as done: ";
                int indexDone; cin >> indexDone;
                taskManager.markAsDone(indexDone);
                cin.ignore();
                cin.get();
                cleanScreen();
                break;

        case 4:
                taskManager.showTasks();
                cin.ignore();
                cin.get();
                cleanScreen();
                break;

        case 5:
                cout << "Exit...";
                break;

        default:

                cout << "Invalid choice. Please try again.\n";
                break;
            
        }

    } while(choice != 5);
    
    return 0;
}
