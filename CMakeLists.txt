cmake_minimum_required(VERSION 3.7)

project(jeromemarfleet-personal-api)

set(CMAKE_CXX_STANDARD 11)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Boost COMPONENTS system filesystem REQUIRED)
find_package(Threads REQUIRED)
find_package(libmongocxx REQUIRED)

add_executable(personal_api main.cpp)
target_include_directories(personal_api PRIVATE ${Boost_INCLUDE_DIRS}
${LIBMONGOCXX_INCLUDE_DIRS})
target_link_libraries(personal_api ${Boost_LIBRARIES} Threads::Threads
${LIBMONGOCXX_LIBRARIES})