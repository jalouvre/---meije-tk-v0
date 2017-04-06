# from https://github.com/LuaDist/libgd/blob/master/cmake/modules/AC_HEADER_STDC.cmake

message(STATUS "Checking whether system has ANSI C header files")
include(CheckPrototypeExists)

include(CheckPrototypeExists)
check_include_files("dlfcn.h;stdint.h;stddef.h;inttypes.h;stdlib.h;strings.h;string.h;float.h" StandardHeadersExist)
if(StandardHeadersExist)
  check_prototype_exists(memchr string.h memchrExists)
  if(memchrExists)

    check_prototype_exists(free stdlib.h freeExists)
    if(freeExists)
      message(STATUS "ANSI C header files - found")
      set(STDC_HEADERS 1 CACHE INTERNAL "System has ANSI C header files")
      set(HAVE_STRINGS_H 1)
      set(HAVE_STRING_H 1)
      set(HAVE_FLOAT_H 1)
      set(HAVE_STDLIB_H 1)
      set(HAVE_STDDEF_H 1)
      set(HAVE_STDINT_H 1)
      set(HAVE_INTTYPES_H 1)
      set(HAVE_DLFCN_H 1)
    endif(freeExists)
  endif(memchrExists)
endif(StandardHeadersExist)

if(NOT STDC_HEADERS)
  message(STATUS "ANSI C header files - not found")
  set(STDC_HEADERS 0 CACHE INTERNAL "System has ANSI C header files")
endif(NOT STDC_HEADERS)

check_include_files(unistd.h HAVE_UNISTD_H)

include(CheckDIRSymbolExists)
check_dirsymbol_exists("sys/stat.h;sys/types.h;dirent.h" HAVE_DIRENT_H)
if (HAVE_DIRENT_H)
  set(HAVE_SYS_STAT_H 1)
  set(HAVE_SYS_TYPES_H 1)
endif (HAVE_DIRENT_H)

check_include_files("dlfcn.h;stdint.h;stddef.h;inttypes.h;stdlib.h;strings.h;string.h;float.h" StandardHeadersExist)
set(HAVE_LIBM 1)
