set(lib_name ClientInfo)
xpGetExtern(externIncs externLibs PUBLIC boost wxWidgets)
include_directories(${externIncs} ${CMAKE_SOURCE_DIR})
set(Client_srcs
Player.cpp)
source_group(Client_Info FILES ${Client_srcs})
list(APPEND ${lib_name}_libsrcs ${Client_srcs})
add_library(${lib_name} STATIC ${${lib_name}_libsrcs})