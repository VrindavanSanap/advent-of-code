# Create the library from the source file
add_library(set set.c)

# Define the include directories
# PUBLIC = accessible to both the library itself AND anyone who links to it
target_include_directories(set PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_link_libraries(set PUBLIC dynamic_array)