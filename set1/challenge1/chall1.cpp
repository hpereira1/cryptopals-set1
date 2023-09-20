#include <iostream>
#include <vector>
#include <string>
#include "cryptopals.h"



int main(){
  std::string s = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
  Cryptopals c;
  std::vector<uint8_t> byte_vec = c.hex2bytes(s);
  std::string result = c.bytes2base64(byte_vec);

  std::cout << result << std::endl;
  return 0;
}