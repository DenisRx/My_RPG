/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** hero_utils
*/

#include "game.h"
#include "protos.h"

sfVector2f get_hand_position(game_t *game)
{
    hero_t *hero = game->hero;
    sfFloatRect rect = sfSprite_getGlobalBounds(hero->animation->sprite);
    sfVector2f pos = (sfVector2f) {rect.left, rect.top};

    if (hero->direction == BOT) {
        pos.x += rect.width / 2;
        pos.y -= rect.height / 2;
    }
    if (hero->direction == TOP)
        pos.x -= rect.width;
    if (hero->direction == RIGHT) {
        pos.x -= rect.width / 2;
        pos.y -= rect.height / 2;
    }
    if (hero->direction == LEFT) {
        pos.x += rect.width / 2.5;
        pos.y -= rect.height / 2;
    }
    return (pos);
}

sfVector2f get_front_position(hero_t *hero, sfFloatRect swipe_rect)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(hero->animation->sprite);
    sfVector2f pos = (sfVector2f) {rect.left, rect.top};

    if (hero->direction == BOT) {
        pos.x += rect.width / 2;
        pos.y += rect.height + swipe_rect.height / 2;
    }
    if (hero->direction == TOP) {
        pos.x += rect.width / 2;
        pos.y -= swipe_rect.height / 2;
    }
    if (hero->direction == RIGHT) {
        pos.x += rect.width + swipe_rect.width / 2;
        pos.y += rect.height / 2;
    }
    if (hero->direction == LEFT) {
        pos.x -= swipe_rect.width / 2;
        pos.y += rect.height / 2;
    }
    return (pos);
}