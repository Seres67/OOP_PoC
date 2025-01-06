#include "character.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/random.h>

int get_random_number(int min, int max) { return rand() % (max - min + 1) + min; }

int main()
{
    char buffer[64];
    long ret = getrandom(buffer, 64, 0);
    if (ret == -1)
        return 84;
    unsigned long long seed = 0;
    for (int i = 0; i < 64; ++i)
        seed += buffer[i];
    srand(seed);

    Character char1 =
        character_new("Orc", get_random_number(0, 100), get_random_number(10, 100), get_random_number(0, 100), Orc);
    Character char2 = character_new("Warrior", get_random_number(0, 100), get_random_number(10, 100),
                                    get_random_number(0, 100), Warrior);

    printf("Char1: %ld health\n", char1.get_health(&char1));
    printf("Char2: %ld health\n", char2.get_health(&char2));

    while (char1.get_health(&char1) > 0 && char2.get_health(&char2) > 0) {
        char1.attack(&char1, &char2);
        printf("Char2: %ld health\n", char2.get_health(&char2));
        char2.attack(&char2, &char1);
        printf("Char1: %ld health\n", char1.get_health(&char1));
    }
    if (char1.get_health(&char1) <= 0)
        printf("%s wins: %ld health remaining\n", char2.get_name((Entity *)&char2), char2.get_health(&char2));
    if (char2.get_health(&char2) <= 0)
        printf("%s wins: %ld health remaining\n", char1.get_name((Entity *)&char1), char1.get_health(&char1));
}
