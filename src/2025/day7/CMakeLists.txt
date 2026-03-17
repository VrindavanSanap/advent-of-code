add_executable(2025_day7 day7.c)
add_executable(2025_day7_part2 day7_part2.c)

target_link_libraries(2025_day7 PRIVATE dynamic_array)
target_link_libraries(2025_day7_part2 PRIVATE dynamic_array)

configure_file(day7_smol.txt "${CMAKE_CURRENT_BINARY_DIR}/day7_smol.txt" COPYONLY)
configure_file(day7.txt "${CMAKE_CURRENT_BINARY_DIR}/day7.txt" COPYONLY)
