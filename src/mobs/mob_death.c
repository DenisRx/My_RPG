/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** mob_death
*/

#include "global.h"

void handle_ganon_death(__attribute__((unused))sfRenderWindow *window,
mob_t *mob, game_t *game)
{
    if (mob->life <= 0)
        mob->state = 99;
    if (mob->state < 99)
        return;
    game->win = 1;
    sfClock_restart(game->win_clock);
    if (mob->state == 99) {
        mob->animation = get_animation_w_name(mob->animation_list, "dead_loop");
        mob->state = 100;
    }
    if (mob->state == 100 && mob->animation->play_count > 10) {
        mob->animation = get_animation_w_name(mob->animation_list, "dead_end");
        mob->state = 101;
    }
    if (mob->state == 101 && is_animation_ended(mob->animation)) {
        mob->displayed = 0;
    }
}

void handle_mob_death(game_t *game, mob_t *mob)
{
    int drop = rand() % NB_TYPES;

    for (node_t *node = game->quests->quest_list; node; node = node->next) {
        if (mob->quest_id == ((quest_t*)node->data)->id)
            ((quest_t*)node->data)->status = 1;
    }
    if (rand() % 4 == 0)
        add_in_ground_list(drop, mob->position, game);
    game->hero->xp += mob->xp;
    if (mob->type != 16)
        mob->displayed = 0;
    check_level(game);
}