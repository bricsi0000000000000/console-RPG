#include <gtest/gtest.h>

#include "../jsonParser.cpp"
#include "../character.cpp"

TEST(unitTests, parseCharacterEquals){
    Character* character1 = new Character("Mapple", 1500, 80, 2.9, 4, 8, 2);
    Character* character2 = JsonParser::parseUnitFromFile("../units/unit2.json");

    ASSERT_EQ(character1->GetName(), character2->GetName());
    ASSERT_EQ(character1->GetHealth(), character2->GetHealth());
    ASSERT_EQ(character1->GetDamage(), character2->GetDamage());
    ASSERT_EQ(character1->GetAttackcooldown(), character2->GetAttackcooldown());
}

TEST(unitTests, parseCharacterNotEquals){
    Character* character1 = new Character("Mapel", 510, 79, 4, 2, 3, 2);
    Character* character2 = JsonParser::parseUnitFromFile("../units/unit2.json");

    ASSERT_NE(character1->GetName(), character2->GetName());
    ASSERT_NE(character1->GetHealth(), character2->GetHealth());
    ASSERT_NE(character1->GetDamage(), character2->GetDamage());
    ASSERT_NE(character1->GetAttackcooldown(), character2->GetAttackcooldown());
}

TEST(jsonParseTests, parseCharacterMissingCurlyBracket){
    Character* character1 = new Character("Mapple", 1500, 80, 2.9, 4, 8, 2);
    Character* character2 = JsonParser::parseUnitFromFile("wrong_units/wrong_unit1.json");

    ASSERT_EQ(character1->GetName(), character2->GetName());
    ASSERT_EQ(character1->GetHealth(), character2->GetHealth());
    ASSERT_EQ(character1->GetDamage(), character2->GetDamage());
    ASSERT_EQ(character1->GetAttackcooldown(), character2->GetAttackcooldown());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}