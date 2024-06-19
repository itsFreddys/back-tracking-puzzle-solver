#ifndef __PUZZLE_SOLVER__HPP
#define __PUZZLE_SOLVER__HPP

#include <unordered_map>
#include <string>
#include <set>
#include <stack>

// PART 1 - Summation Puzzle Verifier. See project write-up for details.
bool puzzleVerifier(const std::string& s1, const std::string& s2, const std::string& s3, const std::unordered_map<char, unsigned> & mapping);

// PART 2 - Summation Puzzle Solver. See project write-up for details.
bool puzzleSolver(const std::string &s1, const std::string &s2, const std::string &s3, std::unordered_map<char, unsigned> &mapping);
bool rec_solver(size_t f_size, const std::string &s1, const std::string &s2, const std::string &s3,
                std::unordered_map<char, unsigned> &mapping, std::stack<char> &s_char, std::deque<unsigned> &s_val);
void get_stack_setup(const std::string &s1, const std::string &s2, const std::string &s3,
                     std::stack<char> &s_char);

#endif