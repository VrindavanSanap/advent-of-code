add_executable(2019_day2 day2.c)
add_executable(2019_day2_part2 day2_part2.c)
target_link_libraries(2019_day2 PRIVATE dynamic_array)
target_link_libraries(2019_day2_part2 PRIVATE dynamic_array)

configure_file(2019_day2_smol.txt "${CMAKE_BINARY_DIR}/bin/2019_day2_smol.txt" COPYONLY)
configure_file(2019_day2.txt "${CMAKE_BINARY_DIR}/bin/2019_day2.txt" COPYONLY)
