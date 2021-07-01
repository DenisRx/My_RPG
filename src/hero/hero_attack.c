/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** hero_input
*/

#include "game.h"
#include "protos.h"

void attack_key_press(__attribute__((unused))sfRenderWindow *window,
sfEvent event, game_t *game)
{
    hero_t *hero = game->hero;

    if (event.key.code == sfKeySpace) {
        if (hero->bomb == NULL) {
            hero->is_attacking = 1;
            animate_swipe(game);
        } else {
            throw_bomb(hero);
        }
    }
}

void animate_sword(game_t *game)
{
    hero_t *hero = game->hero;
    char *anim_sword[] = {"sword_right", "sword_bot",
        "sword_left", "sword_top"};
    hero->sword_animation = get_animation_w_name(hero->animation_list,
    anim_sword[hero->direction]);
    hero->sword_animation->current_frame = -1;
    sfSprite_setPosition(hero->sword_animation->sprite,
    get_hand_position(game));
}

void animate_swipe(game_t *game)
{
    hero_t *hero = game->hero;
    char *anim_swipe[] = {"swipe_right", "swipe_bot",
        "swipe_left", "swipe_top"};

    hero->swipe_animation = get_animation_w_name(hero->animation_list,
    anim_swipe[hero->direction]);
    center_origin_sprite(hero->swipe_animation->sprite);
    sfSprite_setPosition(hero->swipe_animation->sprite,
    get_front_position(hero,
    sfSprite_getGlobalBounds(hero->swipe_animation->sprite)));
}

void stop_attack(game_t *game)
{
    hero_t *hero = game->hero;

    if (hero->sword_animation != NULL &&
    is_animation_ended(hero->sword_animation)) {
        hero->sword_animation = NULL;
    }
    if (hero->is_attacking && is_animation_ended(hero->animation)) {
        hero->animation->current_frame = -1;
        hero->swipe_animation->current_frame = -1;
        hero->swipe_animation = NULL;
        game->hero->is_attacking = 0;
    }
    if (hero->sword_animation == NULL &&
    hero->is_attacking && hero->animation->current_frame == 3) {
        animate_sword(game);
    }
}