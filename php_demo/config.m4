
PHP_ARG_ENABLE(demo, whether to enable demo support,
Make sure that the comment is aligned:
[--enable-demo Enable demo support])

PHP_NEW_EXTENSION(demo, demo.c, $ext_shared)
