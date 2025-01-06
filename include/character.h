#ifndef CHARACTER_H
#define CHARACTER_H

#include <entity.h>
#include <stdint.h>

enum CharacterType
{
    Warrior,
    Orc
};

typedef struct character_t
{
    struct entity_t;
    // private
    int64_t _health;
    int64_t _strength;
    int64_t _defense;
    enum CharacterType _type;

    // getters
    int64_t (*get_health)(const struct character_t *character);
    int64_t (*get_strength)(const struct character_t *character);
    int64_t (*get_defense)(const struct character_t *character);
    enum CharacterType (*get_type)(const struct character_t *character);

    // setters
    void (*set_health)(struct character_t *character, const int64_t health);
    void (*set_strength)(struct character_t *character, const int64_t strength);
    void (*set_defense)(struct character_t *character, const int64_t defense);
    void (*set_type)(struct character_t *character, enum CharacterType type);
} Character;

Character character_new(const char *name, int64_t health, int64_t strength, int64_t defense, enum CharacterType type);

#endif // !CHARACTER_H
