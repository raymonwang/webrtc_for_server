AUTOMAKE_OPTIONS = foreign

lib_LIBRARIES = libwebrtc_base.a

DEFS = -I../../ -I../../third_party/jsoncpp/source/include -I../../third_party/boringssl/src/include/

AM_CPPFLAGS = -DWEBRTC_POSIX -DWEBRTC_LINUX -DWEBRTC_BUILD_LIBEVENT -D__STDC_FORMAT_MACROS -DOPENSSL_IS_BORINGSSL
AM_CXXFLAGS = -std=gnu++11

libwebrtc_base_a_SOURCES = numerics/exp_filter.cc\
asynchttprequest.cc\
asyncinvoker.cc\
asyncpacketsocket.cc\
asyncresolverinterface.cc\
asyncsocket.cc\
asynctcpsocket.cc\
asyncudpsocket.cc\
autodetectproxy.cc\
base64.cc\
bitbuffer.cc\
bufferqueue.cc\
bytebuffer.cc\
checks.cc\
common.cc\
copyonwritebuffer.cc\
crc32.cc\
criticalsection.cc\
cryptstring.cc\
diskcache.cc\
event.cc\
event_tracer.cc\
fakeclock.cc\
file.cc\
file_posix.cc\
filerotatingstream.cc\
fileutils.cc\
firewallsocketserver.cc\
flags.cc\
helpers.cc\
httpbase.cc\
httpclient.cc\
httpcommon.cc\
httpserver.cc\
ifaddrs_converter.cc\
ipaddress.cc\
json.cc\
location.cc\
logging.cc\
logsinks.cc\
md5.cc\
md5digest.cc\
messagedigest.cc\
messagehandler.cc\
messagequeue.cc\
natserver.cc\
natsocketfactory.cc\
nattypes.cc\
nethelpers.cc\
network.cc\
networkmonitor.cc\
nullsocketserver.cc\
openssladapter.cc\
openssldigest.cc\
opensslidentity.cc\
opensslstreamadapter.cc\
optional.cc\
optionsfile.cc\
pathutils.cc\
physicalsocketserver.cc\
platform_file.cc\
platform_thread.cc\
proxydetect.cc\
proxyinfo.cc\
proxyserver.cc\
race_checker.cc\
random.cc\
rate_limiter.cc\
rate_statistics.cc\
ratelimiter.cc\
ratetracker.cc\
rtccertificate.cc\
rtccertificategenerator.cc\
sequenced_task_checker_impl.cc\
sha1.cc\
sha1digest.cc\
sharedexclusivelock.cc\
signalthread.cc\
sigslot.cc\
socketadapters.cc\
socketaddress.cc\
socketaddresspair.cc\
socketpool.cc\
socketstream.cc\
ssladapter.cc\
sslfingerprint.cc\
sslidentity.cc\
sslsocketfactory.cc\
sslstreamadapter.cc\
stream.cc\
stringencode.cc\
stringutils.cc\
task.cc\
task_queue_libevent.cc\
task_queue_posix.cc\
taskparent.cc\
taskrunner.cc\
testclient.cc\
thread.cc\
thread_checker_impl.cc\
timestampaligner.cc\
timeutils.cc\
transformadapter.cc\
unixfilesystem.cc\
virtualsocketserver.cc\
weak_ptr.cc 

libwebrtc_base_a_SOURCES += ../common_types.cc ../config.cc
