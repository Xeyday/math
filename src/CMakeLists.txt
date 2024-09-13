add_subdirectory(generator)

include(FetchContent)
FetchContent_Declare(
    argparse
    GIT_REPOSITORY https://github.com/p-ranav/argparse.git
)
FetchContent_MakeAvailable(argparse)

add_executable(xeyday.math.generator-cli)

target_sources(xeyday.math.generator-cli
    PRIVATE
    "entry_point.cpp"
)

target_link_libraries(xeyday.math.generator-cli
    PRIVATE
    argparse
    xeyday.math.generator
)
