add_executable(2015_day12 ./day12.c)

# Link against cJSON — prefer the namespaced target (system/find_package),
# fall back to the fetched target (FetchContent).
if(TARGET cJSON::cJSON)
    target_link_libraries(2015_day12 PRIVATE cJSON::cJSON)
elseif(TARGET cjson)
    target_link_libraries(2015_day12 PRIVATE cjson)
endif()

configure_file("./day12.json" "${CMAKE_BINARY_DIR}/bin/2015_day12.json" COPYONLY)
