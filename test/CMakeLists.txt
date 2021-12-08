set(CMAKE_C_FLAGS "-fprofile-arcs -ftest-coverage")
ADD_EXECUTABLE(taosdemoTest test.c)
target_link_libraries(taosdemoTest cunit)
add_test(NAME taosdemoTest COMMAND taosdemoTest)