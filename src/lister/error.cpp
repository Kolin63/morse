// SPDX-License-Identifier: MIT
// Copyright (c) Colin Melican 2025

#include "error.hpp"

#include <iostream>

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
