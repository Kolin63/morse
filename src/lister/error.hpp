// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#ifndef MORSE_SRC_ERROR_HPP_
#define MORSE_SRC_ERROR_HPP_

#include <iostream>

enum class Error {
  OK,
  NOT_A_CHAR,
};

std::ostream& operator<<(std::ostream& out, Error err);

#endif  // MORSE_SRC_ERROR_HPP_
