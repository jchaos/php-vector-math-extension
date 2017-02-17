/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2017 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_vmath.h"

/* If you declare any globals in php_vmath.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(vmath)
*/

/* True global resources - no need for thread safety here */
static int le_vmath;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("vmath.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_vmath_globals, vmath_globals)
    STD_PHP_INI_ENTRY("vmath.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_vmath_globals, vmath_globals)
PHP_INI_END()
*/
/* }}} */

/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_vmath_compiled(string arg)
   Return a string to confirm that the module is compiled in */

/***********vector plus***********/
PHP_FUNCTION(vec2Add)
{
    zval *ele0, *ele1, *ele2, *ele3;
    zval *leftVar, *rightVar;
    zval res0, res1;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "aa", &leftVar, &rightVar) == FAILURE)
    {
        return;
    }
    
    ele0 = zend_hash_index_find(Z_ARRVAL_P(leftVar), 0);
    ele1 = zend_hash_index_find(Z_ARRVAL_P(leftVar), 1);
    
    ele2 = zend_hash_index_find(Z_ARRVAL_P(rightVar), 0);
    ele3 = zend_hash_index_find(Z_ARRVAL_P(rightVar), 1);
    
    double d0, d1;
    d0 = Z_DVAL_P(ele0)+Z_DVAL_P(ele2);
    d1 = Z_DVAL_P(ele1)+Z_DVAL_P(ele3);
    ZVAL_DOUBLE(&res0, d0);
    ZVAL_DOUBLE(&res1, d1);
    
    array_init_size(return_value, 2);
    zend_hash_index_update(Z_ARRVAL_P(return_value), 0, &res0);
    zend_hash_index_update(Z_ARRVAL_P(return_value), 1, &res1);
}
/***********vector minus***********/
PHP_FUNCTION(vec2Sub)
{
    zval *ele0, *ele1, *ele2, *ele3;
    zval *leftVar, *rightVar;
    zval res0, res1;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "aa", &leftVar, &rightVar) == FAILURE)
    {
        return;
    }
    
    ele0 = zend_hash_index_find(Z_ARRVAL_P(leftVar), 0);
    ele1 = zend_hash_index_find(Z_ARRVAL_P(leftVar), 1);
    
    ele2 = zend_hash_index_find(Z_ARRVAL_P(rightVar), 0);
    ele3 = zend_hash_index_find(Z_ARRVAL_P(rightVar), 1);
    
    double d0, d1;
    d0 = Z_DVAL_P(ele0)-Z_DVAL_P(ele2);
    d1 = Z_DVAL_P(ele1)-Z_DVAL_P(ele3);
    ZVAL_DOUBLE(&res0, d0);
    ZVAL_DOUBLE(&res1, d1);
    
    array_init_size(return_value, 2);
    zend_hash_index_update(Z_ARRVAL_P(return_value), 0, &res0);
    zend_hash_index_update(Z_ARRVAL_P(return_value), 1, &res1);
}

/***********vector dot***********/
PHP_FUNCTION(vec2Dot)
{
    zval *ele0, *ele1, *ele2, *ele3;
    zval *leftVar, *rightVar;
    zval res0, res1;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "aa", &leftVar, &rightVar) == FAILURE)
    {
        return;
    }
    
    ele0 = zend_hash_index_find(Z_ARRVAL_P(leftVar), 0);
    ele1 = zend_hash_index_find(Z_ARRVAL_P(leftVar), 1);
    
    ele2 = zend_hash_index_find(Z_ARRVAL_P(rightVar), 0);
    ele3 = zend_hash_index_find(Z_ARRVAL_P(rightVar), 1);
    
    double d0, d1, dr;
    d0 = Z_DVAL_P(ele0)*Z_DVAL_P(ele2);
    d1 = Z_DVAL_P(ele1)*Z_DVAL_P(ele3);
    dr = d0 + d1;
    RETURN_DOUBLE(dr);
}
/***********vector cross***********/
PHP_FUNCTION(vec2Cro)
{
    zval *ele0, *ele1, *ele2, *ele3;
    zval *leftVar, *rightVar;
    zval res0, res1;
    
    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "aa", &leftVar, &rightVar) == FAILURE)
    {
        return;
    }
    
    ele0 = zend_hash_index_find(Z_ARRVAL_P(leftVar), 0);
    ele1 = zend_hash_index_find(Z_ARRVAL_P(leftVar), 1);
    
    ele2 = zend_hash_index_find(Z_ARRVAL_P(rightVar), 0);
    ele3 = zend_hash_index_find(Z_ARRVAL_P(rightVar), 1);
    
    double d0, d1, dr;
    d0 = Z_DVAL_P(ele0)*Z_DVAL_P(ele3);
    d1 = Z_DVAL_P(ele2)*Z_DVAL_P(ele1);
    dr = d0 - d1;
    RETURN_DOUBLE(dr);
}


PHP_FUNCTION(confirm_vmath_compiled)
{
	char *arg = NULL;
	size_t arg_len, len;
	zend_string *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	strg = strpprintf(0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "vmath", arg);

	RETURN_STR(strg);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and
   unfold functions in source code. See the corresponding marks just before
   function definition, where the functions purpose is also documented. Please
   follow this convention for the convenience of others editing your code.
*/


/* {{{ php_vmath_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_vmath_init_globals(zend_vmath_globals *vmath_globals)
{
	vmath_globals->global_value = 0;
	vmath_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(vmath)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(vmath)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(vmath)
{
#if defined(COMPILE_DL_VMATH) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(vmath)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(vmath)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "vmath support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ vmath_functions[]
 *
 * Every user visible function must have an entry in vmath_functions[].
 */
const zend_function_entry vmath_functions[] = {
    PHP_FE(vec2Add, NULL)
    PHP_FE(vec2Sub, NULL)
    PHP_FE(vec2Dot, NULL)
    PHP_FE(vec2Cro, NULL)
	PHP_FE(confirm_vmath_compiled,	NULL)		/* For testing, remove later. */
	PHP_FE_END	/* Must be the last line in vmath_functions[] */
};
/* }}} */

/* {{{ vmath_module_entry
 */
zend_module_entry vmath_module_entry = {
	STANDARD_MODULE_HEADER,
	"vmath",
	vmath_functions,
	PHP_MINIT(vmath),
	PHP_MSHUTDOWN(vmath),
	PHP_RINIT(vmath),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(vmath),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(vmath),
	PHP_VMATH_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_VMATH
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(vmath)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
