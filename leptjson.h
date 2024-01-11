#ifndef LEPTJSON_H_
#define LEPTJSON_H_
#include <assert.h>
#define NULL 0
typedef enum {
  LEPT_NULL,
  LEPT_FALSE,
  LEPT_TRUE,
  LEPT_NUMBER,
  LEPT_STRING,
  LEPT_ARRAY,
  LEPT_OBJECT
} lept_type; /*json element type*/

/*json elemnt value*/
typedef struct {
  lept_type type;
} lept_value;

/*test expectvalue*/
enum {
  LEPT_PARSE_OK = 0,
  LEPT_PARSE_EXPECT_VALUE,
  LEPT_PARSE_INVALID_VALUE,
  LEPT_PARSE_ROOT_NOT_SINGULAR
};

/*json context*/
typedef struct {
  const char* json;
} lept_context;

#endif