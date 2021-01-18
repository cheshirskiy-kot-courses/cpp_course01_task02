cmake_minimum_required(VERSION 3.12)

project(task02 VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

set(CMAKE_PREFIX_PATH_EXT "" CACHE PATH "pathes for find_package")
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH_EXT})
set(Boost_USE_STATIC_LIBS OFF)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.h.in ${PROJECT_SOURCE_DIR}/version.h)

add_executable(ip_filter "ip_filter.cpp")

add_library(ip_filter_lib "lib.cpp")

add_executable(test_ip_filter "test_ip_filter.cpp")

set_target_properties(
	ip_filter ip_filter_lib PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

set_target_properties(
	test_ip_filter PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(
    ip_filter
    ip_filter_lib
)

target_link_libraries(
	test_ip_filter
    ${Boost_LIBRARIES}
    ip_filter_lib
)

enable_testing()

add_test(ip_filter_tests test_ip_filter)

install(TARGETS ip_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT cheshirskiy-kot-courses@yandex.com)

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)
