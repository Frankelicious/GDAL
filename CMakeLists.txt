cmake_minimum_required(VERSION 3.20)

project(MyProject LANGUAGES C CXX)

set(MY_PROJECT_NAME MyGDALProject)
set(THIRD_PARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(BUILD_SHARED_LIBS OFF)
set(ENABLE_TIFF OFF)
set(ENABLE_CURL OFF)
set(SOURCES
    ${SOURCE_DIR}/main.cpp)

set(HEADERS)

add_executable(${MY_PROJECT_NAME})

target_sources(${MY_PROJECT_NAME} PRIVATE
    ${SOURCES}
)

add_subdirectory(${THIRD_PARTY_DIR}/SQLite3)
add_subdirectory(${THIRD_PARTY_DIR}/curl)
add_subdirectory(${THIRD_PARTY_DIR}/libtiff)
add_subdirectory(${THIRD_PARTY_DIR}/proj)
add_subdirectory(${THIRD_PARTY_DIR}/gdal)