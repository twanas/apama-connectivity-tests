cmake_minimum_required(VERSION 3.16)

project(apama_connectivity_tests)

include_directories(/usr/local/include)

set(CMAKE_CXX_STANDARD 11)

if(DEFINED APAMA_HOME)
    message("APAMA_HOME found : $ENV{APAMA_HOME}, building apama plugin")
    set(APAMA_INCLUDE_DIRS "${APAMA_HOME}/include")
    set(APAMA_LIBRARIES "${APAMA_HOME}/lib/libapclient.so")
    include_directories(${APAMA_INCLUDE_DIRS})
endif()

add_subdirectory(src)
