
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "php_demo.h"

const zend_function_entry demo_functions[] = {
	PHP_ME(demo, __construct, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
		PHP_ME(demo, __destruct, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
		PHP_ME(demo, set, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
		PHP_ME(demo, get, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
		{NULL, NULL, NULL}
};

zend_module_entry demo_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"demo",
	demo_functions,
	PHP_MINIT(demo),
	PHP_MSHUTDOWN(demo),
	PHP_RINIT(demo),	/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(demo),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(demo),
#if ZEND_MODULE_API_NO >= 20010901
	PHP_DEMO_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_DEMO
ZEND_GET_MODULE(demo)
#endif

zend_class_entry *demo_ce = NULL;
PHP_MINIT_FUNCTION(demo)
{
	zend_class_entry demo;
	INIT_CLASS_ENTRY(demo, "demo", demo_functions);
	demo_ce=zend_register_internal_class_ex(&demo, NULL, NULL TSRMLS_CC);
	zend_declare_property_null(demo_ce, ZEND_STRL("name"), ZEND_ACC_PUBLIC TSRMLS_CC);
	fprintf(stdout, "PHP_MINIT_FUNCTION\n");
	return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(demo)
{
	fprintf(stdout, "PHP_MSHUTDOWN_FUNCTION\n");
	return SUCCESS;
}

PHP_RINIT_FUNCTION(demo)
{
	fprintf(stdout, "PHP_RINIT_FUNCTION\n");
	return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(demo)
{
	fprintf(stdout, "PHP_RSHUTDOWN_FUNCTION\n");
	return SUCCESS;
}

PHP_MINFO_FUNCTION(demo)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "demo support", "enabled");
	php_info_print_table_end();
}

PHP_METHOD(demo, __construct)
{

}

PHP_METHOD(demo, __destruct)
{

}

PHP_METHOD(demo, set)
{

	char *key = NULL;
	int key_size = 0;

	char *value = NULL;
	int value_size = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss",
				&key,
				&key_size,
				&value,
				&value_size
				) == FAILURE)
		return;


	fprintf(stdout, "%s:%s\n", key, value);
}

PHP_METHOD(demo, get)
{
	char *str = NULL;
	int len = spprintf(&str, 0, "美国");
	RETURN_STRINGL(str, len, 0);
}


