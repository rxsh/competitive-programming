#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Task{

public:
	string title;
	string description;
	bool isDone;

	Task(const string& _title, const string& _description) : title(_title), description(_description), isDone(false) {}

};

class TaskManager{

private:
	vector<Task> tasks;
	const string filename = "tasks.txt";

public:

	void addTask(const string& title, const string& description){
		tasks.emplace_back(title, description);
	}

	void deleteTask(int index){
		if (index >= 0 && index < tasks.size()){
			tasks.erase(tasks.begin() + index);
		}
	}

	void markTaskAsDone(int index){
		if(index >= 0 && index < tasks.size()){
			tasks[index].isDone	= true;
		}
	}

	void exportTasks(){
		ofstream file(filename);
		if(file.is_open()){
			for(const auto& task : tasks){
				file << task.title << "," << task.description << "," << task.isDone	<< "\n";
			}
			file.close();
			cout << "Task exported successfully.\n";
		}
		else {
			cerr << "Failed to export tasks.\n";
		}
	}

	void importTasks(){
		tasks.clear();
		ifstream file(filename);
		if(file.is_open()){
			string line;
			while(getline(file, line)){
				stringstream ss(line);
				string title,description, isDoneStr;
				getline(ss,title,',');
				getline(ss,description,',');
				getline(ss, isDoneStr, ',');
				bool isDone = (isDoneStr == "1");
				tasks.emplace_back(title, description);
				tasks.back().isDone = isDone;
			}
			file.close();
			cout << "Tasks imported successfully.\n";
		}
		else {
			cerr << "Failed to import tasks.\n";
		}
	}

	void listTask(){
		int index = 0;
		for(const auto& task : tasks){
			cout << index << ".";
			cout << "Title: " << task.title << endl;
			cout << "Description: " << task.description << endl;
			cout << "Status: " << (task.isDone ? "Done" : "Not Done") << "\n";
			index++;
		}
	}
};


int main(){

	TaskManager taskManager;

	taskManager.importTasks();

	int choice;
	string title, description;
	do{

		cout << "Task Management Application \n";
		cout << "1.- Add task\n";
		cout << "2.- Delete task\n";
		cout << "3.- Mark task as done\n";
		cout << "4.- List tasks\n";
		cout << "5.- Export tasks\n";
		cout << "6.- Exit\n";
		cout << "Enter your choice: "; cin >> choice;

		switch(choice) {
		case 1:
			cout << "Enter the task title: ";
			cin.ignore();
			getline(cin,title);
			cout << "Enter task description: ";
			getline(cin,description);
			taskManager.addTask(title, description);
			break;

		case 2:
			cout << "Enter the task index to delete: ";
			int deleteIndex;
			cin >> deleteIndex;
			taskManager.deleteTask(deleteIndex);
			break;

		case 3:
			cout << "Enter the task index to mark as done: ";
			int doneIndex;
			cin >> doneIndex;
			taskManager.markTaskAsDone(doneIndex);
			break;

		case 4:
			taskManager.listTask();
			break;

		case 5:
			taskManager.exportTasks();
			break;

		case 6:

			taskManager.exportTasks();
			cout << "Exiting this Application.\n";
			break;

		default:
			cout << "Invalid choice. Please try again.\n";
			break;
		}

	} while (choice != 6);

	return 0;

}