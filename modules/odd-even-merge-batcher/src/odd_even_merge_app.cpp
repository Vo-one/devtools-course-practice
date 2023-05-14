// Copyright 2023 Elistratov Vladimir

#include "include/odd_even_merge_app.h"

#include <exception>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "include/odd_even_merge.h"

std::string OddEvenMergeApplication::operator()(int argc, const char** argv) {
  if (argc <= 1) return printHelp(argv[0]);

  const int sizeArray = std::stoi(argv[1]);
  std::vector<int> array = OddEvenMerge::getRandomArray(sizeArray);

  std::cout << "Original array:" << std::endl;
  for (int i = 0; i < sizeArray; i++) std::cout << array[i] << " ";
  std::cout << std::endl;

  OddEvenMerge::OddEvenMergeBatcherSort(&array);

  std::cout << "Sorted array:" << std::endl;
  for (int i = 0; i < sizeArray; i++) std::cout << array[i] << " ";
  std::cout << std::endl;

  return "";
}

std::string OddEvenMergeApplication::printHelp(const std::string& programName) {
  std::stringstream ss;
  ss << "Usage: " << programName << " sizeArray" << std::endl;
  return ss.str();
}
