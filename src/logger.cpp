// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include "logger.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <string_view>

Logger::Logger(std::string_view filename) : filename_{filename} {
  fs_.open(filename_);
  std::cout << "Logger: Opened file " << filename_ << " for logging.\n";
}

Logger::~Logger() {
  fs_.close();
  std::cout << "Logger: Closed file " << filename_ << ".\n";
}

void Logger::Log(std::string text) { fs_ << text << '\n'; }
