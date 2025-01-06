#include <character.h>

int64_t character_get_health(const struct character_t *character) { return character->_health; }

int64_t character_get_strength(const struct character_t *character) { return character->_strength; }

int64_t character_get_defense(const struct character_t *character) { return character->_defense; }

enum CharacterType character_get_type(const struct character_t *character) { return character->_type; }

void character_set_health(struct character_t *character, const int64_t health) { character->_health = health; }

void character_set_strength(struct character_t *character, const int64_t strength) { character->_strength = strength; }

void character_set_defense(struct character_t *character, const int64_t defense) { character->_defense = defense; }

void character_set_type(struct character_t *character, const enum CharacterType type) { character->_type = type; }

void character_attack(struct character_t *character, struct character_t *to_attack)
{
    to_attack->set_health(to_attack, to_attack->get_health(to_attack) - character->get_strength(character) -
                                         to_attack->get_defense(to_attack));
}

Character character_new(const char *name, const int64_t health, const int64_t strength, const int64_t defense,
                        enum CharacterType type)
{
    return (Character){{name, {0, 0}, entity_get_name, entity_set_name},
                       health,
                       strength,
                       defense,
                       type,
                       character_get_health,
                       character_get_strength,
                       character_get_defense,
                       character_get_type,
                       character_set_health,
                       character_set_strength,
                       character_set_defense,
                       character_set_type,
                       character_attack};
}
