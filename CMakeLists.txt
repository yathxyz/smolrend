cmake_minimum_required(VERSION 3.30)

set(CXX C:/Users/iielefth/scoop/apps/mingw-winlibs-llvm/current/bin/clang++.exe)
set(CC C:/Users/iielefth/scoop/apps/mingw-winlibs-llvm/current/bin/clang.exe)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(GLFW_LIB_DIR C:/Users/iielefth/scoop/apps/glfw/current/lib-vc2022/glfw3_mt.lib)
set(GLFW_INCLUDE_DIR C:/Users/iielefth/scoop/apps/glfw/current/include)

set(PROJECT_NAME VulkanTutorial)
set(SOURCE src/main.cpp)

project(${PROJECT_NAME})

set(CMAKE_MAKE_PROGRAM Ninja)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

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

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.4
)
FetchContent_MakeAvailable(glfw)

add_executable(${PROJECT_NAME} ${SOURCE})

target_include_directories(${PROJECT_NAME} PUBLIC ${GLFW_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan vk-bootstrap::vk-bootstrap glm::glm glfw)
