include(FetchContent)
FetchContent_Declare(
    doctest
    GIT_REPOSITORY https://github.com/doctest/doctest.git
)
FetchContent_MakeAvailable(doctest)

add_executable(xeyday.math.generator-test)

target_include_directories(xeyday.math.generator-test
    PRIVATE
    "${doctest_SOURCE_DIR}/doctest"
)

target_sources(xeyday.math.generator-test
    PRIVATE
    "entry_point.cpp"
)

add_custom_target(xeyday.math.generate-for-test
  COMMAND xeyday.math.generator-cli "--everything"
  WORKING_DIRECTORY ${XEYDAY_MATH_ROOT_DIR}
  COMMENT "generate xeyday.math in ${XEYDAY_MATH_ROOT_DIR} for testing"
  BYPRODUCTS "${XEYDAY_MATH_ROOT_DIR}/generated"
)

add_dependencies(xeyday.math.generator-test
    xeyday.math.generate-for-test
)

enable_testing()

include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)

doctest_discover_tests(xeyday.math.generator-test)
