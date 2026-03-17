add_executable(2025_day11 day11.c)

target_link_libraries(2025_day11 PRIVATE dynamic_array)

configure_file(day11_smol.txt "${CMAKE_CURRENT_BINARY_DIR}/day11_smol.txt" COPYONLY)
configure_file(day11.txt "${CMAKE_CURRENT_BINARY_DIR}/day11.txt" COPYONLY)
