
#ifndef PHP_DEMO_H
#define PHP_DEMO_H

extern zend_module_entry demo_module_entry;
#define phpext_demo_ptr &demo_module_entry

#define PHP_DEMO_VERSION "0.1.0" /* Replace with version number for your extension */

#ifdef PHP_WIN32
#	define PHP_DEMO_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_DEMO_API __attribute__ ((visibility("default")))
#else
#	define PHP_DEMO_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(demo);
PHP_MSHUTDOWN_FUNCTION(demo);
PHP_RINIT_FUNCTION(demo);
PHP_RSHUTDOWN_FUNCTION(demo);
PHP_MINFO_FUNCTION(demo);

PHP_METHOD(demo, __construct);
PHP_METHOD(demo, __destruct);

PHP_METHOD(demo, set);
PHP_METHOD(demo, get);

#ifdef ZTS
#define DEMO_G(v) TSRMG(demo_globals_id, zend_demo_globals *, v)
#else
#define DEMO_G(v) (demo_globals.v)
#endif

#endif	/* PHP_DEMO_H */


