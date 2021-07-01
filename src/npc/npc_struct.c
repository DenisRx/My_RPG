/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** npc_struct
*/

#include "global.h"
#include "protos.h"
#include <stdlib.h>

static const sfVector2f npc_scale = {2.4, 2.4};

const anim_config_t npc_animations[] = {
    {"idle_bot", "assets/hero/green/idle_bot.png", 4, 1, npc_scale, 120000},
    {"idle_right", "assets/hero/green/idle_side.png", 4, 1, npc_scale, 120000},
    {"idle_left", "assets/hero/green/idle_left.png", 4, 1, npc_scale, 120000},
    {"idle_top", "assets/hero/green/idle_top.png", 4, 1, npc_scale, 120000},
    {NULL}
};

sfSprite *create_message_box(void)
{
    sfSprite *box = load_sprite(MSG_BOX);

    sfSprite_setScale(box, (sfVector2f){1, 0.5});
    sfSprite_setPosition(box, (sfVector2f){400, 700});
    return (box);
}

npc_t *generate_npc(void)
{
    npc_t *npc = malloc(sizeof(npc_t));

    npc->id = 1;
    npc->quest_id = 1;
    return (npc);
}