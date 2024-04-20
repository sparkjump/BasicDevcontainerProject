set(TARGET_NAME example.executable.app)

add_executable(${TARGET_NAME}
  src/CFileTemplate.cpp
  src/main.cpp
)

target_link_libraries(${TARGET_NAME} PRIVATE
  example.library.lib
)

target_include_directories(${TARGET_NAME} PUBLIC 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/inc>
)

add_sanitizers(${TARGET_NAME})
