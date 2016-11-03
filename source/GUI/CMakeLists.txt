set(lib_name GUI)
xpGetExtern(externIncs externLibs PUBLIC boost wxWidgets)
include_directories(${externIncs} ${CMAKE_SOURCE_DIR})
add_executable(client
CreateAccount.cpp
CreateAccount.h
GameOver.h
GameOver.cpp
GUI.cpp
LoginScreen.cpp
LoginScreen.h
PlayModeScreen.cpp
PlayModeScreen.h
)
target_link_libraries(client ${externLibs})
target_include_directories(client ${externIncs})