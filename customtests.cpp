#include "catch.hpp"
#include "puzzleSolver.hpp"
#include "gradeYesAnswer.hpp"
#include <iostream>

namespace
{
    // TEST_CASE("xxSOLVE(POT + PAN = BIB)", "[solver]")
    // {
    //     std::unordered_map<char, unsigned> mapping;
    //     std::string s1 = "POT";
    //     std::string s2 = "PAN";
    //     std::string s3 = "BIB";


    //     bool const has_answer = puzzleSolver(s1, s2, s3, mapping);
    //     REQUIRE((has_answer && gradeYesAnswer(s1, s2, s3, mapping)));
    // }

    // TEST_CASE("xxSOLVE(UCI + ALEX = MIKE)", "[solver]")
    // {
    //     std::unordered_map<char, unsigned> mapping;
    //     std::string s1 = "UCI";
    //     std::string s2 = "ALEX";
    //     std::string s3 = "MIKE";

    //     bool const has_answer = puzzleSolver(s1, s2, s3, mapping);
    //     REQUIRE((has_answer && gradeYesAnswer(s1, s2, s3, mapping)));
    // }

    // TEST_CASE("xxSOLVE(SEND + MORE = MONEY)", "[solver]")
    // {
    //     std::unordered_map<char, unsigned> mapping;
    //     std::string s1 = "SEND";
    //     std::string s2 = "MORE";
    //     std::string s3 = "MONEY";

    //     bool const has_answer = puzzleSolver(s1, s2, s3, mapping);
    //     REQUIRE((has_answer && gradeYesAnswer(s1, s2, s3, mapping)));
    // }

    // TEST_CASE("xxSOLVE(LARRY + CAREER = LEGEND)", "[solver]")
    // {
    //     std::unordered_map<char, unsigned> mapping;
    //     std::string s1 = "LARRY";
    //     std::string s2 = "CAREER";
    //     std::string s3 = "LEGEND";

    //     REQUIRE_FALSE(puzzleSolver(s1, s2, s3, mapping));
    // }

    TEST_CASE("SOLVE(SEND + MORE = MONEY) TRUE", "[solver]") {
  std::unordered_map<char, unsigned> mapping;
  std::string s1 = "SEND";
  std::string s2 = "MORE";
  std::string s3 = "MONEY";

  bool const has_answer = puzzleSolver(s1, s2, s3, mapping);
  REQUIRE((has_answer && gradeYesAnswer(s1, s2, s3, mapping)));
}

TEST_CASE("SOLVE(EAT + THAT = APPLE) TRUE", "[solver]") {
  std::unordered_map<char, unsigned> mapping;
  std::string s1 = "EAT";
  std::string s2 = "THAT";
  std::string s3 = "APPLE";

  bool const has_answer = puzzleSolver(s1, s2, s3, mapping);
  REQUIRE((has_answer && gradeYesAnswer(s1, s2, s3, mapping)));
}

TEST_CASE("SOLVE(CATCH + BATCH = BATCH) FALSE", "[solver]") {
  std::unordered_map<char, unsigned> mapping;
  std::string s1 = "CATCH";
  std::string s2 = "BATCH";
  std::string s3 = "BATCH";

  REQUIRE_FALSE(puzzleSolver(s1, s2, s3, mapping));
}

TEST_CASE("SOLVE(ABCDEFGHIJ + FIJHDEBACG = IJHGFABCDE) MAX BOUND TOO BIG",
          "[solver]") {
  std::unordered_map<char, unsigned> mapping;
  std::string s1 = "ABCDEFGHIJ";
  std::string s2 = "FIJHDEBACG";
  std::string s3 = "IJHGFABCDE";

  REQUIRE_FALSE(puzzleSolver(s1, s2, s3, mapping));
}

TEST_CASE(
    "SOLVE(ABDDEFGHIJIJABDDEFGHIJ + JBADEFGHIJABDDEFGHIJ = "
    "ABCDEFGHIJABDDEFGHIJ) TOO LARGE LETTERS",
    "[solver]") {
  std::unordered_map<char, unsigned> mapping;
  std::string s1 = "ABDDEFGHIJIJABDDEFGHIJ";
  std::string s2 = "JBADEFGHIJABDDEFGHIJ";
  std::string s3 = "ABCDEFGHIJABDDEFGHIJ";

  REQUIRE_FALSE(puzzleSolver(s1, s2, s3, mapping));
}

TEST_CASE("SOLVE(AAAAAAAABCDEF + ABCDEF = GHIJKL) LEADING ZERO FALSE",
          "[solver]") {
  std::unordered_map<char, unsigned> mapping;
  std::string s1 = "AAAAAAAABCDEF";
  std::string s2 = "ABCDEF";
  std::string s3 = "GHIJKL";

  REQUIRE_FALSE(puzzleSolver(s1, s2, s3, mapping));
}

TEST_CASE("SOLVE(AAAAAAAAAABC + DEF = HIJ) LEADING ZERO TRUE", "[solver]") {
  std::unordered_map<char, unsigned> mapping;
  std::string s1 = "AAAAAAAAAABC";
  std::string s2 = "DEF";
  std::string s3 = "HIJ";

  bool const has_answer = puzzleSolver(s1, s2, s3, mapping);
  REQUIRE((has_answer && gradeYesAnswer(s1, s2, s3, mapping)));
}

} // namespace
