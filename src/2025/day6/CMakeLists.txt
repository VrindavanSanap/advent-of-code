add_executable(2025_day6 day6.c)
add_executable(2025_day6_part2 day6_part2.c)

target_link_libraries(2025_day6 PRIVATE dynamic_array)
target_link_libraries(2025_day6_part2 PRIVATE dynamic_array)

configure_file(2025_day6_smol.txt "${CMAKE_BINARY_DIR}/bin/2025_day6_smol.txt" COPYONLY)
configure_file(2025_day6.txt "${CMAKE_BINARY_DIR}/bin/2025_day6.txt" COPYONLY)
