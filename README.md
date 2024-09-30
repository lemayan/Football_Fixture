
# **Football Fixture Generator**

This project generates home and away fixtures for a set of football teams from a CSV file, displaying the schedule by weekends. You can also save the generated fixtures into a CSV file.

## **Features**
- Reads team data (team name, town, and stadium) from a CSV file.
- Generates home and away fixtures for all teams.
- Assigns matches to weekends, ensuring each team plays both home and away.
- Option to save the generated fixtures to a CSV file.

## **Project Structure**
- `main.cpp`: Contains the core logic for generating fixtures.
- `utils.h`: Utility functions for reading CSV files, printing fixtures, and saving fixtures to a file.
- `teams.csv`: CSV file containing team data such as team name, town, and stadium.

### **Team CSV Format**
The `teams.csv` file should follow this format:

```
Team Name, Local Town, Team Stadium
Cklein Starts, Nairobi, Cklein Arena
Wolves FC, Nairobi, Wolves
Dolphins FC, Mombasa, Dolphins
Sea Horses FC, Mombasa, SHorses Arena
...
```

## **How to Run**
1. Clone the repository:
    ```bash

    git clone https://github.com/lemayan/Football_Fixture.git

    
    cd fixture-generator
    ```

2. **Build the Project** in CLion or any C++ IDE.
    - Open the project folder in CLion and build the project.

3. **Run the Program**:
    - The program will load teams from the `teams.csv` file.
    - It will display the generated fixtures.
    - You can choose to save the fixtures to a CSV file.

4. **Saving Fixtures**:
    - The program will ask if you'd like to save the fixtures. If you choose `yes`, the fixtures will be saved to a file called `generated_fixtures.csv`.

## **Sample Output**
```
Welcome to the ABC Premier League Match Fixture Generator!
--------------------------------------------------------

Loading teams from '../data/teams_csvFile.csv'...
10 teams successfully loaded.
Teams Loaded:
- Cklein Starts (Town: Nairobi, Stadium: Cklein Arena)
- Wolves FC (Town: Nairobi, Stadium: Wolves)
...

Generating match fixtures...

Fixtures successfully generated! Displaying fixtures:
Weekend 1: Cklein Starts vs Wolves FC at Cklein Arena (Nairobi), Leg 1
Weekend 1: Wolves FC vs Cklein Starts at Wolves (Nairobi), Leg 2
...
```

## **Dependencies**
- **C++11 or later**: This project uses modern C++ features such as smart pointers and lambda functions.
- **CLion IDE**: Recommended for easy setup, but you can use any C++ IDE.

## **How to Contribute**
Feel free to fork the project, make improvements, and submit pull requests. Contributions are welcome!

---

For my students please feel free to modify the content according to your project's specifics or any extra features you want to highlight.
