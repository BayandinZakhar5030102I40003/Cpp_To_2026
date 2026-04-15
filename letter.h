#pragma once

#include <string>

#include "equation.h"
#include "solution.h"

class Letter {
 private:
  const std::string studName;
  const Equation func;
  const Solution answer;

 public:
  Letter(const std::string& name, const Equation& fnc, const Solution& ans)
      : studName(name), func(fnc), answer(ans) {}

  const std::string& getStudentName() const { return studName; }
  const Equation& getEquation() const { return func; }
  const Solution& getAnswer() const { return answer; }

  ~Letter() = default;
};