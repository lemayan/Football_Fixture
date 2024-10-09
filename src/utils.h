#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

struct Team {
    string name;
    string town;
    string stadium;
};

class Utils {
public:
    // Here we have now created a Function that will be able to read teams from the CSV file
    static vector<Team> readTeamsFromCSV(const std::string& filename) {
        vector<Team> teams;
        ifstream file(filename);
        string line, name, town, stadium;

        // The purpose of this code will be to help Skip header line
        getline(file, line);

        //For this it will Read the data from the CSV file
        while (getline(file, line)) {
            stringstream ss(line);
            getline(ss, name, ',');
            getline(ss, town, ',');
            getline(ss, stadium, ',');
            teams.push_back({name, town, stadium});
        }

        file.close();
        return teams;
    }

    // This Function will now be able to save the generated fixtures into a CSV file
    static void saveFixturesToCSV(const string& filename, const vector<string>& fixtures) {
        ofstream file(filename);
        for (const auto& fixture: fixtures) {
            file << fixture << std::endl;
        }
        file.close();
    }

    // Here we create a Function to print the generated fixtures to the console
    static void printFixtures(const vector<string>& fixtures) {
        for (const auto& fixture : fixtures) {
            cout << fixture << endl;
        }
    }
};

#endif
