add_executable(2025_day9 day9.c)

target_link_libraries(2025_day9 PRIVATE dynamic_array)

configure_file(2025_day9_smol.txt "${CMAKE_BINARY_DIR}/bin/2025_day9_smol.txt" COPYONLY)
configure_file(2025_day9.txt "${CMAKE_BINARY_DIR}/bin/2025_day9.txt" COPYONLY)
