add_executable(2021_day3 day3.c)
add_executable(2021_day3_part2 day3_part2.c)
target_link_libraries(2021_day3 PRIVATE dynamic_array)
target_link_libraries(2021_day3_part2 PRIVATE dynamic_array)

configure_file(2021_day3.txt "${CMAKE_BINARY_DIR}/bin/2021_day3.txt" COPYONLY)
configure_file(2021_day3_smol.txt "${CMAKE_BINARY_DIR}/bin/2021_day3_smol.txt" COPYONLY)