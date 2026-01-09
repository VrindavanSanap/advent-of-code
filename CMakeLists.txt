cmake_minimum_required(VERSION 3.14)
project(MyCProject)

include(FetchContent)

FetchContent_Declare(
  cjson
  GIT_REPOSITORY https://github.com/DaveGamble/cJSON.git
  GIT_TAG v1.7.17
)
FetchContent_MakeAvailable(cjson)

# cJSON 1.7.17 does not export include directories for the target when used via add_subdirectory
# We explicitly add the source directory to the target's include directories.
# We use BUILD_INTERFACE to avoid export issues.
if(TARGET cjson)
    target_include_directories(cjson PUBLIC $<BUILD_INTERFACE:${cjson_SOURCE_DIR}>)
endif()

# Add the library directory first so it is available to apps
add_subdirectory(libs)

# Add your application directories
add_subdirectory(src)
