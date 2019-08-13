cmake_minimum_required(VERSION 3.11.0)
project(SimpleBench)

add_library(${CMAKE_PROJECT_NAME} SHARED
	src/${CMAKE_PROJECT_NAME}/timekeeper.cpp
	src/${CMAKE_PROJECT_NAME}/benchmarkcase.cpp
	src/${CMAKE_PROJECT_NAME}/benchmark.cpp)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC include/${CMAKE_PROJECT_NAME})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER include/${CMAKE_PROJECT_NAME}/benchmark.h)

add_executable(bench src/main.cpp src/montecarlopi.cpp)
target_include_directories(bench PUBLIC include)
target_link_libraries(bench PUBLIC ${PROJECT_NAME})
