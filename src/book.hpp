#pragma once

#include <string>
#include <map>

#include <boost/filesystem.hpp>

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

      boost::filesystem::path _data;

        std::string path;
        std::map<std::string, std::string> book_data;
};
