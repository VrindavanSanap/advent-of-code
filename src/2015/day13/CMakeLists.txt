add_executable(2015_day13 ./day13.c)
target_link_libraries(2015_day13 PRIVATE dynamic_array)

configure_file("./day13.txt" "${CMAKE_BINARY_DIR}/bin/2015_day13.txt" COPYONLY)
