#include <string>
#include <iostream>
#include <vector>


class Cryptopals
{
  public:
    std::vector<uint8_t> hex2bytes(const std::string& s);
    std::string bytes2base64(std::vector<uint8_t> bytes);
    std::vector<uint8_t> fixedXor(std::vector<uint8_t>& i1, std::vector<uint8_t>& i2 );
    double englishWordScoring(std::string input);
    std::vector<uint8_t> singleByteXOR(const std::vector<uint8_t>& s, uint8_t key);
  private:
  
};  
