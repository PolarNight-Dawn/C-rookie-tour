//
// Created by polarnight on 24-8-31, 上午11:20.
//

#include <iostream>

class Transaction {
 public:
  Transaction() { init(); }
  virtual void LogTransaction() const { std::cout << "base class" << std::endl; }

 private:
  void init() { LogTransaction(); }
};

class BuyTransaction : public Transaction {
 public:
  virtual void LogTransaction() const { std::cout << "derived class" << std::endl; }
};

int main() {
  BuyTransaction b;

  return 0;
};

