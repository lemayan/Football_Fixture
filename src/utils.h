#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

struct Team {
    std::string name;
    std::string town;
    std::string stadium;
};

class Utils {
public:
    // Here we have now created a Function that will be able to read teams from the CSV file
    static std::vector<Team> readTeamsFromCSV(const std::string& filename) {
        std::vector<Team> teams;
        std::ifstream file(filename);
        std::string line, name, town, stadium;

        // The purpose of this code will be to help Skip header line
        std::getline(file, line);

        //For this it will Read the data from the CSV file
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::getline(ss, name, ',');
            std::getline(ss, town, ',');
            std::getline(ss, stadium, ',');
            teams.push_back({name, town, stadium});
        }

        file.close();
        return teams;
    }

    // This Function will now be able to save the generated fixtures into a CSV file
    static void saveFixturesToCSV(const std::string& filename, const std::vector<std::string>& fixtures) {
        std::ofstream file(filename);
        for (const auto& fixture: fixtures) {
            file << fixture << std::endl;
        }
        file.close();
    }

    // Here we create a Function to print the generated fixtures to the console
    static void printFixtures(const std::vector<std::string>& fixtures) {
        for (const auto& fixture : fixtures) {
            std::cout << fixture << std::endl;
        }
    }
};

#endif
