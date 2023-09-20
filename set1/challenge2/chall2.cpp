#include "../cryptopals.h"
#include <vector>


int main(){
  Cryptopals c;
  std::string i1 = "1c0111001f010100061a024b53535009181c";
  std::string i2 = "686974207468652062756c6c277320657965";
  std::vector<uint8_t> x = c.hex2bytes(i1);
  std::vector<uint8_t> y = c.hex2bytes(i2);
  std::vector<uint8_t> result = c.fixedXor(x, y);
  for (auto &byte : result) {
    std::cout << std::hex << static_cast<int>(byte);
  }
  std::cout << std::endl;
return 0;
}

