#include "../cryptopals.h"
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

int main(){
Cryptopals c;
    std::string i1 = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
    const std::vector<uint8_t> s = c.hex2bytes(i1);
    double bestScore = 0.0;
    std::string bestDecryption;
    uint8_t bestKey = 0;
    for (uint8_t i = 1; i < 255;i++) {
        std::vector<uint8_t> res = c.singleByteXOR(s, i);
        std::string res_str(res.begin(), res.end());
        double score = c.englishWordScoring(res_str);
        if (score > bestScore) {
            bestScore = score;
            bestDecryption = res_str;
            bestKey = i;
    }    
    }
    std::cout << "score: " << bestScore << std::endl;
    std::cout << "key: " << (int)bestKey << std::endl;
    std::cout << "decryption: " << bestDecryption << std::endl;
return 0;
}