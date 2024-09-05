cmake_minimum_required(VERSION 3.30)

set(CXX C:/Users/iielefth/scoop/apps/mingw-winlibs-llvm/current/bin/clang++.exe)
set(CC C:/Users/iielefth/scoop/apps/mingw-winlibs-llvm/current/bin/clang.exe)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(PROJECT_NAME VulkanTutorial)
set(SOURCE src/main.cpp)
project(${PROJECT_NAME})

set(CMAKE_MAKE_PROGRAM Ninja)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

link_directories("

# Vulkan installed with `scoop install vulkan`
find_package(Vulkan REQUIRED)


# VK-bootstrap (useful for not wasting time with arcane lookups)
include(FetchContent)
FetchContent_Declare(
    fetch_vk_bootstrap
    GIT_REPOSITORY https://github.com/charles-lunarg/vk-bootstrap
    GIT_TAG        v1.3.295
)
FetchContent_MakeAvailable(fetch_vk_bootstrap)

include(FetchContent)

FetchContent_Declare(
	glm
	GIT_REPOSITORY	https://github.com/g-truc/glm.git
	GIT_TAG 	bf71a834948186f4097caa076cd2663c69a10e1e #refs/tags/1.0.1
)
FetchContent_MakeAvailable(glm)

add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(${PROJECT_NAME} vulkan glfw vk-bootstrap::vk-bootstrap glm::glm)
