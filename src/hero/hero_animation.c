/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** hero_animation
*/

#include "global.h"

const sfVector2f scale = {2.4, 2.4};

const char *character_color_path[] = {
    "assets/hero/green/",
    "assets/hero/blue/",
    "assets/hero/purple/",
    "assets/hero/red/"
};

const anim_config_t hero_animations[] = {
    {"idle_bot", "idle_bot.png", 4, 1, scale, 120000},
    {"idle_right", "idle_side.png", 4, 1, scale, 120000},
    {"idle_left", "idle_left.png", 4, 1, scale, 120000},
    {"idle_top", "idle_top.png", 4, 1, scale, 120000},

    {"idle_hold_bot", "idle_hold_bot.png", 1, 1, scale, 1},
    {"idle_hold_right", "idle_hold_right.png", 1, 1, scale, 1},
    {"idle_hold_left", "idle_hold_left.png", 1, 1, scale, 1},
    {"idle_hold_top", "idle_hold_top.png", 1, 1, scale, 1},

    {"run_bot", "run_bot.png", 4, 1, scale, 120000},
    {"run_right", "run_side.png", 4, 1, scale, 120000},
    {"run_left", "run_left.png", 4, 1, scale, 120000},
    {"run_top", "run_top.png", 4, 1, scale, 120000},

    {"run_hold_bot", "run_hold_bot.png", 6, 1, scale, 120000},
    {"run_hold_right", "run_hold_right.png", 6, 1, scale, 120000},
    {"run_hold_left", "run_hold_left.png", 6, 1, scale, 120000},
    {"run_hold_top", "run_hold_top.png", 6, 1, scale, 120000},

    {"attack_top", "attack_top.png", 6, 1, scale, 100000},
    {"attack_right", "attack_side.png", 6, 1, scale, 100000},
    {"attack_left", "attack_left.png", 6, 1, scale, 100000},
    {"attack_bot", "attack_bot.png", 6, 1, scale, 100000},

    {"sword_top", "sword/attack_top.png", 3, 1, scale, 100000},
    {"sword_right", "sword/attack_side.png", 3, 1, scale, 100000},
    {"sword_left", "sword/attack_left.png", 3, 1, scale, 100000},
    {"sword_bot", "sword/attack_bot.png", 3, 1, scale, 100000},

    {"swipe_top", "sword/swipe_top.png", 2, 1, scale, 300000},
    {"swipe_right", "sword/swipe_right.png", 2, 1, scale, 300000},
    {"swipe_left", "sword/swipe_left.png", 2, 1, scale, 300000},
    {"swipe_bot", "sword/swipe_bot.png", 2, 1, scale, 300000},

    {"hurt_bot", "hurt_bot.png", 3, 1, scale, 100000},
    {"hurt_right", "hurt_right.png", 3, 1, scale, 100000},
    {"hurt_left", "hurt_left.png", 3, 1, scale, 100000},
    {"hurt_top", "hurt_top.png", 3, 1, scale, 100000},
    {"dies", "dead.png", 17, 1, scale, 100000},
    {NULL}
};

named_animation_t *create_name_anim(const anim_config_t config, int type)
{
    named_animation_t *anim = malloc(sizeof(named_animation_t));
    char *path = create_str((char *)character_color_path[type], config.path);

    anim->name = config.name;
    anim->animation = create_animation(path, config.sprite_nb,
    config.line, config.scale);
    anim->animation->delay = config.delay;
    return (anim);
}

node_t *create_animation_list(const anim_config_t *animation_list, int type)
{
    node_t *start = malloc(sizeof(node_t));
    node_t *tmp = start;
    node_t *previous = NULL;

    start->next = NULL;
    for (int i = 0; animation_list[i].name != NULL; i++) {
        previous != NULL ? previous->next = tmp : (void)previous;
        tmp->data = create_name_anim(animation_list[i], type);
        tmp->next = NULL;
        previous = tmp;
        tmp = malloc(sizeof(node_t));
    }
    return (start);
}

animation_t *get_animation_w_name(node_t *animation_list, char *name)
{
    for (node_t *node = animation_list; node != NULL; node = node->next) {
        if (my_strcmp(((named_animation_t *)node->data)->name, name) == 0)
            return (((named_animation_t *)node->data)->animation);
    }
    return (NULL);
}

void animate_hero(game_t *game)
{
    hero_t *hero = game->hero;

    if (animate_attack(hero))
        return;
    if (animate_hurt(hero))
        return;
    else if (hero->is_moving) {
        animate_run(hero);
        return;
    }
    if (sfClock_getElapsedTime(hero->animation->animation_clock).microseconds /
        hero->animation->delay >= 1)
        animate_idle(hero);
}