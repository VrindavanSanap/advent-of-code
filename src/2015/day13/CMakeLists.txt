add_executable(day13 ./day13.c)


# 2. Add your executable
target_link_libraries(day13 PRIVATE dynamic_array)
# 3. Link the library
# Note: The target name is usually 'cjson' (lowercase) or 'cJSON::cJSON'
configure_file("./day13.txt" "${CMAKE_CURRENT_BINARY_DIR}/day13.txt" COPYONLY)
