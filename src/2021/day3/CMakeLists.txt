add_executable(2021_day3 day3.c)
add_executable(2021_day3_part2 day3_part2.c)
target_link_libraries(2021_day3 PRIVATE dynamic_array)
target_link_libraries(2021_day3_part2 PRIVATE dynamic_array)

configure_file(day3.txt day3.txt COPYONLY)
configure_file(day3_smol.txt day3_smol.txt COPYONLY)