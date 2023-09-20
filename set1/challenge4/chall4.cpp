#include "../cryptopals.h"
#include <vector>
#include <cmath>
#include <fstream>


std::vector<std::string> rf(const std::string& filename) {
    std::vector<std::string> file_lines;
    std::string file_line;
    std::ifstream ifile(filename);
    while (std::getline(ifile, file_line)) {
        file_lines.push_back(file_line);
    }
    return file_lines;
}

int main(){
    Cryptopals c;
    std::vector<std::string> lines = rf("4.txt");
    double bestScore = 0.0;
    std::string bestDecryption;
    std::string encrypt;
    for (const auto& line : lines){
        if (line.length() != 60) continue;
        std::vector<uint8_t> s = c.hex2bytes(line); 
        for (uint8_t i = 1; i < 255; ++i) {
            std::vector<uint8_t> res = c.singleByteXOR(s, i);
            std::string res_str(res.begin(), res.end());
            double score = c.englishWordScoring(res_str);
                if (score > bestScore) {
                    bestScore = score;
                    bestDecryption = res_str;
                    encrypt = line;
            }
        }
    }
    std::cout << "score: " << bestScore << std::endl;
    std::cout << ": " << encrypt << std::endl;
    std::cout << "msg: " << bestDecryption << std::endl;
return 0;
}