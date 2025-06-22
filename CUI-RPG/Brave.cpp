#include "Brave.hpp"
#include <map>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

using level_t = unsigned short;
using exp_t = unsigned short;
using string = string;

map<level_t, exp_t> Brave::GenerateLevelToExp()
{
    ifstream file("leveltable.csv");
    if (!file.is_open()) {
        cerr << "can't open file" << endl;
        exit(EXIT_FAILURE);
    }

    map levelToExp;
    string line;
    level_t level;
    exp_t exp;
    getline(file, line);

    while (getline(file, line)) {
        level = stoi(line.substr(0, line.find(',')));
        exp = stoi(line.substr(line.find(',') + 1));

        levelToExp.insert(std::make_pair(level, exp));
    }

    return levelToExp;
}