add_executable(day13 ./day13.c)


# 2. Add your executable
target_link_libraries(day13 PRIVATE dynamic_array)
# 3. Link the library
# Note: The target name is usually 'cjson' (lowercase) or 'cJSON::cJSON'
file(COPY "./day13.txt" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
