file(GLOB_RECURSE _headers ${CMAKE_CURRENT_LIST_DIR}/*.h  CONFIGURE_DEPEND)
target_sources(${TARGET_NAME} PRIVATE ${_headers})
unset(_headers)

target_include_directories(${TARGET_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})