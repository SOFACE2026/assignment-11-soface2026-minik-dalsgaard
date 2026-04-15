#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "dict.hpp"
#include <string>
#include <vector>

using Catch::Matchers::UnorderedEquals;

TEST_CASE("Test Dict")
{
    // Implement your own tests. You can use below as a reference.
    // When implementing tests, think of the edge cases where you
    // suspect the program is likely to fail.
    // For example inserting the 'same' person twice or removing an
    // non existent person from the dictionary.
    Dict<std::string, int> name_to_age;

    // The dictionary should initially be empty
    REQUIRE(name_to_age.len() == 0);

    // Insert first key-value pair
    name_to_age.set("Jane", 20);

    // Check that the element was inserted correctly
    REQUIRE(name_to_age.len() == 1);
    REQUIRE(name_to_age.has("Jane"));
    REQUIRE(name_to_age.get("Jane").has_value());
    REQUIRE(name_to_age.get("Jane").value() == 20);

    // Insert second key-value pair
    name_to_age.set("Tarzan", 25);

    // Now there should be two elements
    REQUIRE(name_to_age.len() == 2);
    REQUIRE(name_to_age.has("Tarzan"));
    REQUIRE(name_to_age.get("Tarzan").value() == 25);

    // Overwrite existing key
    name_to_age.set("Jane", 21);

    // Size should stay the same, value should change
    REQUIRE(name_to_age.len() == 2);
    REQUIRE(name_to_age.get("Jane").value() == 21);

    // Delete an existing key
    name_to_age.del("Jane");

    // Jane should be gone
    REQUIRE(name_to_age.len() == 1);
    REQUIRE_FALSE(name_to_age.has("Jane"));
    REQUIRE_FALSE(name_to_age.get("Jane").has_value());

    // Tarzan should still exist
    REQUIRE(name_to_age.has("Tarzan"));
    REQUIRE(name_to_age.get("Tarzan").value() == 25);

    // Deleting a key that does not exist should do nothing
    name_to_age.del("Jane");

    // Nothing should change
    REQUIRE(name_to_age.len() == 1);
}
