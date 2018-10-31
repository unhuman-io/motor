add_library(messages INTERFACE)
target_include_directories(messages INTERFACE .)
install(FILES messages.h DESTINATION sdk/c/include)
install(FILES messages.h DESTINATION sdk/cpp/include)