
#include "puzzleSolver.hpp"
#include <iostream>


// PART 1 - Summation Puzzle Verifier. See project write-up for details.
bool puzzleVerifier(const std::string& s1, const std::string& s2, const std::string& s3, const std::unordered_map<char, unsigned> &mapping)
{
    std::string val = "";
    char temp;
    int v1,v2,v3;

    for (size_t i=0; i < s1.size(); i++){
        temp = s1[i];
        val += std::to_string(mapping.at(temp));
    }
    try {
        v1 = std::stoi(val);
    }
    catch (const std::out_of_range& e){
        return false;
    }
    val = "";
    for (size_t i=0; i < s2.size(); i++){
        temp = s2[i];
        val += std::to_string(mapping.at(temp));
    }
    try {
        v2 = std::stoi(val);
    }
    catch (const std::out_of_range& e){
        return false;
    }
    val = "";
    for (size_t i=0; i < s3.size(); i++){
        temp = s3[i];
        val += std::to_string(mapping.at(temp));
    }
    try {
        v3 = std::stoi(val);
    }
    catch (const std::out_of_range& e){
        return false;
    }

    if (v3 == (v1 + v2)) {
        return true;
    }
    else
        return false;

}

// PART 2 - Summation Puzzle Solver. See project write-up for details.
bool puzzleSolver(const std::string &s1, const std::string &s2, const std::string &s3, std::unordered_map<char, unsigned> &mapping)
{
	// IMPLEMENT ME.
    // Hint: You should use the puzzleVerifier function above and recursion. Good luck :D
    std::stack<char> s_char;
    std::deque<unsigned> s_val = {0,1,2,3,4,5,6,7,8,9};

    get_stack_setup(s1,s2,s3,s_char);
    if (s_char.size() > 10) return false;

    size_t c_size = s_char.size();
    if(rec_solver(c_size, s1, s2, s3, mapping,s_char, s_val)){ return true;}
    return false;
}

void get_stack_setup(const std::string &s1, const std::string &s2, const std::string &s3,
                     std::stack<char> &s_char){
    std::set<char> temp_set;

    for (char i : s1){
        temp_set.insert(i);
    }
    for (char i : s2){
        temp_set.insert(i);
    }
    for (char i : s3){
        temp_set.insert(i);
    }

    for(const auto& value: temp_set) {
        s_char.push(value);
    }

}

bool rec_solver(size_t f_size, const std::string &s1, const std::string &s2, const std::string &s3,
                std::unordered_map<char, unsigned> &mapping, std::stack<char> &s_char, std::deque<unsigned> &s_val){

    if (s_char.empty() && mapping.size() == f_size){
        if (puzzleVerifier(s1, s2, s3, mapping)) {
            return true;
        }
        else return false;
    }
    const char c = s_char.top();
    size_t val_size = s_val.size();

    for (size_t i = 0; i < val_size; ++i){
        unsigned n = s_val.front();
        mapping[c] = n;
        s_val.pop_front();
        s_char.pop();

        if (rec_solver(f_size, s1, s2, s3, mapping, s_char, s_val)){
            return true;
        }
        else {
            s_val.push_back(n);
            s_char.push(c);
            mapping.erase(c);
        }
    }
    return false;
}

