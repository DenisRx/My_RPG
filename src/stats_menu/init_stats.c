/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** stats.c
*/

#include "global.h"

void set_stats_infos(stats_t *stats, game_t *game)
{
    sfText_setString(stats->title, "STATISTICS");
    sfText_setString(stats->xp_txt, my_getstr(game->hero->xp));
    sfText_setString(stats->lives_txt, my_getstr(game->hero->lives));
    sfText_setString(stats->damage_txt, my_getstr(game->hero->damage));
    sfText_setString(stats->crit_txt, my_getstr(game->hero->critical_chance));
    sfText_setString(stats->res_txt, my_getstr(game->hero->resistance));
    sfText_setString(stats->level_txt, my_getstr(game->hero->level));
}

void set_size_texts(stats_t *stats)
{
    int size = 30;

    sfText_setCharacterSize(stats->title, 40);
    sfText_setCharacterSize(stats->level_txt, size);
    sfText_setCharacterSize(stats->xp_txt, size);
    sfText_setCharacterSize(stats->lives_txt, size);
    sfText_setCharacterSize(stats->damage_txt, size);
    sfText_setCharacterSize(stats->crit_txt, size);
    sfText_setCharacterSize(stats->res_txt, size);
}

void set_sprite_infos(game_t *game, stats_t *stats)
{
    stats->displayed = 0;
    stats->bg = load_sprite(STATS_BG);
    center_sprite(game, stats->bg, 0);
}

stats_t *init_stat_struct(game_t *game)
{
    stats_t *stats = malloc(sizeof(stats_t));
    sfVector2f pos = {900, 245};
    int offset = 75;

    stats->title = create_texts(TITLE_FONT, (sfVector2f){500, 150}, sfWhite);
    stats->level_txt = create_texts(MSG_FONT, pos, sfWhite);
    pos.y += offset;
    stats->xp_txt = create_texts(MSG_FONT, pos, sfWhite);
    pos.y += offset;
    stats->lives_txt = create_texts(MSG_FONT, pos, sfWhite);
    pos.y += offset;
    stats->damage_txt = create_texts(MSG_FONT, pos, sfWhite);
    pos.y += offset;
    stats->crit_txt = create_texts(MSG_FONT, pos, sfWhite);
    pos.y += offset;
    stats->res_txt = create_texts(MSG_FONT, pos, sfWhite);
    set_sprite_infos(game, stats);
    set_stats_infos(stats, game);
    set_size_texts(stats);
    return (stats);
}