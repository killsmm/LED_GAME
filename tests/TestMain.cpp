#include <gtest/gtest.h>

// Main function to run all the tests
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout << "Running tests..." << std::endl;
  return RUN_ALL_TESTS();
}