#include <iostream>
#include "cryptopals.h"
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

std::string base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

std::vector<uint8_t> Cryptopals::hex2bytes(const std::string& s)
{
  std::vector<uint8_t> bytes_vector;
  for (size_t i = 0; i < s.size(); i+=2) {
      bytes_vector.push_back(static_cast<uint8_t>(std::stoi(s.substr(i, 2), nullptr, 16)));
  }
  return bytes_vector;
}


double Cryptopals::englishWordScoring(std::string input) {
    static const std::map<char, double> scoreperword = {
        {'a', 0.82}, {'b', 0.16}, {'c', 0.28}, {'d', 0.43}, 
        {'e', 1.28}, {'f', 0.22}, {'g', 0.20}, {'h', 0.61},
        {'i', 0.71}, {'j', 0.03}, {'k', 0.06}, {'l', 0.39},
        {'m', 0.23}, {'n', 0.70}, {'o', 0.76}, {'p', 0.19},
        {'q', 0.02}, {'r', 0.61}, {'s', 0.62}, {'t', 0.91},
        {'u', 0.28}, {'v', 0.09}, {'w', 0.23}, {'x', 0.03},
        {'y', 0.19}, {'z', 0.01}, {'0', 0.10}, {'1', 0.08},
        {'2', 0.08}, {'3', 0.08}, {'4', 0.08}, {'5', 0.08},
        {'6', 0.08}, {'7', 0.08}, {'8', 0.08}, {'9', 0.08},
        {' ', 0.68}
    };
    double str_score = 0;
    std::string lowercase_input = input;
    transform( lowercase_input.begin(), lowercase_input.end(), lowercase_input.begin(), ::tolower );  
    for (char c : lowercase_input) {
        if (scoreperword.find(c) != scoreperword.end()){
            str_score += scoreperword.at(c);
    }}
    return str_score;
}

std::vector<uint8_t> Cryptopals::singleByteXOR(const std::vector<uint8_t>& s, uint8_t key) {
    std::vector<uint8_t> output;
    for (size_t i = 0; i < s.size(); ++i) {
        output.push_back(s[i] ^ key);
    }
    return output;
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

std::vector<uint8_t> Cryptopals::fixedXor(std::vector<uint8_t>& i1, std::vector<uint8_t>& i2 ) {
  if (i1.size() > i2.size()) {
    i2.resize(i1.size(), 0);
  } else if (i2.size() > i2.size()) {
    i1.resize(i2.size(), 0);
  }
  std::vector<uint8_t> result(i1.size());
  for (size_t i = 0; i < i1.size(); ++i) {
    result[i] = i1[i] ^ i2[i];
    }

  return result;
}
