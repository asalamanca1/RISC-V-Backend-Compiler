#include <stdio.h>
#include <stdlib.h>
#include "check_pow_two.h"
#include "test_pow_two.h"

int main(void){
    uint32_t random;
    int passCount=0;
    int failCount=0;
    uint32_t result=0;
    while(passCount<6){
        random=(uint32_t)rand();
        result = (uint32_t)checkPow2(random);
      
        if(result!=(uint32_t)(0)){
         
            passCount++;
            printf("Passed at %d\n", random);
            
        }

    }
    while(failCount<6){
        random=(uint32_t)rand();
        result = (uint32_t)checkPow2(random);
      
        if(result==(uint32_t)(0)){
      
            failCount++;
            printf("Failed at %d\n", random);
        }
    }
    return 0;
}