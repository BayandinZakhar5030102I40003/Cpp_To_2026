#pragma once
#include <unordered_map>
#include <string>
#include <vector>

#include "letter.h"

class Teacher {
 private:
  std::vector<Letter> queue;
  std::unordered_map<std::string, int> results;

  bool Correct(const Solution& correct, const Solution& student);

 public:
  Teacher() {}
  void addSubmission(const Letter& sub);
  void checkAll();
  void printResults();
  void saveResultsToCSV(const std::string& filename);
  ~Teacher() = default;
};