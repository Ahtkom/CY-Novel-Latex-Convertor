file(GLOB_RECURSE _sources ${CMAKE_CURRENT_LIST_DIR}/*.cc  CONFIGURE_DEPEND)
target_sources(${TARGET_NAME} PRIVATE ${_sources})
unset(_sources)