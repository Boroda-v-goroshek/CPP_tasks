if(EXISTS "/home/babrakadabra/second_course/CPP_tasks/Game Life/build/tests/game_test[1]_tests.cmake")
  include("/home/babrakadabra/second_course/CPP_tasks/Game Life/build/tests/game_test[1]_tests.cmake")
else()
  add_test(game_test_NOT_BUILT game_test_NOT_BUILT)
endif()