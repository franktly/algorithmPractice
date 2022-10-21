SET(SRC_LIST main.cpp)
MESSAGE(STAUTS  "this is a binary dir: ", ${NUMBERIC_BINARY_DIR})
MESSAGE(STAUTS  "this is a source dir: ", ${NUMBERIC_SOURCE_DIR})
ADD_EXECUTABLE(numberic ${SRC_LIST})
# TARGET_LINK_LIBRARIES(numberic pthread)

