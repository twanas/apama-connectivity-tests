add_library(numeric_limits SHARED numeric_limit_plugin.cpp)
target_link_libraries(numeric_limits ${APAMA_LIBRARIES})
