#pragma once

#include "solution.h"

class Equation {
 public:
  double a, b, c;

  Equation(double a, double b, double c) : a(a), b(b), c(c) {}
  ~Equation() = default;

  Solution solve() const;  
};