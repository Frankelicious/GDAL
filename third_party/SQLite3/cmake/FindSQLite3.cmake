# FindSQLite3.cmake
if (NOT TARGET SQLite::SQLite3)
    set(SQLite3_FOUND TRUE)
    set(SQLite3_INCLUDE_DIR ${SQLite3_INCLUDE_DIRS})
    set(SQLite3_LIBRARY ${SQLite3_LIBRARIES})
endif ()
