set(lib_name GUI)
xpGetExtern(externIncs externLibs PUBLIC boost wxWidgets)
include_directories(${externIncs} ${CMAKE_SOURCE_DIR})
add_executable(client
GUI.cpp
CreateAccount.hpp
CreateAccount.cpp
GameOver.hpp
GameOver.cpp
HeartsBoard.hpp
HeartsBoard.cpp
LoginScreen.hpp
LoginScreen.cpp
PlayModeScreen.hpp
PlayModeScreen.cpp
SpadesBoard.hpp
SpadesBoard.cpp
)
target_link_libraries(client ${externLibs})
target_include_directories(client ${externIncs})