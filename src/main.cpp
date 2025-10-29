// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
#include <ostream>
#include <string>

#include "error.hpp"
#include "logger.hpp"

const std::map<std::string, char> morse{
    {".-", 'A'},    {"-...", 'B'},  {"-.-.", 'C'},  {"-..", 'D'},
    {".", 'E'},     {"..-.", 'F'},  {"--.", 'G'},   {"....", 'H'},
    {"..", 'I'},    {".---", 'J'},  {"-.-", 'K'},   {".-..", 'L'},
    {"--", 'M'},    {"-.", 'N'},    {"---", 'O'},   {".--.", 'P'},
    {"--.-", 'Q'},  {".-.", 'R'},   {"...", 'S'},   {"-", 'T'},
    {"..-", 'U'},   {"...-", 'V'},  {".--", 'W'},   {"-..-", 'X'},
    {"-.--", 'Y'},  {"--..", 'Z'},  {"-----", '0'}, {".----", '1'},
    {"..---", '2'}, {"...--", '3'}, {"....-", '4'}, {".....", '5'},
    {"-....", '6'}, {"--...", '7'}, {"---..", '8'}, {"----.", '9'},
};

std::string MakeWord(std::string str, Error* err) {
  if (str[str.size() - 1] != ' ') [[likely]]
    str += ' ';
  std::string word{};
  std::string char_morse{};
  for (char i : str) {
    // for each character
    if (i == ' ') [[unlikely]] {
      // end of character
      if (auto search{morse.find(char_morse.c_str())}; search != morse.end()) {
        // add char to word
        word += search->second;
        char_morse = "";
      } else {
        // char doesn't exist - exit
        *err = Error::NOT_A_CHAR;
        return word;
      }
    } else {
      // add dot or dash to char morse
      char_morse += i;
    }
  }
  *err = Error::OK;
  return word;
}

int main() {
  // TODO(kolin63): make this read from stdin
  const std::string input = ".---.------.-.--";
  const size_t len{input.size()};
  assert(len > 0 && len < 64);
  const uint64_t max_count{static_cast<uint64_t>(std::pow(2, len - 1))};

  Logger logger{"out.txt"};

  // 1 indicates a space should come before the respective char
  for (uint64_t space_mask{}; space_mask < max_count; ++space_mask) {
    std::string fstr{};
    for (size_t i{}; i < len; ++i) {
      const int space_bit_mask{1 << (len - 1 - i)};
      if (space_mask & space_bit_mask) fstr += ' ';
      fstr += input[i];
    }
    Error err;
    std::string out{MakeWord(fstr, &err)};
    if (err == Error::OK) {
      logger.Log(out);
      std::cout << space_mask << ": " << out << " (" << fstr << ")\n";
    }
  }

  return 0;
}
