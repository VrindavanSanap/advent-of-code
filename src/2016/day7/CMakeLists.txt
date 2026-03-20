add_executable(2016_day7 day7.c)
target_link_libraries(2016_day7 PRIVATE dynamic_array)

add_executable(2016_day7_part2 day7_part2.c)
target_link_libraries(2016_day7_part2 PRIVATE dynamic_array)

configure_file(2016_day7.txt "${CMAKE_BINARY_DIR}/bin/2016_day7.txt" COPYONLY)
