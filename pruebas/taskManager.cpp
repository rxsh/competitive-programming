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
		if(index >= 0 && index < tasks.size()){
			tasks.erase(tasks.begin() + index);
		}
	}

	void markTaskAsDone(int index){
		if(index >= && index < tasks.size()){
			tasks[index].isDone = true;
		}
	}

	void exportTasks(){
		tasks.clear();
		ifstream file(filename);
		if(file.is_open()){
			string line;
			while(getline(file,line)){
				stringstream ss(line);
				string title,description, isDoneStr;
				getline(ss,title,'');
				getline(ss,description,'');
				getline(ss, isDoneStr,'');
				bool isDone = (isDoneStr == "1");
				tasks.emplace_back(title,description);
				tasks.back().isDone = isDone;
			}
			file.close();
			cout << "Task imported successfully.\n";
		} else {
			cerr << "Failed to import tasks.\n";
		}
	}

	void listTask(){
		int index = 0;
		for(const auto& task : tasks){
			cout << index << ".";
			cout << "Title: " << task.title << endl;
			cout << "Description: " << task.description << endl;
			cout << "Status: " << (task.isDone ? "Done" : "Not Done") << endl;
			index++;
		}
	}

};

int main(){



	/*
	1.- Add task
	2.- Delete task
	3.- Mark as Done
	4.- exportTasks
	5.- importTasks
	

	*/

	return 0;
}