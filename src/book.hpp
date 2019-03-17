#ifndef BOOK_H
#define BOOK_H

#endif // BOOK_H
#include <string>
#include <map>

class book
{
public:
      book();
      ~book();
      void choose_action(int choice);
      void list_entries();
      void add_entry();
      void delete_entry();

private:

    std::string path;
    std::map<std::string, std::string> book_data;
};
