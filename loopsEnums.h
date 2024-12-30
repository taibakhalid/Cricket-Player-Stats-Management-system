#ifndef LOOPSENUMS_H
#define LOOPSENUMS_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
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
string playerTypeToString(PlayerType type);
void displayPlayerDetails(const Player &player);

#endif