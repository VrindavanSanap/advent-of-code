find_package(OpenSSL REQUIRED)

# Define your executable
add_executable(2016_day5_part2 day5_part2.c)

# Link OpenSSL's Crypto library to your executable
# OpenSSL::Crypto automatically handles include paths and linking
target_link_libraries(2016_day5_part2 OpenSSL::Crypto)