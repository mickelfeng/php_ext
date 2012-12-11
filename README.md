php_ext
=======

Learning to write a php extension. This is a learning with some of my modification of the page below:
http://www.kchodorow.com/blog/2011/08/11/php-extensions-made-eldrich-hello-world/

host info:

CentOS 6 - i386, with following packages: php php-devel gcc g++

Initial compilation:

1. phpize the code:
[zyc@nepenthe php_ext]$ phpize
Configuring for:
PHP Api Version:         20090626
Zend Module Api No:      20090626
Zend Extension Api No:   220090626

2. run configure script
[zyc@nepenthe php_ext]$ ./configure 
checking for grep that handles long lines and -e... /bin/grep
checking for egrep... /bin/grep -E
checking for a sed that does not truncate output... /bin/sed
checking for cc... cc
checking for C compiler default output file name... a.out
checking whether the C compiler works... yes
checking whether we are cross compiling... no
checking for suffix of executables... 
checking for suffix of object files... o
checking whether we are using the GNU C compiler... yes
checking whether cc accepts -g... yes
checking for cc option to accept ISO C89... none needed
checking how to run the C preprocessor... cc -E
checking for icc... no
checking for suncc... no
checking whether cc understands -c and -o together... yes
checking for system library directory... lib
checking if compiler supports -R... no
checking if compiler supports -Wl,-rpath,... yes
checking build system type... i686-pc-linux-gnu
checking host system type... i686-pc-linux-gnu
checking target system type... i686-pc-linux-gnu
checking for PHP prefix... /usr
checking for PHP includes... -I/usr/include/php -I/usr/include/php/main -I/usr/include/php/TSRM -I/usr/include/php/Zend -I/usr/include/php/ext -I/usr/include/php/ext/date/lib
checking for PHP extension directory... /usr/lib/php/modules
checking for PHP installed headers prefix... /usr/include/php
checking if debug is enabled... no
checking if zts is enabled... no
checking for re2c... no
configure: WARNING: You will need re2c 0.13.4 or later if you want to regenerate PHP parsers.
checking for gawk... gawk
checking whether to enable zyc extension... yes, shared
checking for a sed that does not truncate output... (cached) /bin/sed
checking for fgrep... /bin/grep -F
checking for ld used by cc... /usr/bin/ld
checking if the linker (/usr/bin/ld) is GNU ld... yes
checking for BSD- or MS-compatible name lister (nm)... /usr/bin/nm -B
checking the name lister (/usr/bin/nm -B) interface... BSD nm
checking whether ln -s works... yes
checking the maximum length of command line arguments... 1966080
checking whether the shell understands some XSI constructs... yes
checking whether the shell understands "+="... yes
checking for /usr/bin/ld option to reload object files... -r
checking for objdump... objdump
checking how to recognize dependent libraries... pass_all
checking for ar... ar
checking for strip... strip
checking for ranlib... ranlib
checking command to parse /usr/bin/nm -B output from cc object... ok
checking for ANSI C header files... yes
checking for sys/types.h... yes
checking for sys/stat.h... yes
checking for stdlib.h... yes
checking for string.h... yes
checking for memory.h... yes
checking for strings.h... yes
checking for inttypes.h... yes
checking for stdint.h... yes
checking for unistd.h... yes
checking for dlfcn.h... yes
checking for objdir... .libs
checking if cc supports -fno-rtti -fno-exceptions... no
checking for cc option to produce PIC... -fPIC -DPIC
checking if cc PIC flag -fPIC -DPIC works... yes
checking if cc static flag -static works... no
checking if cc supports -c -o file.o... yes
checking if cc supports -c -o file.o... (cached) yes
checking whether the cc linker (/usr/bin/ld) supports shared libraries... yes
checking whether -lc should be explicitly linked in... no
checking dynamic linker characteristics... GNU/Linux ld.so
checking how to hardcode library paths into programs... immediate
checking whether stripping libraries is possible... yes
checking if libtool supports shared libraries... yes
checking whether to build shared libraries... yes
checking whether to build static libraries... no
configure: creating ./config.status
config.status: creating config.h
config.status: executing libtool commands
[zyc@nepenthe php_ext]$ 
[zyc@nepenthe php_ext]$ 


3. Compile the code
[zyc@nepenthe php_ext]$ make
/bin/sh /home/zyc/php_ext/libtool --mode=compile cc  -I. -I/home/zyc/php_ext -DPHP_ATOM_INC -I/home/zyc/php_ext/include -I/home/zyc/php_ext/main -I/home/zyc/php_ext -I/usr/include/php -I/usr/include/php/main -I/usr/include/php/TSRM -I/usr/include/php/Zend -I/usr/include/php/ext -I/usr/include/php/ext/date/lib  -DHAVE_CONFIG_H  -g -O2   -c /home/zyc/php_ext/php_zyc.c -o php_zyc.lo 
libtool: compile:  cc -I. -I/home/zyc/php_ext -DPHP_ATOM_INC -I/home/zyc/php_ext/include -I/home/zyc/php_ext/main -I/home/zyc/php_ext -I/usr/include/php -I/usr/include/php/main -I/usr/include/php/TSRM -I/usr/include/php/Zend -I/usr/include/php/ext -I/usr/include/php/ext/date/lib -DHAVE_CONFIG_H -g -O2 -c /home/zyc/php_ext/php_zyc.c  -fPIC -DPIC -o .libs/php_zyc.o
/bin/sh /home/zyc/php_ext/libtool --mode=link cc -DPHP_ATOM_INC -I/home/zyc/php_ext/include -I/home/zyc/php_ext/main -I/home/zyc/php_ext -I/usr/include/php -I/usr/include/php/main -I/usr/include/php/TSRM -I/usr/include/php/Zend -I/usr/include/php/ext -I/usr/include/php/ext/date/lib  -DHAVE_CONFIG_H  -g -O2   -o zyc.la -export-dynamic -avoid-version -prefer-pic -module -rpath /home/zyc/php_ext/modules  php_zyc.lo 
libtool: link: cc -shared  .libs/php_zyc.o      -Wl,-soname -Wl,zyc.so -o .libs/zyc.so
libtool: link: ( cd ".libs" && rm -f "zyc.la" && ln -s "../zyc.la" "zyc.la" )
/bin/sh /home/zyc/php_ext/libtool --mode=install cp ./zyc.la /home/zyc/php_ext/modules
libtool: install: cp ./.libs/zyc.so /home/zyc/php_ext/modules/zyc.so
libtool: install: cp ./.libs/zyc.lai /home/zyc/php_ext/modules/zyc.la
libtool: finish: PATH="/usr/local/bin:/bin:/usr/bin:/usr/local/sbin:/usr/sbin:/sbin:/home/zyc/bin:/sbin" ldconfig -n /home/zyc/php_ext/modules
----------------------------------------------------------------------
Libraries have been installed in:
   /home/zyc/php_ext/modules

If you ever happen to want to link against installed libraries
in a given directory, LIBDIR, you must either use libtool, and
specify the full pathname of the library, or use the `-LLIBDIR'
flag during linking and do at least one of the following:
   - add LIBDIR to the `LD_LIBRARY_PATH' environment variable
     during execution
   - add LIBDIR to the `LD_RUN_PATH' environment variable
     during linking
   - use the `-Wl,-rpath -Wl,LIBDIR' linker flag
   - have your system administrator add LIBDIR to `/etc/ld.so.conf'

See any operating system documentation about shared libraries for
more information, such as the ld(1) and ld.so(8) manual pages.
----------------------------------------------------------------------

Build complete.
Don't forget to run 'make test'.

4. test
[zyc@nepenthe php_ext]$ make test

Build complete.
Don't forget to run 'make test'.


=====================================================================
PHP         : /usr/bin/php 
PHP_SAPI    : cli
PHP_VERSION : 5.3.3
ZEND_VERSION: 2.3.0
PHP_OS      : Linux - Linux nepenthe 2.6.32-042stab055.10 #1 SMP Thu May 10 15:38:32 MSD 2012 i686
INI actual  : /home/zyc/php_ext/tmp-php.ini
More .INIs  :  
CWD         : /home/zyc/php_ext
Extra dirs  : 
VALGRIND    : Not used
=====================================================================
TIME START 2012-12-11 03:35:57
=====================================================================
No tests were run.

5. Install
[zyc@nepenthe php_ext]$ sudo make install
[sudo] password for zyc: 
Installing shared extensions:     /usr/lib/php/modules/

6. Load the extension
[zyc@nepenthe php_ext]$ cat /etc/php.d/zyc.ini 
extension=zyc.so
