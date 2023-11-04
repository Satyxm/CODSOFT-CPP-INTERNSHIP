#include <iostream>
#include <vector>

using namespace std;

struct TodoItem {
  string taskName;
  bool isCompleted;
};

void AddTodoItem(vector<TodoItem>& todoList) {
  TodoItem newItem;
  string taskName;
  cin.ignore(); 
  cout << "Enter the task name (or 'quit' to exit): ";
  while (getline(cin, taskName) && taskName != "quit") {
    if (!taskName.empty()) {
      newItem.taskName = taskName;
      newItem.isCompleted = false;
      todoList.push_back(newItem);
      cout << "Task added successfully!" << endl;
      cout << "Enter the next task name (or 'quit' to exit): ";
    }
  }
}

void ViewTodoList(const vector<TodoItem>& todoList) {
  if (todoList.empty()) {
    cout << "The todo list is empty." << endl;
    return;
  }

  for (size_t i = 0; i < todoList.size(); ++i) {
    cout << "Task " << i + 1 << ": " << todoList[i].taskName << " - Status: "
         << (todoList[i].isCompleted ? "Completed" : "Pending") << endl;
  }
}

void MarkTaskAsCompleted(vector<TodoItem>& todoList) {
  size_t index;
  cout << "Enter the task number to mark as completed: ";
  cin >> index;
  --index;

  if (index < 0 || index >= todoList.size()) {
    cout << "Invalid task number." << endl;
    return;
  }

  todoList[index].isCompleted = true;
  cout << "Task marked as completed!" << endl;
}

void RemoveTodoItem(vector<TodoItem>& todoList) {
  size_t index;
  cout << "Enter the task number to remove: ";
  cin >> index;
  --index;

  if (index < 0 || index >= todoList.size()) {
    cout << "Invalid task number." << endl;
    return;
  }

  todoList.erase(todoList.begin() + index);
  cout << "Task removed successfully!" << endl;
}

int main() {
  vector<TodoItem> todoList;
  int choice;

  do {
    cout << "---------- ToDo List Application ----------" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";

    cin >> choice;

    switch (choice) {
      case 1:
        AddTodoItem(todoList);
        break;
      case 2:
        ViewTodoList(todoList);
        break;
      case 3:
        MarkTaskAsCompleted(todoList);
        break;
      case 4:
        RemoveTodoItem(todoList);
        break;
      case 0:
        cout << "Exiting..." << endl;
        break;
      default:
        cout << "Invalid choice." << endl;
        break;
    }
  } while (choice != 0);

  return 0;
}
