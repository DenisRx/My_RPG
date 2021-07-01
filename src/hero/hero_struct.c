/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** hero_struct
*/

#include "game.h"
#include "my.h"
#include "protos.h"
#include <stdlib.h>

void init_hero(hero_t *hero)
{
    hero->damage = 30;
    hero->speed = 5;
    hero->xp = 0;
    hero->level = 1;
    hero->critical_chance = 0;
    hero->resistance = 0;
    hero->is_moving = 0;
    hero->is_getting_damage = 0;
    hero->is_attacking = 0;
    hero->lives = 6;
    hero->color = GREEN;
}

hero_t *create_hero(game_t *game)
{
    hero_t *hero = malloc(sizeof(hero_t));

    hero->animation_list = create_animation_list(hero_animations, GREEN);
    hero->direction = BOT;
    hero->animation = get_animation_w_name(hero->animation_list, "idle_bot");
    hero->swipe_animation = NULL;
    hero->sword_animation = NULL;
    hero->bomb = NULL;
    hero->movement_clock = sfClock_create();
    hero->invic_anim = sfClock_create();
    hero->movement = (sfVector2f) {0, 0};
    hero->position = get_player_spawn(game);
    hero->invicibilty = sfClock_create();
    hero->knockback_clock = sfClock_create();
    init_hero(hero);
    return (hero);
}