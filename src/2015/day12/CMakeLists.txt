add_executable(day12 ./day12.c)

# cJSON is provided by FetchContent at the root level
if(TARGET cjson)
    target_link_libraries(day12 PRIVATE cjson)
elseif(TARGET cJSON::cJSON)
    target_link_libraries(day12 PRIVATE cJSON::cJSON)
endif()

configure_file("./day12.json" "${CMAKE_CURRENT_BINARY_DIR}/day12.json" COPYONLY)
