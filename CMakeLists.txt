cmake_minimum_required(VERSION 3.22)
project(KeenCPPTest_all)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

include_directories(/*)

add_executable(getTime utils/timeUtils/getTime.cpp)
set_target_properties(getTime PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/utils/timeUtils/")