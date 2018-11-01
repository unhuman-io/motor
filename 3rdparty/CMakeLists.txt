#file(DOWNLOAD "https://raw.githubusercontent.com/muflihun/easyloggingpp/v9.96.5/src/easylogging%2B%2B.h" ${CMAKE_CURRENT_BINARY_DIR}/easylogging/easylogging++.h EXPECTED_MD5 10655cd1aabb3df9787dc63754636729)
#file(DOWNLOAD "https://raw.githubusercontent.com/muflihun/easyloggingpp/v9.96.5/src/easylogging%2B%2B.cc" ${CMAKE_CURRENT_BINARY_DIR}/easylogging/easylogging++.cc EXPECTED_MD5 a8782ba880a51e34b69b93300c567099)

add_library(easylogging INTERFACE) #easylogging/easylogging++.cc
       # easylogging/easylogging++.h)
target_include_directories(easylogging INTERFACE ${CMAKE_BINARY_DIR}/3rdparty/easylogging)
