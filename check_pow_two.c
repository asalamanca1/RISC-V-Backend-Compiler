#include <stdlib.h>
#include <math.h>
#include "check_pow_two.h"

int checkPow2(uint32_t n){
  if(n==0){
    return 0;
  }
  return (n&(n-1))==0 ? (int)log2(n) : 0;

  
}
