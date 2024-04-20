set(TARGET_NAME example.library.lib)

add_library(${TARGET_NAME} 
  src/CCalculator.cpp
  src/CPythagoras.cpp
)

target_link_libraries(${TARGET_NAME} PUBLIC 
  
)

target_include_directories(${TARGET_NAME} PUBLIC 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/inc>
)

add_sanitizers(${TARGET_NAME})

# ---------------------------------------------------------

if(BUILD_TESTS)
  set(TEST_TARGET_NAME ${TARGET_NAME}.test)

  add_executable(${TEST_TARGET_NAME}
    tst/CCalculatorMock.cpp
    tst/CCalculatorTest.cpp
    tst/CPythagorasTest.cpp
    tst/main.cpp
  )

  add_sanitizers(${TEST_TARGET_NAME})

  target_link_libraries(${TEST_TARGET_NAME} PRIVATE
    ${TARGET_NAME}
    GTest::gtest_main
    GTest::gmock_main
  )

  gtest_discover_tests(${TEST_TARGET_NAME}
    XML_OUTPUT_DIR "${CMAKE_BINARY_DIR}/test_results"
  )
endif()
