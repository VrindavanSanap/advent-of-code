# Create the library from the source file
add_library(dynamic_array dynamic_array.c)

# Define the include directories
# PUBLIC = accessible to both the library itself AND anyone who links to it
target_include_directories(dynamic_array PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)