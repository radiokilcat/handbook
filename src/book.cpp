#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

#include "book.hpp"

int WriteFile(std::string fname, std::map<std::string, std::string> *m) {
        int count = 0;
        if (m->empty())
                return 0;

        FILE *fp = fopen(fname.c_str(), "w");
        if (!fp)
                return -errno;

        for(std::map<std::string, std::string>::iterator it = m->begin(); it != m->end(); it++) {
                fprintf(fp, "%s=%s\n", it->first.c_str(), it->second.c_str());
                count++;
        }

        fclose(fp);
        return count;
}

int ReadFile(std::string fname, std::map<std::string, std::string> *m) {
        int count = 0;

        FILE *fp = fopen(fname.c_str(), "r");
        if (!fp)
                return -errno;
        m->clear();

        char *buf = 0;
        size_t buflen = 0;

        while(getline(&buf, &buflen, fp) > 0)
        {                                                     // File parsing
                char *nl = strchr(buf, '\n');
                if (nl == NULL)
                        continue;
                *nl = 0;

                char *sep = strchr(buf, '=');
                if (sep == NULL)
                        continue;
                *sep = 0;
                sep++;

                std::string s1 = buf;
                std::string s2 = sep;

                (*m)[s1] = s2;

                count++;
        }

        if (buf)
                free(buf);

        fclose(fp);
        return count;
}

book::book()
{
    //std::cout << "enter the path to handbook" << std::endl;

    std::cin >> path;

    std::fstream file_settings;
    file_settings.open("data.txt", std::ios_base::trunc | std::ios_base::in | std::ios_base::out);

    if (!file_settings.is_open())
    {
       std::cout << "cannot open file" << std::endl;
    }
    else
    {
       ReadFile(path, &book_data);
    }
}
book::~book()
{
    WriteFile(path, &book_data);

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
