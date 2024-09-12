include(FetchContent)
FetchContent_Declare(cmake_git_version_tracking
    GIT_REPOSITORY https://github.com/andrew-hardin/cmake-git-version-tracking.git
)
FetchContent_MakeAvailable(cmake_git_version_tracking)

add_library(xeyday.math.generator STATIC)

target_link_libraries(xeyday.math.generator
    PRIVATE
    cmake_git_version_tracking
)

target_include_directories(xeyday.math.generator
    PUBLIC
    "${XEYDAY_MATH_DEPENDENCIES_INCLUDE_DIR}"
)

target_sources(xeyday.math.generator
    PRIVATE
    "generator.cpp"
    "generator.hpp"
)
