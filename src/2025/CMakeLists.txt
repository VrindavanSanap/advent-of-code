add_executable(day5 ./day5/day5.c)
add_executable(day5_part2 ./day5/day5_part2.c)

# Link the shared library. 
# CMake automatically adds the include path from step (2).
target_link_libraries(day5 PRIVATE dynamic_array)
target_link_libraries(day5_part2 PRIVATE dynamic_array)


configure_file("./day5/day5_smol.txt" "${CMAKE_CURRENT_BINARY_DIR}/day5_smol.txt" COPYONLY)
configure_file("./day5/day5.txt" "${CMAKE_CURRENT_BINARY_DIR}/day5.txt" COPYONLY)

add_executable(day6 ./day6/day6.c)
add_executable(day6_part2 ./day6/day6_part2.c)

target_link_libraries(day6 PRIVATE dynamic_array)
target_link_libraries(day6_part2 PRIVATE dynamic_array)

configure_file("./day6/day6_smol.txt" "${CMAKE_CURRENT_BINARY_DIR}/day6_smol.txt" COPYONLY)
configure_file("./day6/day6.txt" "${CMAKE_CURRENT_BINARY_DIR}/day6.txt" COPYONLY)

add_executable(day7 ./day7/day7.c)
add_executable(day7_part2 ./day7/day7_part2.c)

target_link_libraries(day7 PRIVATE dynamic_array)
target_link_libraries(day7_part2 PRIVATE dynamic_array)

configure_file("./day7/day7_smol.txt" "${CMAKE_CURRENT_BINARY_DIR}/day7_smol.txt" COPYONLY)
configure_file("./day7/day7.txt" "${CMAKE_CURRENT_BINARY_DIR}/day7.txt" COPYONLY)

add_executable(day9 ./day9/day9.c)
# day9_part2 does not exist
# add_executable(day9_part2 ./day9/day9_part2.c)

target_link_libraries(day9 PRIVATE dynamic_array)
# target_link_libraries(day9_part2 PRIVATE dynamic_array)

configure_file("./day9/day9_smol.txt" "${CMAKE_CURRENT_BINARY_DIR}/day9_smol.txt" COPYONLY)
configure_file("./day9/day9.txt" "${CMAKE_CURRENT_BINARY_DIR}/day9.txt" COPYONLY)
