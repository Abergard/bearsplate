add_library(bearsplate-core STATIC bearsplate.cpp)

if(ENABLE_TESTING)
  set(EXTERNAL_TEST_LIB "externals/googletest")
  add_subdirectory("${PROJECT_SOURCE_DIR}/${EXTERNAL_TEST_LIB}" ${EXTERNAL_TEST_LIB})

  add_executable(bearsplate-ut bearsplate-ut.cpp)
  target_link_libraries(bearsplate-ut PRIVATE bearsplate-core gmock_main)
  gtest_discover_tests(bearsplate-ut
    EXTRA_ARGS --gtest_color=yes
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
endif()


if(WIN32 AND NOT FORCE_BUILD_CONSOLE_APP)
  message(STATUS "WIN32 application")
  add_executable(bearsplate WIN32 main-win32.cpp)
else()
  message(STATUS "Console application")
  add_executable(bearsplate main.cpp)
endif()

target_link_libraries(bearsplate PRIVATE bearsplate-core)
