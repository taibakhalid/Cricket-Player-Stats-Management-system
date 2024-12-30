#ifndef POINTERS_H
#define POINTERS_H

#include <iostream>
#include <string>
using namespace std;

enum BattingStyle
{
    LeftHanded,
    RightHanded
};

enum PlayerRole
{
    Batsman,
    Bowler,
    Wicketkeeper
};

struct Player
{
    std::string name;
    int matchesPlayed;
    int runsScored;
    BattingStyle battingStyle;
    PlayerRole role;

    Player(const std::string &n, int matches, int runs, BattingStyle style, PlayerRole r)
        : name(n), matchesPlayed(matches), runsScored(runs), battingStyle(style), role(r) {}
};

void displayPlayerDetails(const Player &player);
void updatePlayerStats(Player &player);

#endif // POINTERS_H
