add_executable(2025_day5 day5.c)
add_executable(2025_day5_part2 day5_part2.c)

target_link_libraries(2025_day5 PRIVATE dynamic_array)
target_link_libraries(2025_day5_part2 PRIVATE dynamic_array)

configure_file(day5_smol.txt "${CMAKE_BINARY_DIR}/bin/2025_day5_smol.txt" COPYONLY)
configure_file(day5.txt "${CMAKE_BINARY_DIR}/bin/2025_day5.txt" COPYONLY)
