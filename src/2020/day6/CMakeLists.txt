add_executable(2020_day6 day6.c)
add_executable(2020_day6_part2 day6_part2.c)

target_link_libraries(2020_day6 PRIVATE set)
target_link_libraries(2020_day6_part2 PRIVATE set)

configure_file(2020_day6_smol.txt "${CMAKE_BINARY_DIR}/bin/2020_day6_smol.txt" COPYONLY)
configure_file(2020_day6.txt "${CMAKE_BINARY_DIR}/bin/2020_day6.txt" COPYONLY)
