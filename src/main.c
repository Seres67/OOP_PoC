#include "character.h"
#include <stdint.h>
#include <stdio.h>

int main()
{
    Character orc = character_new("Orc", 100, 100, 100, Orc);
    Character warrior = character_new("Warrior", 100, 100, 100, Warrior);
    printf("Orc name: %s\n", orc.get_name((Entity *)&orc));
}
