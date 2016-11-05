set(lib_name GUI)
xpGetExtern(externIncs externLibs PUBLIC boost wxWidgets)
include_directories(${externIncs} ${CMAKE_SOURCE_DIR})
add_executable(client
CreateAccount.cpp
CreateAccount.hpp
GameOver.hpp
GameOver.cpp
GUI.cpp
LoginScreen.cpp
LoginScreen.hpp
PlayModeScreen.cpp
PlayModeScreen.hpp
)
target_link_libraries(client ${externLibs})
target_include_directories(client ${externIncs})