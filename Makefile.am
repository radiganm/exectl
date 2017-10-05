## makefile.am
## Copyright 2016 Mac Radigan
## All Rights Reserved

AM_LDFLAGS  = -pthread                                      \
              -L/usr/lib -ldl -lm                           \
              -L/usr/lib/x86_64-linux-gnu -lgflags

AM_CPPFLAGS = -I$(top_srcdir)/include                       \
              -std=c++11
AM_FCFLAGS  = -Jmod

exectl_ldadd             = libexectl.la                     \
                           -ldl -lm                         \
                           -lrt                             \
                           -ltecla                           

bin_PROGRAMS             = exectl

exectl_SOURCES           = src/apps/exectl.cc
exectl_LDADD             = $(exectl_ldadd)

lib_LTLIBRARIES          = libexectl.la
libexectl_la_SOURCES     = src/packages/process/Process.cc

libexectl_la_LIBADD      = -lz                                                 \
                           -L/usr/lib/x86_64-linux-gnu -lrt

libexectl_la_LDFLAGS     = -export-symbols-regex '^exectl_[^_]' -fPIC          \
                           -shared -pthread                                    \
                           -L/usr/lib/x86_64-linux-gnu -lrt

pkginclude_HEADERS       = include/packages/process/Process.h

## *EOF*
