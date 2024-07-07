cmake_minimum_required(VERSION 3.3.0)
project(Fasta VERSION 0.1.0 LANGUAGES C CXX)

#Set standard for C++
message(STATUS "Requiring C++ Standard 20")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

#Start building the library
message(STATUS "Building the library")
include(CTest)
enable_testing()
file(GLOB_RECURSE LIB_FILES lib/*.cpp)
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include/")
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

#Building executable
message(STATUS "Building the executable")
add_executable(fasta "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp" ${LIB_FILES})
message(STATUS "Linking the library to the executable")

#Debugging. Uncomment following line to debug:
#set_target_properties(fasta PROPERTIES VS_DEBUGGER_COMMAND_ARGUMENTS "test.fasta") 