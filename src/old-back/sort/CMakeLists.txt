file (GLOB ALGORITHM_SRCS "*.cc")
file (GLOB ALGORITHM_HEADERS "*.h")

# set(SRC_FILES ${SRC_FILES} ${CURRENT_SRC_FILES} PARENT_SCOPE)
# set(HEADER_FILES ${HEADER_FILES} ${CURRENT_HEADER_FILES} PARENT_SCOPE)

add_library(algorithm ${ALGORITHM_SRCS})
target_link_libraries(algorithm pthread)

# install(TARGETS algorithm_sort DESTINATION lib)
