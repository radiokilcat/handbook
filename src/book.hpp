#pragma once

#include <string>
#include <map>

#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

class book
{
public:
      book();
      ~book();

      struct person  {
          std::string phone;
          std::string adress;
      };

      void list_entries();
      void add_entry();
      int write_to_file(fs::path, std::map<std::string, person>);
      int read_from_file(fs::path);
//      void delete_entry();

private:


      person info;
      boost::filesystem::path path_;
      std::map<std::string, person> book_data_;
};
