set(lib_name Networking)
xpGetExtern(externIncs externLibs PUBLIC boost)
include_directories(${externIncs} ${CMAKE_SOURCE_DIR})
add_library(${lib_name}
ClientNetworkInterface.cpp
ClientNetworkInterface.hpp
GeneralMessage.cpp
GeneralMessage.hpp
NetworkInterface.cpp
NetworkInterface.hpp
TCPConnection.cpp
TCPConnection.hpp
)
link_libraries(${externLibs})