cmake_minimum_required(VERSION 3.16)
project(blackjack LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "RelWithDebInfo" "MinSizeRel")
endif()

add_executable(blackjack
  src/main.cpp
  src/Game.cpp
  src/Deck.cpp
  src/Hand.cpp
  src/Cards.cpp
)

target_include_directories(blackjack PRIVATE ${CMAKE_SOURCE_DIR}/include)

if(MSVC)
  target_compile_options(blackjack PRIVATE /W4 /permissive- /EHsc)
else()
  target_compile_options(blackjack PRIVATE -Wall -Wextra -Wpedantic)
endif()

find_package(Threads REQUIRED)
target_link_libraries(blackjack PRIVATE Threads::Threads)
