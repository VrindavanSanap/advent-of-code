add_executable(2020_day6 day6.c)
add_executable(2020_day6_part2 day6_part2.c)

# target_link_libraries(2020_day6 PRIVATE ...)
# target_link_libraries(2020_day6_part2 PRIVATE ...)

configure_file(day6_smol.txt "${CMAKE_CURRENT_BINARY_DIR}/day6_smol.txt" COPYONLY)
configure_file(day6.txt "${CMAKE_CURRENT_BINARY_DIR}/day6.txt" COPYONLY)
