#include <iostream>
#include "book.hpp"

int main() {
  std::cout << "Welcome to the phone book" << std::endl;
  book tel_book;
  bool exit = false;
  while(true)
  {
  std::cout << "Choose your action: "
               "\n 1 - list all entries; "
               "2 - add new entry; "
               "3 - delete entry; "
               "4 - quit;" << std::endl;
  int action;
  std::cin >> action;
  switch (action)
  {
  case 1 :
    tel_book.list_entries();
    break;
  case 2 :
    tel_book.add_entry();
    break;
  case 3 :
    tel_book.delete_entry();
    break;
  case 4 :
      exit = true;
      break;
  }
  if (exit) break;
  }
}
