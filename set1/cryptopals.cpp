#include <iostream>
#include "cryptopals.h"


std::string base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

std::vector<uint8_t> Cryptopals::hex2bytes(const std::string& s)
{
  std::vector<uint8_t> bytes_vector;
  for (size_t i = 0; i < s.size(); i+=2) {
      bytes_vector.push_back(static_cast<uint8_t>(std::stoi(s.substr(i, 2), nullptr, 16)));
  }
  std::size_t remainder = bytes_vector.size() % 3;
  if (remainder > 0) {
    for (size_t i = 0; i < remainder; i++) {
      bytes_vector.push_back(0);
    }
  } 
  return bytes_vector;
}

std::string Cryptopals::bytes2base64(std::vector<uint8_t> bytes)
{

  std::string b64_str;

  for(size_t i = 0; i < bytes.size(); i += 3) {
    uint32_t bytes_concat = 0;
    bytes_concat |= (bytes[i] << 16);
    if (i + 1 < bytes.size()) {
      bytes_concat |= (bytes[i + 1] << 8);
    }
    if (i + 2 < bytes.size()) {
      bytes_concat |= (bytes[i + 2]);
    }

    for (int j = 3; j >= 0; --j) {
      uint8_t six_bits = (bytes_concat >> (j * 6)) & 0x3F; //00111111
      b64_str.push_back(base64[six_bits]);
    }
  }
  return b64_str;
}
