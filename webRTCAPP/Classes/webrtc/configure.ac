#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([webrtcapp], [1.0], [BUG-REPORT-ADDRESS])
AM_INIT_AUTOMAKE(webrtcapp, 1.0)
AC_CONFIG_SRCDIR([typedefs.h])
AC_CONFIG_HEADERS([autoconfig.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_AWK

# Checks for libraries.

# Checks for header files.
AC_PATH_X
AC_FUNC_ALLOCA
AC_CHECK_HEADERS([arpa/inet.h fcntl.h float.h inttypes.h limits.h mach/mach.h malloc.h memory.h netdb.h netinet/in.h stddef.h stdint.h stdlib.h string.h strings.h sys/file.h sys/ioctl.h sys/socket.h sys/statfs.h sys/statvfs.h sys/time.h sys/timeb.h unistd.h wchar.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_INT8_T
AC_TYPE_MODE_T
AC_TYPE_OFF_T
AC_TYPE_PID_T
AC_C_RESTRICT
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE
AC_FUNC_FORK
AC_FUNC_MALLOC
AC_FUNC_MKTIME
AC_FUNC_MMAP
AC_FUNC_REALLOC
AC_FUNC_STRTOD
AC_CHECK_FUNCS([alarm atexit clock_gettime floor gethostbyname gethostname gettimeofday localtime_r memmove memset mkdir munmap pow realpath rmdir select socket sqrt strcasecmp strchr strdup strerror strncasecmp strrchr strspn strstr strtol strtoul uname])

AC_PROG_RANLIB
AC_CONFIG_FILES([Makefile
                 api/Makefile
                 audio/Makefile
                 base/Makefile
                 call/Makefile
                 common_audio/Makefile
                 common_video/Makefile
                 logging/Makefile
                 media/Makefile
                 modules/audio_coding/acm2/Makefile
                 modules/audio_coding/audio_network_adaptor/Makefile
                 modules/audio_coding/codecs/Makefile
                 modules/audio_coding/codecs/cng/Makefile
                 modules/audio_coding/codecs/g711/Makefile
                 modules/audio_coding/codecs/g722/Makefile
                 modules/audio_coding/codecs/ilbc/Makefile
                 modules/audio_coding/codecs/isac/Makefile
                 modules/audio_coding/codecs/isac/main/Makefile
                 modules/audio_coding/codecs/isac/fix/Makefile
                 modules/audio_coding/codecs/opus/Makefile
                 modules/audio_coding/codecs/pcm16b/Makefile
                 modules/audio_coding/neteq/Makefile
                 modules/audio_conference_mixer/Makefile
                 modules/audio_device/Makefile
                 modules/audio_mixer/Makefile
                 modules/audio_processing/Makefile
                 modules/bitrate_controller/Makefile
                 modules/congestion_controller/Makefile
                 modules/media_file/Makefile
                 modules/pacing/Makefile
                 modules/remote_bitrate_estimator/Makefile
                 modules/rtp_rtcp/Makefile
                 modules/utility/Makefile
                 modules/video_capture/Makefile
                 modules/video_coding/Makefile
                 modules/video_coding/codecs/h264/Makefile
                 modules/video_coding/codecs/i420/Makefile
                 modules/video_coding/codecs/vp8/Makefile
                 modules/video_coding/codecs/vp9/Makefile
                 modules/video_processing/Makefile
                 system_wrappers/Makefile
                 video/Makefile
                 p2p/Makefile
                 pc/Makefile
                 voice_engine/Makefile])
AC_OUTPUT
