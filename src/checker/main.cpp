// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include <string_view>

// returns false if the line has the same character three times in a row
bool TripleCharCheck(std::string_view line) {
  char c{0};
  int amt{};
  for (size_t i{}; i < line.length(); ++i) {
    if (line[i] == c) {
      ++amt;
      if (amt >= 3) return false;
    } else {
      amt = 1;
      c = line[i];
    }
  }
  return true;
}

// returns false if given char repeats n times in line
bool XNCharCheck(char x, int n, std::string_view line) {
  int amt{};
  for (size_t i{}; i < line.length(); ++i) {
    if (line[i] == x) {
      ++amt;
      if (amt >= n) return false;
    } else {
      amt = 0;
    }
  }
  return true;
}

int main() {
  // open the file
  const std::string file_name{"out.txt"};
  std::ifstream fs{file_name};
  if (!fs.is_open()) {
    std::cerr << "Error: Could not open " << file_name << ".\n";
    return -1;
  }

  // read the lines
  for (std::string line; std::getline(fs, line);) {
    if (!TripleCharCheck(line)) continue;
    // https://english.stackexchange.com/questions/563650
    if (!XNCharCheck('Q', 2, line)) continue;
    if (!XNCharCheck('X', 2, line)) continue;
    if (!XNCharCheck('Y', 2, line)) continue;
    if (!XNCharCheck('J', 2, line)) continue;
    if (!XNCharCheck('U', 2, line)) continue;
    if (!XNCharCheck('W', 2, line)) continue;
    if (!XNCharCheck('I', 2, line)) continue;
    if (!XNCharCheck('V', 2, line)) continue;
    if (!XNCharCheck('H', 2, line)) continue;
    if (!XNCharCheck('K', 2, line)) continue;
    if (!XNCharCheck('A', 2, line)) continue;
    std::cout << line << '\n';
  }

  fs.close();
  return 0;
}
