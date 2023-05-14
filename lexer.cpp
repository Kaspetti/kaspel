#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <regex>


enum class TokenType {
    IDENTIFIER,
    KEYWORD,
    OPERATOR,
    LITERAL,
    COMMENT,
    DELIMITER
};


std::unordered_map<std::string, std::string> keyword_patterns = {
    {"int", R"(int\s+[a-zA-Z][a-zA-Z0-9-_]+\s*=\s*\d+\s*;)"}
};


/**
 * Splits a string into a vector of strings based on a delimiter
 * @param str The string to split
 * @param delimiter The delimiter to split the string on
 * @return A vector of strings
 */
std::vector<std::string> split_string (const std::string &str, const std::string &delimiter) {
    std::vector<std::string> strings;
    std::string::size_type start_index = 0;
    std::string::size_type end_index = str.find(delimiter);

    while (end_index != std::string::npos) {
        strings.push_back(str.substr(start_index, end_index - start_index + 1));
        start_index = end_index + delimiter.length();
        end_index = str.find(delimiter, start_index);
    }
    strings.push_back(str.substr(start_index));

    return strings;
}


/*
 * Reads the contents of a file into a vector of strings
 * @param path The path to the file
 * @return A vector of strings representing the lines of the file
 */
std::vector<std::string> get_file_contents(const std::string &path) {
    std::ifstream file;
    std::string file_contents;

    file.open("test.kl");

    if (file.is_open()) {
        std::string line;
        while(getline(file, line)) {
            file_contents += line;
        }
    }
    else {
        throw std::invalid_argument("Could not open file");
    }
    file.close();

    return split_string(file_contents, ";");
}


void parse_line(const std::string &line) {
    std::cout << line << std::endl;
    const std::string &pattern = keyword_patterns["int"];
    std::regex regex(pattern);
    std::smatch match;

    if (std::regex_search(line, match, regex)) {
        std::cout << match[0] << std::endl;
    }
    else {
        std::smatch failed_match;
        std::regex_search(line, failed_match, std::regex(".*"));
        std::cout << "Failed to match: " << failed_match[0] << std::endl;
    }
}


int main() {
    std::vector<std::string> lines = get_file_contents("test.kl");
    parse_line(lines.front());
    return 0;
}
