/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** npc_manager
*/

#include "global.h"
#include "protos.h"
#include <SFML/Graphics.h>
#include <math.h>

sfBool sprite_in_reach(sfSprite *ref, sfSprite *npc, int reach)
{
    sfFloatRect ref_bounds = sfSprite_getGlobalBounds(ref);
    sfFloatRect npc_bounds = sfSprite_getGlobalBounds(npc);
    int dist = sqrt(pow(ref_bounds.top + ref_bounds.height/2 - npc_bounds.top +
    npc_bounds.height, 2) + pow(ref_bounds.left + ref_bounds.width/2 -
    npc_bounds.left + npc_bounds.width/2, 2));

    if (dist <= reach)
        return (sfTrue);
    return (sfFalse);
}