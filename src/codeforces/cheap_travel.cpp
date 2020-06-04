/**
 * @file cheap_travel.cpp
 * @author Rahul Wadhwani
 * @brief https://codeforces.com/problemset/problem/466/A
 * @version 0.1
 * @date 2020-05-28
 * 
 * @copyright Copyright (c) 2020
 * 
 * Status: Not completed
 */

#include <iostream>

void solution() {
  int num_rides, m_rides, single_ticket_price, multi_ticket_price, amount = 0;
  std::cin >> num_rides >> m_rides >> single_ticket_price >> multi_ticket_price;
  double per_ride_price_multi = (double) m_rides / (double) multi_ticket_price;
  if(per_ride_price_multi < (double) single_ticket_price) {
    amount = (num_rides / m_rides) * multi_ticket_price;
    num_rides %= m_rides;
    amount += num_rides * single_ticket_price;
  } else {
    amount = num_rides * single_ticket_price;
  }
  std::cout << amount << std::endl;
}

int main() {
  solution();
}
