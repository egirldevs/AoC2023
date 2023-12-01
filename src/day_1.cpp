#include "advent_days.hpp"

#include <cstdint>
#include <fstream>
#include <iostream>
#include <ranges>
#include <span>
#include <string>

namespace advent
{
static void puzzle_1()
{
	std::ifstream input_file{PROJECT_FOLDER "/inputs/day1"};
	std::uint32_t sum = 0;
	for (std::string line; std::getline(input_file, line);)
	{
		auto numeric_chars = line | std::ranges::views::filter([](char it) { return it > 47 && it < 58; });
		std::string number{numeric_chars.front(), numeric_chars.back()};
		sum += std::stoi(number);
	}
	std::cout << "The sum of all calibration values is: " << sum << '\n';
}
static void puzzle_2()
{
}
void day_1()
{
	std::cout << "Advent Of Code, Day 1" << '\n';
	std::cout << "Puzzle 1:" << '\n';
	puzzle_1();
	std::cout << "Puzzle 2:" << '\n';
	puzzle_2();
}
} // namespace advent
