#include <php.h>

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
  php_printf("zyc's first test\n");
}
