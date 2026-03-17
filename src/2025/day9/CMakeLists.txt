add_executable(2025_day9 day9.c)

target_link_libraries(2025_day9 PRIVATE dynamic_array)

configure_file(day9_smol.txt "${CMAKE_CURRENT_BINARY_DIR}/day9_smol.txt" COPYONLY)
configure_file(day9.txt "${CMAKE_CURRENT_BINARY_DIR}/day9.txt" COPYONLY)
