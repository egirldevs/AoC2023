#include "advent_days.hpp"

#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include "advent_logging.hpp" 

std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream tokenStream(s);
    std::string token;
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

bool isGamePossible(const std::string& input, int targetRed, int targetGreen, int targetBlue) {
    std::vector<std::string> tokens = split(input, ';');

    std::set<std::string> cubeCounts;
    for (const std::string& token : tokens) {
        std::vector<std::string> colors = split(token, ' ');
        cubeCounts.insert(colors[1]);
    }

    for (const std::string& count : cubeCounts) {
        std::vector<std::string> colorCount = split(count, ' ');
        int countValue = std::stoi(colorCount[0]);
        std::string color = colorCount[1];

        if ((color == "red" && countValue > targetRed) ||
            (color == "green" && countValue > targetGreen) ||
            (color == "blue" && countValue > targetBlue)) {
            return false;
        }
    }

    return true;
}

int main() {
    int targetRed = 12;
    int targetGreen = 13;
    int targetBlue = 14;

    std::string input;
    while (std::getline(std::cin, input)) {
        size_t pos = input.find(':');
        if (pos != std::string::npos) {
            std::string gameId = input.substr(5, pos - 6);

            if (isGamePossible(input, targetRed, targetGreen, targetBlue)) {
                advent::Logger::log(advent::LogLevel::INFO, "Game " + gameId + " is possible.");
            } else {
                advent::Logger::log(advent::LogLevel::INFO, "Game " + gameId + " is not possible.");
            }
        }
    }

    return 0;
}
