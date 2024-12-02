# Utility variables
set(SQLITE3_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(SQLITE3_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

add_library(SQLite3 STATIC)

target_sources(SQLite3 PRIVATE 
    ${SQLITE3_SOURCES}
    ${SQLITE3_HEADERS}
)

target_include_directories(SQLite3 PRIVATE 
    ${SQLITE3_HEADERS}
)

add_library(SQLite::SQLite3 ALIAS SQLite3)

# Define the CLI executable (sqlite3.exe)
add_executable(sqlite3_cli shell.c)
target_link_libraries(sqlite3_cli PRIVATE SQLite3)
target_include_directories(sqlite3_cli PRIVATE ${SQLITE3_HEADERS})

# Install the CLI executable to ensure PROJ can find it
install(TARGETS sqlite3_cli RUNTIME DESTINATION bin)

# Make the sqlite3 CLI available as a variable
set(SQLite3_EXECUTABLE $<TARGET_FILE:sqlite3_cli> CACHE FILEPATH "Path to sqlite3 executable")

# Set the variables so PROJ can find them
set(SQLite3_INCLUDE_DIR ${SQLITE3_HEADERS} CACHE PATH "Path to SQLite3 headers")
set(SQLite3_LIBRARY SQLite::SQLite3 CACHE STRING "SQLite3 library")



