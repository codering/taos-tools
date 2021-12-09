INCLUDE_DIRECTORIES(../inc)
ADD_EXECUTABLE(taosdemoTest test.c)
target_link_libraries(taosdemoTest cunit taos pthread cJsonDemo)
add_test(NAME taosdemoTest COMMAND taosdemoTest)