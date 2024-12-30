#include "pointers.h"

// Function to display player details using pointers
void displayPlayerDetails(Player *player)
{
    cout << "Player Name: " << player->name << endl;
    cout << "Matches Played: " << player->matchesPlayed << endl;
    cout << "Runs Scored: " << player->runsScored << endl;
    cout << "Batting Style: "
         << (player->battingStyle == LeftHanded ? "Left-Handed" : "Right-Handed") << endl;
    cout << "Role: "
         << (player->role == Batsman ? "Batsman" : player->role == Bowler ? "Bowler"
                                                                          : "Wicketkeeper")

         << endl;
}

// Function to update player stats using pointers
void updatePlayerStats(Player *player)
{
    cout << "Updating stats for: " << player->name << endl;

    // Update matches played
    player->matchesPlayed++;
    cout << "Matches Played updated to: " << player->matchesPlayed << endl;

    // Update runs or role-specific stats
    if (player->role == Batsman)
    {
        int newRuns;
        cout << "Enter runs scored in the last match: ";
        cin >> newRuns;

        if (newRuns < 0)
        {
            cout << "Runs cannot be negative. No changes made." << endl;
        }
        else
        {
            player->runsScored += newRuns;
            cout << "Total Runs updated to: " << player->runsScored << endl;
        }
    }
    else if (player->role == Bowler)
    {
        int newWickets;
        cout << "Enter wickets taken in the last match: ";
        cin >> newWickets;

        if (newWickets < 0)
        {
            cout << "Wickets cannot be negative. No changes made." << endl;
        }
        else
        {
            cout << "Wickets taken: " << newWickets << endl;
        }
    }
    else if (player->role == Wicketkeeper)
    {
        int newCatches;
        cout << "Enter catches taken in the last match: ";
        cin >> newCatches;

        if (newCatches < 0)
        {
            cout << "Catches cannot be negative. No changes made." << endl;
        }
        else
        {
            cout << "Catches taken: " << newCatches << endl;
        }
    }
}

int main()
{
    // Input for player's name
    string name;
    cout << "Enter player name: ";
    cin.ignore(); // Clear newline buffer
    getline(cin, name);

    // Input for matches played
    int matches;
    cout << "Enter matches played: ";
    cin >> matches;

    // Input for runs scored
    int runs;
    cout << "Enter runs scored: ";
    cin >> runs;

    // Input for batting style
    BattingStyle style;
    int styleInput;
    cout << "Enter batting style (1 for Right-Handed, 2 for Left-Handed): ";
    cin >> styleInput;

    if (styleInput == 1)
    {
        style = RightHanded;
    }
    else if (styleInput == 2)
    {
        style = LeftHanded;
    }
    else
    {
        cout << "Invalid input. Defaulting to Right-Handed." << endl;
        style = RightHanded;
    }

    // Input for role
    PlayerRole role;
    int roleInput;
    cout << "Enter player role (1 for Batsman, 2 for Bowler, 3 for Wicketkeeper): ";
    cin >> roleInput;

    if (roleInput == 1)
    {
        role = Batsman;
    }
    else if (roleInput == 2)
    {
        role = Bowler;
    }
    else if (roleInput == 3)
    {
        role = Wicketkeeper;
    }
    else
    {
        cout << "Invalid input. Defaulting to Batsman." << endl;
        role = Batsman;
    }

    // Dynamically create a player using pointers
    Player *player1 = new Player(name, matches, runs, style, role);

    // Display initial details
    cout << "\nInitial Player Details:" << endl;
    displayPlayerDetails(player1);

    // Update stats
    cout << "\n--- Updating Player Stats ---\n";
    updatePlayerStats(player1);

    // Display updated details
    cout << "\nUpdated Player Details:" << endl;
    displayPlayerDetails(player1);

    // Free the dynamically allocated memory
    delete player1;

    return 0;
}
