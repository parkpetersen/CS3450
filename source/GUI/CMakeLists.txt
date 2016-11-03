set(lib_name GUI)
xpGetExtern(externIncs externLibs PUBLIC boost wxWidgets)
include_directories(${externIncs} ${CMAKE_SOURCE_DIR})
add_executable(client
GUI.cpp gameOver.h gameOver.cpp
)
target_link_libraries(client ${externLibs})
target_include_directories(client ${externIncs})