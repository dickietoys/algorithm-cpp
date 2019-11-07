file (GLOB ALGO_SRCS "*.cc")
file (GLOB ALGO_HEADERS "*.h")

# set(SRC_FILES ${SRC_FILES} ${CURRENT_SRC_FILES} PARENT_SCOPE)
# set(HEADER_FILES ${HEADER_FILES} ${CURRENT_HEADER_FILES} PARENT_SCOPE)

add_library(greedy ${ALGO_SRCS})
target_link_libraries(greedy pthread)

# install(TARGETS algorithm_sort DESTINATION lib)
