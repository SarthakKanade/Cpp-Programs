//Simple TaskManager Model

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

// Task structure
struct Task 
{
    int id;
    string title;
    string description;
    string priority; 
    string deadline; 
    string category; 
    bool isCompleted;

    // Display task details
    void display() const 
    {
        cout << "ID: " << id << ", Title: " << title << ", Priority: " << priority
             << ", Deadline: " << deadline << ", Category: " << category
             << ", Status: " << (isCompleted ? "Completed" : "Pending") << endl;
    }
};

// Function prototypes
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void editTask(vector<Task>& tasks);
void deleteTask(vector<Task>& tasks);
void markCompleted(vector<Task>& tasks);
void saveTasks(const vector<Task>& tasks);
void loadTasks(vector<Task>& tasks);
void listByPriority(const vector<Task>& tasks, const string& priority);
void listByCategory(const vector<Task>& tasks, const string& category);

int main() 
{
    vector<Task> tasks; 
    int choice;
    loadTasks(tasks);  
    cout << "=======================\n";
    cout << "Task Management System\n";
    cout << "=======================\n";

    do {
        // Display menu
        cout << "\n1. Add Task\n";
        cout << "2. View All Tasks\n";
        cout << "3. Edit Task\n";
        cout << "4. Delete Task\n";
        cout << "5. Mark Task as Completed\n";
        cout << "6. List Tasks by Priority\n";
        cout << "7. List Tasks by Category\n";
        cout << "8. Save & Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1: addTask(tasks); break;
            case 2: viewTasks(tasks); break;
            case 3: editTask(tasks); break;
            case 4: deleteTask(tasks); break;
            case 5: markCompleted(tasks); break;
            case 6: 
            {
                string priority;
                cout << "Enter priority (high/medium/low): ";
                cin >> priority;
                listByPriority(tasks, priority);
                break;
            }
            case 7: 
            {
                string category;
                cout << "Enter category: ";
                cin >> category;
                listByCategory(tasks, category);
                break;
            }
            case 8: saveTasks(tasks); cout << "Tasks saved. Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n"; break;
        }
    } while (choice != 8);

    return 0;
}

// Add a new task
void addTask(vector<Task>& tasks) 
{
    Task newTask;
    newTask.id = tasks.size() + 1; 
    cin.ignore(); 

    cout << "Enter task title: ";
    getline(cin, newTask.title);
    if (newTask.title.empty()) 
    {
        cout << "Error: Task title cannot be empty!\n";
        return;
    }

    cout << "Enter task description: ";
    getline(cin, newTask.description);

    cout << "Enter task priority (high/medium/low): ";
    getline(cin, newTask.priority);
    if (newTask.priority != "high" && newTask.priority != "medium" && newTask.priority != "low") {
        cout << "Error: Invalid priority! Please choose 'high', 'medium', or 'low'.\n";
        return;
    }

    cout << "Enter task deadline (YYYY-MM-DD HH:MM): ";
    getline(cin, newTask.deadline);
    
    cout << "Enter task category (Work/Personal/Other): ";
    getline(cin, newTask.category);
    
    newTask.isCompleted = false;

    tasks.push_back(newTask);
    cout << "Task added successfully.\n";
}

// View all tasks
void viewTasks(const vector<Task>& tasks) 
{
    if (tasks.empty()) 
    {
        cout << "No tasks available.\n";
    } else 
    {
        for (const auto& task : tasks) 
        {
            task.display();
        }
    }
}

// Edit an existing task
void editTask(vector<Task>& tasks) 
{
    int id;
    cout << "Enter task ID to edit: ";
    cin >> id;

    if (id <= 0 || id > tasks.size()) 
    {
        cout << "Error: Invalid task ID!\n";
        return;
    }

    for (auto& task : tasks) 
    {
        if (task.id == id) 
        {
            cin.ignore();
            cout << "Editing task: " << task.title << endl;
            cout << "Enter new title: ";
            getline(cin, task.title);
            if (task.title.empty()) 
            {
                cout << "Error: Task title cannot be empty!\n";
                return;
            }
            cout << "Enter new description: ";
            getline(cin, task.description);
            cout << "Enter new priority (high/medium/low): ";
            getline(cin, task.priority);
            if (task.priority != "high" && task.priority != "medium" && task.priority != "low") 
            {
                cout << "Error: Invalid priority! Please choose 'high', 'medium', or 'low'.\n";
                return;
            }
            cout << "Enter new deadline (YYYY-MM-DD HH:MM): ";
            getline(cin, task.deadline);
            cout << "Enter new category: ";
            getline(cin, task.category);
            cout << "Task updated.\n";
            return;
        }
    }
    cout << "Task not found.\n";
}

// Delete a task
void deleteTask(vector<Task>& tasks) 
{
    int id;
    cout << "Enter task ID to delete: ";
    cin >> id;

    if (id <= 0 || id > tasks.size()) 
    {
        cout << "Error: Invalid task ID!\n";
        return;
    }

    for (auto it = tasks.begin(); it != tasks.end(); ++it) 
    {
        if (it->id == id) {
            tasks.erase(it);
            cout << "Task deleted.\n";
            return;
        }
    }
    cout << "Task not found.\n";
}

// Mark task as completed
void markCompleted(vector<Task>& tasks) 
{
    int id;
    cout << "Enter task ID to mark as completed: ";
    cin >> id;

    if (id <= 0 || id > tasks.size()) 
    {
        cout << "Error: Invalid task ID!\n";
        return;
    }

    for (auto& task : tasks) 
    {
        if (task.id == id) 
        {
            task.isCompleted = true;
            cout << "Task marked as completed.\n";
            return;
        }
    }
    cout << "Task not found.\n";
}

// List tasks by priority
void listByPriority(const vector<Task>& tasks, const string& priority) 
{
    bool found = false;
    for (const auto& task : tasks) 
    {
        if (task.priority == priority) 
        {
            task.display();
            found = true;
        }
    }
    if (!found) 
    {
        cout << "No tasks found with " << priority << " priority.\n";
    }
}

// List tasks by category
void listByCategory(const vector<Task>& tasks, const string& category) 
{
    bool found = false;
    for (const auto& task : tasks) 
    {
        if (task.category == category) 
        {
            task.display();
            found = true;
        }
    }
    if (!found) 
    {
        cout << "No tasks found under " << category << " category.\n";
    }
}

// Save tasks to a file
void saveTasks(const vector<Task>& tasks) 
{
    ofstream outFile("tasks.txt");

    if (!outFile) 
    {
        cout << "Error: Failed to open file for saving.\n";
        return;
    }

    for (const auto& task : tasks) 
    {
        outFile << task.id << "\n" << task.title << "\n" << task.description << "\n"
                << task.priority << "\n" << task.deadline << "\n" << task.category
                << "\n" << task.isCompleted << "\n";
    }

    outFile.close();
    cout << "Tasks saved to file.\n";
}

// Load tasks from a file
void loadTasks(vector<Task>& tasks) 
{
    ifstream inFile("tasks.txt");

    if (!inFile) 
    {
        cout << "Error: Could not open file for loading tasks.\n";
        return;
    }

    Task task;
    while (inFile >> task.id) 
    {
        inFile.ignore(); 
        getline(inFile, task.title);
        getline(inFile, task.description);
        getline(inFile, task.priority);
        getline(inFile, task.deadline);
        getline(inFile, task.category);
        inFile >> task.isCompleted;
        inFile.ignore(); 
        tasks.push_back(task);
    }

    inFile.close();
}
