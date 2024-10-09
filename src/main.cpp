#include <iostream>
#include <vector>
#include <string>
#include "utils.h"
using namespace std;

struct Match {
    string homeTeam;
    string awayTeam;
    string stadium;
    string town;
    int leg;        // for this i think we just assign 1 for first leg, 2 for second leg
    int weekend;
};

// So here we will now create a function that will generate fixtures for all our teams
vector<Match> generateFixtures(const vector<Team>& teams) {
    vector<Match> fixtures;
    int weekend = 1;

    // now for each pair of teams, we will generate home and away matches
    for (size_t i = 0; i < teams.size(); ++i) {
        for (size_t j = i + 1; j < teams.size(); ++j) {
            // First leg
            fixtures.push_back({teams[i].name, teams[j].name, teams[i].stadium, teams[i].town, 1, weekend});
            // Second leg
            fixtures.push_back({teams[j].name, teams[i].name, teams[j].stadium, teams[j].town, 2, weekend});

            // Here Only 4 teams should play per weekend, so after two matches we will increase the weekend count
            if (fixtures.size() % 2 == 0) {
                weekend++;
            }
        }
    }

    return fixtures;
}

int main() {
    string filename = "../data/teams_csvFile.csv"; // Here we have placed the Path to our CSV file

    cout << "Welcome to the our Kenyan Premier League Match Fixture Generator!\n";
    cout << "--------------------------------------------------------\n\n";//here we are creating a more user-friendly information

    // Step 1: Now Here we now Load our teams from our CSV file
    cout << "Loading teams from '" << filename << "'...\n";
    vector<Team> teams = Utils::readTeamsFromCSV(filename);

    if (teams.empty()) {
        cerr << "Error: No teams were loaded. Please check the file and try again.\n";
        return 1; // Exit the program with error...so here a non-zero status will show...this will indicate an error
    }

    cout << teams.size() << " teams successfully loaded.\n";

    // This will now allow us to Display teams
    cout << "Teams Loaded:\n";
    for (const auto& team : teams) {
        cout << "- " << team.name << " (Town: " << team.town << ", Stadium: " << team.stadium << ")\n";
    }

    cout << "\nGenerating match fixtures...\n";

    // Step 2: This step will Generate fixtures
    vector<Match> fixtures = generateFixtures(teams);

    // Step 3: Here we will Convert matches to string for easier display and saving
    vector<std::string> fixtureStrings;
    for (const auto& match : fixtures) {
        stringstream ss;
        ss << "Weekend " << match.weekend << ": "
           << match.homeTeam << " vs " << match.awayTeam
           << " at " << match.stadium << " (" << match.town << "), Leg " << match.leg;
        fixtureStrings.push_back(ss.str());
    }

    // Step 4: Now we Display our fixtures
    cout << "\nFixtures successfully generated! Displaying fixtures:\n";
    Utils::printFixtures(fixtureStrings);

    //  Here we Ask the user if they want to save the fixtures to a file
    char saveOption;
    cout << "\nWould you like to save the fixtures to a file? (y/n): ";
    cin >> saveOption;

    if (saveOption == 'y' || saveOption == 'Y') {
        string outputFilename = "../build/generated_fixtures.csv"; // Now this will be Saved in the build folder
        Utils::saveFixturesToCSV(outputFilename, fixtureStrings);
        cout << "Fixtures saved successfully to '" << outputFilename << "'!\n";
    } else {
        cout << "You chose not to save the fixtures.\n";
    }

    cout << "Thank you for using the Kenyan Premier League Match Fixture Generator!\n";
    return 0;
}