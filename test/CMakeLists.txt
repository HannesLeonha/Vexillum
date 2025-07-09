set(TEST_FILES
    main.c
    Flag.c)

foreach(TEST_FILE ${TEST_FILES})
    # Setup
    string(REGEX REPLACE "\.[a-zA-Z]*$" "" FILE_NAME ${TEST_FILE})
    set(TEST_TARGET "${FILE_NAME}_TEST")

    # Build
    add_executable(${TEST_TARGET}
            ${TEST_FILE})
    target_link_libraries(${TEST_TARGET}
            PRIVATE TestVexillum)
    target_include_directories(${TEST_TARGET} PRIVATE ${PROJECT_SOURCE_DIR}/src)

    # Test
    add_test(NAME "${FILE_NAME} Test" COMMAND ${TEST_TARGET} "loose argument" -lhR --long-flag -d "flag argument")
endforeach()