#include <list>

#include "Todo.h"

class TodoList
{
  list<Todo> todos;  
  public:
    void addTodo(string title);
    void listTodos();
    void toggleTodo(int n);
};

void TodoList::addTodo(string title) {
  Todo todo;
  todo.title = title;
  todo.checked = false;
  todos.insert(todos.begin(), todo);
}

void TodoList::listTodos() {
  int i = 0;

  if (todos.empty()) {
    std::cout << "No items found!" << endl;
    return;
  }

  for (
    std::list<Todo>::const_iterator todo = todos.begin();
    todo != todos.end();
    todo++
  ) {
    i++;
    std::cout << i << ") ";
    std::cout << "[" << (todo->checked ? "x" : " ") << "] ";
    std::cout << todo->title << " ";
    std::cout << endl;
  }
}

void TodoList::toggleTodo(int n) {
  std::list<Todo>::iterator todo = todos.begin();
  std::advance(todo, n-1);
  todo->checked = todo->checked ? false : true;
}
