add_test([=[GameFieldCreate.Construct]=]  [==[/home/babrakadabra/second_course/CPP_tasks/Game Life/build/tests/game_test]==] [==[--gtest_filter=GameFieldCreate.Construct]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[GameFieldCreate.Construct]=]  PROPERTIES WORKING_DIRECTORY [==[/home/babrakadabra/second_course/CPP_tasks/Game Life/build/tests]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[GameFieldCreate.is_life]=]  [==[/home/babrakadabra/second_course/CPP_tasks/Game Life/build/tests/game_test]==] [==[--gtest_filter=GameFieldCreate.is_life]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[GameFieldCreate.is_life]=]  PROPERTIES WORKING_DIRECTORY [==[/home/babrakadabra/second_course/CPP_tasks/Game Life/build/tests]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[GameFieldCreate.to_life]=]  [==[/home/babrakadabra/second_course/CPP_tasks/Game Life/build/tests/game_test]==] [==[--gtest_filter=GameFieldCreate.to_life]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[GameFieldCreate.to_life]=]  PROPERTIES WORKING_DIRECTORY [==[/home/babrakadabra/second_course/CPP_tasks/Game Life/build/tests]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[GameFieldCreate.to_dead]=]  [==[/home/babrakadabra/second_course/CPP_tasks/Game Life/build/tests/game_test]==] [==[--gtest_filter=GameFieldCreate.to_dead]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[GameFieldCreate.to_dead]=]  PROPERTIES WORKING_DIRECTORY [==[/home/babrakadabra/second_course/CPP_tasks/Game Life/build/tests]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[GameProccess.update]=]  [==[/home/babrakadabra/second_course/CPP_tasks/Game Life/build/tests/game_test]==] [==[--gtest_filter=GameProccess.update]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[GameProccess.update]=]  PROPERTIES WORKING_DIRECTORY [==[/home/babrakadabra/second_course/CPP_tasks/Game Life/build/tests]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[GameResults.OutputFile]=]  [==[/home/babrakadabra/second_course/CPP_tasks/Game Life/build/tests/game_test]==] [==[--gtest_filter=GameResults.OutputFile]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[GameResults.OutputFile]=]  PROPERTIES WORKING_DIRECTORY [==[/home/babrakadabra/second_course/CPP_tasks/Game Life/build/tests]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  game_test_TESTS GameFieldCreate.Construct GameFieldCreate.is_life GameFieldCreate.to_life GameFieldCreate.to_dead GameProccess.update GameResults.OutputFile)
