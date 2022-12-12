# Specify the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name and specify that it uses C++20
project(app LANGUAGES CXX C)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)

# Enable compiler sanitizers
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

# Add SDL2 and Vulkan as dependencies
find_package(SDL2 REQUIRED)
find_package(Vulkan REQUIRED)

# Add the source files for the project
file(GLOB_RECURSE SRCS "src/*.cpp")

# Add the project's executable target and specify its source files
add_executable(app ${SRCS})

# Link the project's executable target to SDL2 and Vulkan
target_link_libraries(app PRIVATE SDL2::SDL2 Vulkan::Vulkan)
