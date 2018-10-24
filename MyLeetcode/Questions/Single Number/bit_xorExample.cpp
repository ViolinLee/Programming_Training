#include <iostream>     // std::cout
#include <functional>   // std::bit_xor
#include <algorithm>    // std::accumulate
#include <iterator>     // std::end

int main () {
  // 累 ^ 操作：1^2^3^4^5^6^7^8^9^10;
  int flags[] = {1,2,3,4,5,6,7,8,9,10};
  int acc = std::accumulate (flags, std::end(flags), 0, std::bit_xor<int>());
  std::cout << "xor: " << acc << '\n';
  
  // 重要套路：a^b^a == a^a^b == b 
  int a = 3;
  int b = 5;
  int c = (a^b)^b;
  std::cout << c << std::endl; 
  
  return 0;
}
