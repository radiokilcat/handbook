#include <iostream>
#include <map>
#include <string>
#include <iterator>

#include "book.hpp"


book::book()
{
}
book::~book()
{

}
void book::list_entries()
{
    std::map<std::string, std::string>::iterator it = book_data.begin();
    while(it != book_data.end())
    {
    std::cout<< it->first<<" :: "<<it->second<<std::endl;
    it++;
    }
}
void book::add_entry()
{
    std::cout << "enter the name" << std::endl;
    std::string name;
    std::cin >> name;
    std::cout << "enter the phone" << std::endl;
    std::string phone;
    std::cin >> phone;
    std::cout << "enter the address" << std::endl;
    std::string address;
    std::cin >> address;

    book_data.insert(std::make_pair(name, phone));
    std::map<std::string, std::string>::iterator it = book_data.begin();
    while(it != book_data.end())
    {
    std::cout<< it->first<<" :: "<<it->second<<std::endl;
    it++;
    }
}
void book::delete_entry()
{
    std::cout << "enter the entry name you want to delete: " << std::endl;
    std::string name;
    std::cin >> name;
    std::map<std::string, std::string>::iterator it = book_data.find(name);
    char confirm('n');
    if (book_data.find(name) != book_data.end())
    {
        std::cout << "Are you sure you want to delete this note?" << std::endl;
        std::cout << it->first << " :: " << it->second << std::endl;
        std::cout << "y/n?" << std::endl;
        std::cin >> confirm;
    }
    if (confirm == 'y')
        book_data.erase(it);
}
void book::choose_action(int choice)
{
  switch (choice)
  {
  case 1 :
    book::list_entries();
    break;
  case 2 :
    book::add_entry();
    break;
  case 3 :
    book::delete_entry();
    break;
  }
}
