#ifndef LEPTJSON_H__
#define LEPTJSON_H__
#include <stddef.h>

#define lept_set_null(v) lept_free(v)
#define lept_init(v)       \
  do {                     \
    (v)->type = LEPT_NULL; \
  } while (0)
typedef struct lept_value lept_value;
typedef enum {
  LEPT_NULL,
  LEPT_FALSE,
  LEPT_TRUE,
  LEPT_NUMBER,
  LEPT_STRING,
  LEPT_ARRAY,
  LEPT_OBJECT
} lept_type;

struct lept_value {
  union {
    struct {
      char* s;
      size_t len;
    } s;
    struct {
      lept_value* e;
      size_t size; /*element number*/
    } a;
    double n;
  } u;
  lept_type type;
};

enum {
  LEPT_PARSE_OK = 0,
  LEPT_PARSE_EXPECT_VALUE,
  LEPT_PARSE_INVALID_VALUE,
  LEPT_PARSE_ROOT_NOT_SINGULAR,
  LEPT_PARSE_NUMBER_TOO_BIG,
  LEPT_PARSE_MISS_QUOTATION_MARK,
  LEPT_PARSE_INVALID_STRING_ESCAPE,
  LEPT_PARSE_INVALID_STRING_CHAR,
  LEPT_PARSE_INVALID_UNICODE_HEX,
  LEPT_PARSE_INVALID_UNICODE_SURROGATE,
  LEPT_PARSE_MISS_COMMA_OR_SQUARE_BRACKET
};

void lept_free(lept_value*);

int lept_parse(lept_value* v, const char* json);

lept_type lept_get_type(const lept_value* v);

double lept_get_number(const lept_value* v);
void lept_set_number(lept_value* v, double n);

int lept_get_boolean(const lept_value* v);
void lept_set_boolean(lept_value* v, int b);

const char* lept_get_string(const lept_value* v);
size_t lept_get_string_length(const lept_value* v);
void lept_set_string(lept_value* v, const char* s, size_t len);

size_t lept_get_array_size(const lept_value*);
lept_value* lept_get_array_element(const lept_value*, size_t);
#endif /* LEPTJSON_H__ */