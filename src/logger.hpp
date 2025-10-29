// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#ifndef MORSE_SRC_LOGGER_HPP_
#define MORSE_SRC_LOGGER_HPP_

#include <fstream>
#include <string>
#include <string_view>

class Logger {
 public:
  explicit Logger(std::string_view filename);
  ~Logger();
  // appends a new line
  void Log(std::string text);

 private:
  std::ofstream fs_{};
  std::string filename_;
};

#endif  // MORSE_SRC_LOGGER_HPP_
