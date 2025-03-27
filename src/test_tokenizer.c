/**========================================================================
 * 2025 March 25
 * 
 * Tests the Cide running in tokenizer, this code is only executed during
 * development.
 *========================================================================**/
#include "includes/sitich-sql.h"

const char* levels[] = {"SUCCESS","FAILURE"};
signed int assertEquals(int inputv, int exepected);

int test_getTokenClass(){
    return 0;
}

int test_stitichSQL_getToken_keyword(){
    int type;
    const char* vtest = "Hello";
    stitichSQL_getToken(vtest, &type);

    if(type == 2){
        fprintf(stdout, "[%s] - test_stitichSQL_getToken \n", levels[0]);
        return 0;
    }
    else {
        fprintf(stderr, "[%s] - test_stitichSQL_getToken %d is not 2 \n", levels[1], type);
        return -1;
    }
}

int test_stitichSQL_getToken_bracket(){
    int type;
    const char* vtest = "{";
    stitichSQL_getToken(vtest, &type);
    if(type == 3){
        fprintf(stdout, "[%s] - test_stitichSQL_getToken_bracket \n", levels[0]);
        return 1;
    }
    else {
        fprintf(stderr, "[%s] - test_stitichSQL_getToken_bracket %d is not 2 \n", levels[1], type);
        return -1;
    }
}

signed int assertEquals(int inputv, int exepected){
    return 0;
}