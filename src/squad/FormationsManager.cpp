#include "squad/FormationsManager.hpp"

#include <iostream>
#include <fstream>

FormationsManager *FormationsManager::instance()
{
    static FormationsManager formations_manager;
    return &formations_manager;
}

auto FormationsManager::showAll() const -> size_t
{
    constexpr static auto formation_number = formations.size();
    for (int i = 0; i < formation_number; ++i)
    {
        std::cout << i + 1 << ". " << formations.at(i) << std::endl;
    }
    return formation_number;
}

auto FormationsManager::getFormation(size_t index) -> std::string
{
    return formations.at(index);
}

FormationsManager::~FormationsManager()
{
    delete
}

FormationsManager::FormationsManager()
{
    constexpr auto file_name = "formations.csv";
    std::ifstream file{file_name};
    if (file.is_open())
    {
        std::string line;
        auto counter = 0;
        while (std::getline(file, line))
        {
            formations.at(counter) = line;
            counter++;
        }
        file.close();
    }
    else
    {
        std::cerr << "Error: Unable to open file " << file_name << std::endl;
        exit(1);
    }
}
