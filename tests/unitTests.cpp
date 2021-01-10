#include <gtest/gtest.h>

#include "../jsonParser.cpp"
#include "../character.cpp"
#include "../player.cpp"
#include "../enemy.cpp"

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

TEST(unitTests, parsePlayer){
	Player* player1 = new Player("Kakarott", 3000, 99, 2.8, 2, 3, 2);
	Character* character = JsonParser::parseUnitFromFile("../units/unit1.json");
	Player player2(character);

	ASSERT_EQ(player1->GetName(), player2.GetName());
	ASSERT_EQ(player1->GetHealth(), player2.GetHealth());
	ASSERT_EQ(player1->GetDamage(), player2.GetDamage());
	ASSERT_EQ(player1->GetAttackcooldown(), player2.GetAttackcooldown());
}

TEST(unitTests, parseEnemy){
	Enemy* enemy1 = new Enemy("Mapple", 1500, 80, 2.9, 4, 8, 3);
	Character* character = JsonParser::parseUnitFromFile("../units/unit2.json");
	Enemy enemy2(character);

	ASSERT_EQ(enemy1->GetName(), enemy2.GetName());
	ASSERT_EQ(enemy1->GetHealth(), enemy2.GetHealth());
	ASSERT_EQ(enemy1->GetDamage(), enemy2.GetDamage());
	ASSERT_EQ(enemy1->GetAttackcooldown(), enemy2.GetAttackcooldown());
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