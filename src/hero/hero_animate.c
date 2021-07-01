/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** hero_animate
*/

#include "global.h"

int animate_hurt(hero_t *hero)
{
    char *anim_hurt[] = {"hurt_right", "hurt_bot", "hurt_left",
        "hurt_top"};

    if (hero->is_getting_damage == 0)
        return (0);
    hero->animation = get_animation_w_name(hero->animation_list,
    anim_hurt[hero->direction]);
    return (1);
}

int animate_attack(hero_t *hero)
{
    char *anim_attack[] = {"attack_right", "attack_bot", "attack_left",
        "attack_top"};

    if (hero->is_attacking == 0)
        return (0);
    hero->animation = get_animation_w_name(hero->animation_list,
    anim_attack[hero->direction]);
    return (1);
}

void animate_run(hero_t *hero)
{
    char *anim_run[] = {"run_right", "run_bot", "run_left", "run_top"};
    char *anim_run_hold[] = {"run_hold_right", "run_hold_bot", "run_hold_left",
        "run_hold_top"};
    char *anim_name = NULL;

    anim_name = (hero->bomb != NULL && hero->bomb->is_held == 1 ?
anim_run_hold[hero->direction] : anim_run[hero->direction]);
    hero->animation = get_animation_w_name(hero->animation_list, anim_name);
}

void animate_idle(hero_t *hero)
{
    char *anim_idle[] = {"idle_right", "idle_bot", "idle_left", "idle_top"};
    char *anim_idle_hold[] = {"idle_hold_right", "idle_hold_bot",
        "idle_hold_left", "idle_hold_top"};
    char *anim_name = NULL;

    anim_name = (hero->bomb != NULL && hero->bomb->is_held == 1 ?
anim_idle_hold[hero->direction] : anim_idle[hero->direction]);
    hero->animation = get_animation_w_name(hero->animation_list, anim_name);
}

void show_damage(sfRenderWindow* window, struct transiton_t *transition,
game_t *game)
{
    if (game->hero->is_getting_damage && transition->done == 0) {
        fade(window, transition, NULL);
        if (transition->done) {
            transition->ascending = 0;
            transition->fade_color = sfColor_fromRGBA(255, 0, 0, 110);
        }
    }
}
