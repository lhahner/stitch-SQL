/**========================================================================
 * 2025 March 25
 * 
 * Tests the Cide running in tokenizer, this code is only executed during
 * development.
 *========================================================================**/
#include "includes/sitich-sql.h"

int test_getTokenClass(){
    return 0;
}

int test_stitichSQL_getToken(){
    int type;
    const char* vtest = "Hello";
    stitichSQL_getToken(vtest, &type);
    if(type == 2){
        fprintf(stdout, "[SUCCESS] - test_stitichSQL_getToken \n");
        return 0;
    }
    else {
        fprintf(stderr, "[FAILURE] - test_stitichSQL_getToken %d is not 2 \n", type);
        return -1;
    }
}