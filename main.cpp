#include <iostream>
#include <sstream>
#include "TodoList.h"

using namespace std;

string usageString ()
{
  return "This is a simple console TODO-List. Add one of the letters below \n"
  "and press enter:\n"
    "(1) Add Todo\n"
    "(2) List Todos\n"
    "(3) Toggle Todo as done\n"
    "(4) Help \n"
    "(5) Quit program\n";
}

void usage() {
  cout << usageString() << endl;
}

void addTodo(TodoList &tl) {
  string title;
  Todo todo;

  cout << "EnterTitle: ";
  getline(cin, title);
  tl.addTodo(title);
  cout << endl << "Todo added" << endl;
}

int main()
{
  TodoList todoList;
  usage();
  string inputOption, inputToggle;
  int option, toggle;

  while (1) {
    getline(cin, inputOption);
    stringstream(inputOption) >> option;

    switch (option) {
      case 1:
        addTodo(todoList);
        break;
      case 2:
        todoList.listTodos();
        break;
      case 3:
        cout << "Enter which todo you want to toggle: ";
        getline(cin, inputToggle);
        stringstream(inputToggle) >> toggle;
        todoList.toggleTodo(toggle);
        cout << endl;
        break;
      case 0:
        cout << "no 0 and no letters" << endl;
        return 1;
      case 5:
        cout << "bye" << endl;
        return 0;
      default:
        usage();
        break;
    }
  }
}
