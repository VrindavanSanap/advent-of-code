add_executable(2015_day6 ./day6.cc)

target_link_libraries(2015_day6 PRIVATE ${TORCH_LIBRARIES})
target_include_directories(2015_day6 PRIVATE ${TORCH_INCLUDE_DIRS})
target_compile_options(2015_day6 PRIVATE ${TORCH_CXX_FLAGS})

add_executable(2015_day6_part2 ./day6_part2.cc)

target_link_libraries(2015_day6_part2 PRIVATE ${TORCH_LIBRARIES})
target_include_directories(2015_day6_part2 PRIVATE ${TORCH_INCLUDE_DIRS})
target_compile_options(2015_day6_part2 PRIVATE ${TORCH_CXX_FLAGS})

configure_file("./2015_day6.txt" "${CMAKE_BINARY_DIR}/bin/2015_day6.txt" COPYONLY)
