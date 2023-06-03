#include <gtest/gtest.h>
#include <Game.h>

class GameTest : public ::testing::Test {
protected:
    GameTest() {
    }

    ~GameTest() override {
    }


    void SetUp() override {
        game = new Game(3, nullptr);
        game->target_sequence.clear();
        game->target_sequence.push_back(BUTTON_A);
        game->target_sequence.push_back(BUTTON_B);
        game->target_sequence.push_back(BUTTON_A);
    }

    void TearDown() override {
        delete game;
    }
    Game* game;
};


TEST_F(GameTest, LastResultEmptyVectors)
{
    std::vector<char> button_pressed;
    uint8_t result;
    result = game->getLastResult(game->target_sequence, button_pressed);
    ASSERT_EQ(result, 0);
}

TEST_F(GameTest, LastResultEqualVectors)
{
    std::vector<char> button_pressed;
    uint8_t result;
    button_pressed.push_back(BUTTON_A);
    result = game->getLastResult(game->target_sequence, button_pressed);
    ASSERT_EQ(result, LED_GREEN);
}

TEST_F(GameTest, LastResultExistentVectors)
{
    std::vector<char> button_pressed;
    uint8_t result;
    button_pressed.push_back(BUTTON_B);
    result = game->getLastResult(game->target_sequence, button_pressed);
    ASSERT_EQ(result, LED_ORANGE);
}

TEST_F(GameTest, LastResultNonExistentVectors)
{
    std::vector<char> target_sequence;
    std::vector<char> button_pressed;
    uint8_t result;
    button_pressed.push_back(BUTTON_C);
    result = game->getLastResult(game->target_sequence, button_pressed);
    ASSERT_EQ(result, LED_RED);
}

TEST_F(GameTest, GetLEDResultEmptyVector)
{
    std::vector<uint8_t> results;
    std::vector<uint8_t> led_result;
    led_result = game->getLEDResult(results);
    ASSERT_EQ(led_result[0], LED_OFF);
    ASSERT_EQ(led_result[1], LED_OFF);
    ASSERT_EQ(led_result[2], LED_OFF);
}

TEST_F(GameTest, GetLEDResultMoreElements)
{
    std::vector<uint8_t> results;
    std::vector<uint8_t> led_result;
    results.push_back(LED_GREEN);
    results.push_back(LED_ORANGE);
    results.push_back(LED_RED);
    results.push_back(LED_GREEN);
    results.push_back(LED_ORANGE);
    results.push_back(LED_RED);
    led_result = game->getLEDResult(results);
    ASSERT_EQ(led_result.size(), 3);
    ASSERT_EQ(led_result[0], LED_GREEN);
    ASSERT_EQ(led_result[1], LED_ORANGE);
    ASSERT_EQ(led_result[2], LED_RED);
}

TEST_F(GameTest, GetLEDResultEnoughElements)
{
    std::vector<uint8_t> results;
    std::vector<uint8_t> led_result;
    results.push_back(LED_GREEN);
    results.push_back(LED_ORANGE);
    results.push_back(LED_RED);
    led_result = game->getLEDResult(results);
    ASSERT_EQ(led_result.size(), 3);
    ASSERT_EQ(led_result[0], LED_GREEN);
    ASSERT_EQ(led_result[1], LED_ORANGE);
    ASSERT_EQ(led_result[2], LED_RED);
}

TEST_F(GameTest, GetLEDResultLessElements)
{
    std::vector<uint8_t> results;
    std::vector<uint8_t> led_result;
    results.push_back(LED_GREEN);
    led_result = game->getLEDResult(results);
    ASSERT_EQ(led_result.size(), 3);
    ASSERT_EQ(led_result[0], LED_OFF);
    ASSERT_EQ(led_result[1], LED_OFF);
    ASSERT_EQ(led_result[2], LED_GREEN);
}