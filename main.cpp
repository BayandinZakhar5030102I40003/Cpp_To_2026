#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "bad_student.h"
#include "equation.h"
#include "good_student.h"
#include "middle_student.h"
#include "teacher.h"

int main() {
  std::srand(std::time(0));

  std::vector<Equation> equations;

  std::ifstream file("equations.txt");
  if (!file.is_open()) {
    std::cerr << "Error" << std::endl;
    return 1;
  }

  double a, b, c;
  while (file >> a >> b >> c) {
    equations.emplace_back(a, b, c);
  }
  file.close();

  std::vector<Student*> students = {
      std::make_shared<MiddleStudent>("Sergey"),
      std::make_shared<GoodStudent>("Anton"),
      std::make_shared<MiddleStudent>("Petr"),
      std::make_shared<BadStudent>("Sasha"),
      std::make_shared<MiddleStudent>("Timur"),
      std::make_shared<MiddleStudent>("Timofei"),
      std::make_shared<BadStudent>("Zakhar"),
      std::make_shared<MiddleStudent>("Roman"),
      std::make_shared<GoodStudent>("Rafael Ambrosius Kusto"),
  };

  Teacher teacher;

  for (const auto& student : students) {
    for (const auto& eq : equations) {
      Solution ans = student->solve(eq);
      teacher.addSubmission(Letter(student->getName(), eq, ans));
    }
  }

  teacher.checkAll();
  teacher.printResults();
  teacher.saveResultsToCSV("results.csv");

  for (auto s : students) {
    delete s;
  }

  return 0;
}