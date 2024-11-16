#include <catch2/catch_test_macros.hpp>

#include "main.h"

TEST_CASE("longest_common_substring")
{
    REQUIRE(longest_common_substring("hello world", "hello") == "hello");
    REQUIRE_THROWS_AS(longest_common_substring("abcdef", "ghijkl"),
                      std::invalid_argument);
    REQUIRE(longest_common_substring("Hola", "o1243154145234la") == "la");
    REQUIRE(longest_common_substring("Hola", "o1243154145234LA") == "o");
}

TEST_CASE("largest_palindrome")
{
    REQUIRE(largest_palindrome("babad") == "bab");
    REQUIRE(largest_palindrome("cbbd") == "bb");
    REQUIRE(largest_palindrome("a") == "a");
    REQUIRE(largest_palindrome("ac") == "a");
}

TEST_CASE("contains_text")
{
    REQUIRE(contains_text("hello world", "world") == true);
    REQUIRE(contains_text("hello world", "WORLD") == false);
    REQUIRE(contains_text("hello world", "worlD") == false);

    REQUIRE(contains_text("abcdef", "def") == true);
    REQUIRE(contains_text("abcdef", "gh") == false);
}
