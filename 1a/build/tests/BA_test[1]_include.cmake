if(EXISTS "/home/babrakadabra/second_course/C/CPP/1a/build/tests/BA_test[1]_tests.cmake")
  include("/home/babrakadabra/second_course/C/CPP/1a/build/tests/BA_test[1]_tests.cmake")
else()
  add_test(BA_test_NOT_BUILT BA_test_NOT_BUILT)
endif()
