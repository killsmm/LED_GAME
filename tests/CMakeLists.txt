#TEST

include(GoogleTest)
enable_testing()
add_executable(LED_GAME_TEST GameTest.cpp TestMain.cpp ../Game.cpp)
add_test(LED_GAME_TEST LED_GAME_TEST)
target_link_libraries(LED_GAME_TEST  gtest gtest_main pthread)

add_executable(LED_GAME_INTEGRATION_TEST IntegrationTest.cpp ../Game.cpp ../HALFactory.cpp ../Terminal.cpp)
