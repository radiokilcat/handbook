#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

#include "book.hpp"

namespace fs = boost::filesystem;


int book::write_to_file(fs::path file, std::map<std::string, person> m)
{
//    TODO: re-write to fstream
        int count = 0;
        if (m.empty())
                return 0;

        FILE *fp = fopen(file.c_str(), "w");
        if (fp == nullptr)
        {
            std::fprintf(stderr, "file opening error %d, %s\n", errno, strerror(errno));
            std::abort();
        }

        for(auto it = m.begin(); it != m.end(); it++) {
                fprintf(fp, "%s %s %s\n", it->first.c_str(), it->second.phone.c_str(), it->second.adress.c_str());
                count++;
        }

        fclose(fp);
        return count;
}

int book::read_from_file(fs::path fname)
{
    person current;
    std::string name;
    fs::ifstream file(fname);
    while(file >> name >> current.phone >> current.adress)
        book_data_[name] = current;
    file.close();
    return 0;
}


book::book()
{
    std::cout << "enter the path to handbook" << std::endl;

    std::cin >> path_;

    std::fstream file_settings;
    file_settings.open("data.txt", std::ios_base::trunc | std::ios_base::in | std::ios_base::out);

    if (!file_settings.is_open())
    {
       std::cout << "cannot open file" << std::endl;
    }
    else
    {
        read_from_file(path_);
    }

}

book::~book()
{
    write_to_file(book::path_, book_data_);
}

void book::list_entries()
{
    auto it = book_data_.begin();
    while(it != book_data_.end())
    {
    std::cout << "\n" << "name: " << it->first << "\n"
              "phone: " << it->second.phone << "\n"
              "address: " << it->second.adress << "\n";
    it++;
    }
}

void book::add_entry()
{
    person person1;
    std::cout << "enter the name" << std::endl;
    std::string name;
    std::cin >> name;
    std::cout << "enter the phone" << std::endl;
    std::cin >> person1.phone;
    std::cout << "enter the address" << std::endl;
    std::cin >> person1.adress;

    book_data_.insert(std::make_pair(name, person1));
}

void book::delete_entry()
{
    std::cout << "enter the entry name you want to delete: " << std::endl;
    std::string name;
    std::cin >> name;
    auto it = book_data_.find(name);
    char confirm('n');
    if (book_data_.find(name) != book_data_.end())
    {
        std::cout << "Are you sure you want to delete this note?" << std::endl;
        std::cout << it->first << " :: " << it->second.phone << " :: " << it->second.adress << std::endl;
        std::cout << "y/n?" << std::endl;
        std::cin >> confirm;
    }
    if (confirm == 'y')
        book_data_.erase(it);
}

std::map<std::string, book::person>::iterator book::find_entry(std::string search_string, std::map<std::string, book::person> data)
{
    auto it = data.find(search_string);
    if (it != data.end())
        return it;
}
