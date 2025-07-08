# Flag Tester
add_executable(FlagTester
        main.c)

target_link_libraries(FlagTester
        PRIVATE Vexillum)
target_include_directories(FlagTester PRIVATE ${PROJECT_SOURCE_DIR}/src)

set_target_properties(FlagTester
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/src"
)

# Tests
add_test(NAME Flag COMMAND FlagTester "loose argument" -lhR --long-flag -d "flag argument")