/**========================================================================
 * 2025 March 25
 * 
 * Tests the Cide running in tokenizer, this code is only executed during
 * development.
 *========================================================================**/
#include "../stitch-SQL/includes/tokenizer.h"
#include "./includes/test_tokenizer.h"

int test_stitchSQL_getToken_keyword(){
    int type;
    const char* vtest = "Hello";
    stitchSQL_getToken(vtest, &type);
    assert(type == 2);

    return 0;
}

int test_stitchSQL_getToken_curly_bracket(){
    // Opening Curly Bracket
    int type;
    const char* vtest = "{";
    stitchSQL_getToken(vtest, &type);
    assert(type == 6);

    // Closing Curly Bracket
    int type2;
    const char* vtest2 = "}";
    stitchSQL_getToken(vtest2, &type2);
    assert(type2 == 7);

    return 0;
}

int test_stitchSQL_getTokenClass(){
    char* vtest[] = {"@Test", "{"};
    
    int t = stitchSQL_getTokenClass((unsigned char**)vtest, sizeof(vtest));
    assert(t == 6);

    return 0;
}

int test_stitchSQL_getToken_comment(){
    int type;
    char* tests = "-- Hello World";
    stitchSQL_getToken(tests, &type);
    assert(type == 13);

    return 0;
}

int test_stitchSQL_getToken_bracket(){
    // Opening Bracket
    int type1;
    char* test1 = "(";
    stitchSQL_getToken(test1, &type1);
    assert(type1 == 4);

    // Closing Bracket
    int type2;
    char* test2 = ")";
    stitchSQL_getToken(test2, &type2);
    printf("%d", type2);
    assert(type2 == 5);

    return 0;
}