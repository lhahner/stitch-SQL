/**========================================================================
 * 2025 March 25
 * 
 * Tests the Cide running in tokenizer, this code is only executed during
 * development.
 *========================================================================**/
#include "includes/sitich-sql.h"
#include "includes/test_sitich-sql.h"

const char* levels[] = {"SUCCESS","FAILURE"};

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

int test_stitichSQL_getTokenClass(){
    char* vtest[] = {"@Test", "{"};
    
    int t = stitichSQL_getTokenClass((unsigned char**)vtest, sizeof(vtest));
    if(t == 3){
        fprintf(stdout, "[%s] - test_stitichSQL_getToken_bracket value: %d \n", levels[0], t);
        return 1;
    }
    else {
        fprintf(stderr, "[%s] - test_stitichSQL_getToken_bracket value: %d \n", levels[1], t);
        return -1;
    }
}

int test_stitichSQL_getToken_comment(){
    int type;
    char* tests = "-- Hello World";
    stitichSQL_getToken(tests, &type);

    if(type == 13){
        fprintf(stdout, "[%s] - test_stitichSQL_getToken_bracket value: %d \n", levels[0], type);
        return 1;
    }
    else {
        fprintf(stderr, "[%s] - test_stitichSQL_getToken_bracket value: %d \n", levels[1], type);
        return -1;
    }
}