// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include <iostream>
#include <map>
#include <ostream>
#include <string>
#include <string_view>

enum class Error {
  OK,
  NOT_A_CHAR,
};

std::ostream& operator<<(std::ostream& out, Error err) {
  using enum Error;
  switch (err) {
    case OK:
      return out << "OK";
    case NOT_A_CHAR:
      return out << "Not a char";
  }
  return out << "Unknown Error";
}

constexpr const char* input = ".---.------.-.--";

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
  if (str[str.size() - 1] != ' ') [[likely]] str += ' ';
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
  Error err;
  std::cout << MakeWord("... --- ...", &err) << "\tError: " << err << '\n';
  return 0;
}
