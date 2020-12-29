#include <gtest/gtest.h>

#include "../jsonParser.cpp"
#include "../character.cpp"

TEST(unitTests, parseCharacter){
    Character* character1 = new Character("Mapple", 150, 10, 10);
    Character* character2 = JsonParser::parseUnitFromFile("../units/unit2.json");

    ASSERT_EQ(character1->GetName(), character2->GetName());
    ASSERT_EQ(character1->GetHealth(), character2->GetHealth());
    ASSERT_EQ(character1->GetDamage(), character2->GetDamage());
    ASSERT_EQ(character1->GetAttackcooldown(), character2->GetAttackcooldown());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}