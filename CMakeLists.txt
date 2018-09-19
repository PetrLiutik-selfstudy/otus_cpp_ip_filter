cmake_minimum_required(VERSION 3.2)

if (DEFINED ENV{TRAVIS_BUILD_NUMBER})
    project(ip_filter VERSION 1.1.$ENV{TRAVIS_BUILD_NUMBER})
else ()
    project(ip_filter VERSION 1.1.1)
endif ()

configure_file(version.h.in ${PROJECT_SOURCE_DIR}/version.h)

# Setup application
add_executable(${PROJECT_NAME} main.cpp)

add_library(ver_lib ver.cpp)
add_library(ip_filter_lib ip_filter.cpp)

set_target_properties(${PROJECT_NAME} ver_lib ip_filter_lib PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

target_link_libraries(${PROJECT_NAME} ver_lib)
target_link_libraries(${PROJECT_NAME} ip_filter_lib)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

# Setup testing
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

add_executable(test_${PROJECT_NAME} test_ip_filter.cpp)
target_link_libraries(test_${PROJECT_NAME} ${GTEST_BOTH_LIBRARIES} ver_lib pthread)
target_link_libraries(test_${PROJECT_NAME} ${GTEST_BOTH_LIBRARIES} ip_filter_lib pthread)

set_target_properties(test_${PROJECT_NAME} PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

set_target_properties(test_${PROJECT_NAME} PROPERTIES
  INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIRS}
)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_CONTACT petr_lutik@mail.ru)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

include (CPack)

add_test(ver_test_case test_${PROJECT_NAME})
add_test(ip_filter_test_case test_${PROJECT_NAME})
