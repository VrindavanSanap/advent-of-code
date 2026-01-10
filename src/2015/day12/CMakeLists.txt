add_executable(day12 ./day12.c)

# cJSON is provided by FetchContent at the root level
if(TARGET cjson)
    target_link_libraries(day12 PRIVATE cjson)

    # Workaround to support #include <cjson/cJSON.h>
    # cJSON usually provides headers at root, so we create a mock directory structure in build.
    if(cjson_SOURCE_DIR)
        set(CJSON_MOCK_INCLUDE_DIR "${CMAKE_CURRENT_BINARY_DIR}/cjson_include")
        file(MAKE_DIRECTORY "${CJSON_MOCK_INCLUDE_DIR}/cjson")
        configure_file("${cjson_SOURCE_DIR}/cJSON.h" "${CJSON_MOCK_INCLUDE_DIR}/cjson/cJSON.h" COPYONLY)
        target_include_directories(day12 PRIVATE "${CJSON_MOCK_INCLUDE_DIR}")
    else()
        message(WARNING "cjson_SOURCE_DIR not defined. Compilation of day12 might fail if <cjson/cJSON.h> is required.")
    endif()

elseif(TARGET cJSON::cJSON)
    target_link_libraries(day12 PRIVATE cJSON::cJSON)
endif()

configure_file("./day12.json" "${CMAKE_CURRENT_BINARY_DIR}/day12.json" COPYONLY)
