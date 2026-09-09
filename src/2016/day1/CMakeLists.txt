add_executable(2016_day1_part2 ./day1_part2.c)
target_link_libraries(2016_day1_part2 PRIVATE set)

configure_file("./2016_day1.txt" "${CMAKE_BINARY_DIR}/bin/2016_day1.txt" COPYONLY)
configure_file("./2016_day1_smol.txt" "${CMAKE_BINARY_DIR}/bin/2016_day1_smol.txt" COPYONLY)
