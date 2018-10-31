file(DOWNLOAD "https://github.com/muflihun/easyloggingpp/raw/master/src/easylogging++.h" ${CMAKE_CURRENT_BINARY_DIR}/easylogging/easylogging++.h EXPECTED_MD5 10655cd1aabb3df9787dc63754636729)
file(DOWNLOAD "https://github.com/muflihun/easyloggingpp/raw/master/src/easylogging++.cc" ${CMAKE_CURRENT_BINARY_DIR}/easylogging/easylogging++.cc EXPECTED_MD5 a8782ba880a51e34b69b93300c567099)

add_library(easylogging easylogging/easylogging++.cc easylogging/easylogging++.h)
target_include_directories(easylogging INTERFACE ${CMAKE_BINARY_DIR}/3rdparty/easylogging)
