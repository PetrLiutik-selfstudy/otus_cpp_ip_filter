cmake_minimum_required(VERSION 3.2)

project(ip_filter VERSION 1.1.$ENV{TRAVIS_BUILD_NUMBER})

configure_file(version.h.in version.h)

# Setup application
add_executable(${PROJECT_NAME} main.cpp)

add_library(ver_lib ver.cpp)
add_library(ip_filter_lib ip_filter.cpp)


set_target_properties(
        ${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

target_link_libraries(${PROJECT_NAME} ver_lib)
target_link_libraries(${PROJECT_NAME} ip_filter_lib)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)


set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT petr_lutik@mail.ru)

include (CPack)

