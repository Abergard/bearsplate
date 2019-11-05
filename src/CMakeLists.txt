add_library(bearsplate-core STATIC bearsplate.cpp)
add_executable(bearsplate-ut bearsplate-ut.cpp)
target_link_libraries(bearsplate-ut PRIVATE bearsplate-core gmock_main)
add_test(
  NAME bearsplate-ut
  COMMAND ${EXECUTABLE_OUTPUT_PATH}/bearsplate-ut --gtest_color=yes
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  )

if(WIN32 AND NOT FORCE_BUILD_CONSOLE_APP)
  message(STATUS "WIN32 application")
  add_executable(bearsplate WIN32 main-win32.cpp)
else()
  message(STATUS "Console application")
  add_executable(bearsplate main.cpp)
endif()

target_link_libraries(bearsplate PRIVATE bearsplate-core)
