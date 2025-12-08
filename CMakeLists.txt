project(troll_text CXX)
cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

include_directories(/src)

file(GLOB SOURCES
    src/*.cpp
)

add_executable(troll_text ${SOURCES})


target_link_options(troll_text PRIVATE -static -static-libgcc -static-libstdc++)

file(COPY "${CMAKE_SOURCE_DIR}/example.txt" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

