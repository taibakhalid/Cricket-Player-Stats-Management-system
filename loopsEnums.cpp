#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Enum to classify player types
enum PlayerType
{
    Batsman,
    Bowler,
    Wicketkeeper
};

// Struct to hold player statistics
struct Player
{
    string name;
    PlayerType type;
    int matchesPlayed;
    int runsScored;   // Only for batsmen
    int wicketsTaken; // Only for bowlers
    int catches;      // Only for wicketkeepers

    Player(string n, PlayerType t) : name(n), type(t), matchesPlayed(0), runsScored(0), wicketsTaken(0), catches(0) {}
};

// Function to display the player type as a string
string playerTypeToString(PlayerType type)
{
    switch (type)
    {
    case Batsman:
        return "Batsman";
    case Bowler:
        return "Bowler";
    case Wicketkeeper:
        return "Wicketkeeper";
    default:
        return "Unknown";
    }
}

// Function to display player details
void displayPlayerDetails(const Player &player)
{
    cout << left << setw(20) << player.name
         << setw(12) << playerTypeToString(player.type)
         << setw(15) << player.matchesPlayed;

    // Display stats based on player type
    if (player.type == Batsman)
    {
        cout << setw(12) << player.runsScored << endl;
    }
    else if (player.type == Bowler)
    {
        cout << setw(12) << player.wicketsTaken << endl;
    }
    else if (player.type == Wicketkeeper)
    {
        cout << setw(12) << player.catches << endl;
    }
}

// Main program
int main()
{
    vector<Player> players; // Vector to store players
    int choice;

    while (true)
    {
        // Display menu options
        cout << "\nMenu:\n";
        cout << "1. Add a player\n";
        cout << "2. Update player stats\n";
        cout << "3. Display all players\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            // Add a new player
            string name;
            int typeChoice;
            cout << "Enter player name: ";
            cin.ignore(); // Ignore leftover newline character
            getline(cin, name);

            cout << "Enter player type (1 - Batsman, 2 - Bowler, 3 - Wicketkeeper): ";
            cin >> typeChoice;
            PlayerType type = static_cast<PlayerType>(typeChoice - 1);

            // Create new player and add to list
            players.push_back(Player(name, type));
            cout << "Player added successfully!\n";
        }
        else if (choice == 2)
        {
            // Update player stats
            string name;
            cout << "Enter player name to update stats: ";
            cin.ignore(); // Ignore leftover newline character
            getline(cin, name);

            // Search for player by name
            bool found = false;
            for (size_t i = 0; i < players.size(); ++i)
            {
                if (players[i].name == name)
                {
                    found = true;
                    players[i].matchesPlayed++;

                    // Update stats based on player type
                    if (players[i].type == Batsman)
                    {
                        cout << "Enter runs scored in the match: ";
                        cin >> players[i].runsScored;
                    }
                    else if (players[i].type == Bowler)
                    {
                        cout << "Enter wickets taken in the match: ";
                        cin >> players[i].wicketsTaken;
                    }
                    else if (players[i].type == Wicketkeeper)
                    {
                        cout << "Enter catches taken in the match: ";
                        cin >> players[i].catches;
                    }
                    cout << "Player stats updated successfully!\n";
                    break;
                }
            }
            if (!found)
            {
                cout << "Player not found.\n";
            }
        }
        else if (choice == 3)
        {
            // Display all players
            if (players.empty())
            {
                cout << "No players available to display.\n";
            }
            else
            {
                cout << "\nPlayer Details:\n";
                cout << left << setw(20) << "Name"
                     << setw(12) << "Player Type"
                     << setw(15) << "Matches Played"
                     << setw(12) << "Statistics" << endl;
                for (size_t i = 0; i < players.size(); ++i)
                {
                    displayPlayerDetails(players[i]);
                }
            }
        }
        else if (choice == 4)
        {
            // Exit program
            cout << "Exiting program.\n";
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
} // this the end of the code
