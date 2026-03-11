// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value <= 1)
    return false;
  for (uint64_t i = 2; i * i <= value); i++) {
    if (value % i == 0)
      return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  uint64_t number = 0;
  for (uint64_t i = 2; i <= n; i++) {
    if (checlPrime(i) == true)
      number++;
  }
  return number;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t next = 0;
  while (next == 0) {
    value++;
    if (checkPrime(value) == true) {
      next = value;
    }
  }
  return next;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t summ = 0;
  for (uint64_t i = 2; i < hbound; i++) {
    if (checlPrime(i) == true)
      summ+=i;
  }
  return summ;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  uint64_t count = 0;
  for (uint64_t i = lbound; i < hbound; i++) {
    if (checkPrime(i) == true) {
      if (nextPrime(i) - i == 2)
        count++;
    }
  }
  return count;
}
