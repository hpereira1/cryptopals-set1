#include <string>
#include <iostream>
#include <vector>


class Cryptopals
{
  public:
    std::vector<uint8_t> hex2bytes(const std::string& s);
    std::string bytes2base64(std::vector<uint8_t> bytes);
  private:
};
