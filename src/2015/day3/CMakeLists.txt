add_executable(2015_day3 ./day3.c)
target_link_libraries(2015_day3 PRIVATE set)

configure_file("./2015_day3.txt" "${CMAKE_BINARY_DIR}/bin/2015_day3.txt" COPYONLY)
