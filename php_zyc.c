#include <php.h>
#include <string.h>

#include "php_zyc.h"

zend_function_entry zyc_function[] = 
{
  PHP_FE(my_foo, NULL)
  {NULL, NULL, NULL}
};

zend_module_entry zyc_module_entry = 
{
  STANDARD_MODULE_HEADER,
  PHP_YZHANG_EXTNAME,
  zyc_function,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  PHP_YZHANG_VERSION,
  STANDARD_MODULE_PROPERTIES
};

ZEND_GET_MODULE(zyc)

PHP_FUNCTION(my_foo)
{
  char *phone_number = NULL;
  unsigned int len;
  if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &phone_number, &len) == FAILURE)
  {
    return;
  }

  if(strlen(phone_number) < PHONE_NUMBER_LEN - 1)
  {
    php_printf("zyc's phone number is: '%s'\n", phone_number);
  }
  else
  {
    php_printf("Phone Number must be shorter than %d characters\n", PHONE_NUMBER_LEN - 1);
  }
}
