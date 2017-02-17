dnl $Id$
dnl config.m4 for extension vmath

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(vmath, for vmath support,
dnl Make sure that the comment is aligned:
dnl [  --with-vmath             Include vmath support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(vmath, whether to enable vmath support,
Make sure that the comment is aligned:
[  --enable-vmath           Enable vmath support])

if test "$PHP_VMATH" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-vmath -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/vmath.h"  # you most likely want to change this
  dnl if test -r $PHP_VMATH/$SEARCH_FOR; then # path given as parameter
  dnl   VMATH_DIR=$PHP_VMATH
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for vmath files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       VMATH_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$VMATH_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the vmath distribution])
  dnl fi

  dnl # --with-vmath -> add include path
  dnl PHP_ADD_INCLUDE($VMATH_DIR/include)

  dnl # --with-vmath -> check for lib and symbol presence
  dnl LIBNAME=vmath # you may want to change this
  dnl LIBSYMBOL=vmath # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $VMATH_DIR/$PHP_LIBDIR, VMATH_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_VMATHLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong vmath lib version or lib not found])
  dnl ],[
  dnl   -L$VMATH_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(VMATH_SHARED_LIBADD)

  PHP_NEW_EXTENSION(vmath, vmath.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
