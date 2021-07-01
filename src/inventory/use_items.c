/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** use_items.c
*/

#include "global.h"
#include "protos.h"

node_t *remove_from_inventory(game_t *game, node_t *inv_node)
{
    node_t *first = game->inventory->boxes;

    for (node_t *node = first; node != NULL; node = node->next) {
        if (node == inv_node) {
            ((box_t *)node->data)->empty = 0;
            ((box_t *)node->data)->element = NULL;
            return (first);
        }
    }
    return (first);
}

void display_dialog(game_t *game, sfSprite *sprite, sfText *text, long delay)
{
    sfFloatRect rect = sfText_getGlobalBounds(text);
    dialog_t *dialog = game->dialog;
    sfFloatRect sprite_rect;

    sfClock_restart(dialog->clock);
    dialog->displayed = 1;
    dialog->delay = delay;
    dialog->sprite = sprite;
    dialog->text = text;
    sprite_rect = sfSprite_getGlobalBounds(sprite);
    sfText_setOrigin(text, (sfVector2f){rect.width/2, rect.height/2});
    sfText_setPosition(dialog->text,
    (sfVector2f){sprite_rect.left + sprite_rect.width / 2,
        sprite_rect.top + sprite_rect.height / 2});
}

void add_life(game_t *game, node_t *node)
{
    inv_msg_t *inv = game->inventory->inv_msg;

    if (game->life_infos.remaining_lives == game->life_infos.max_lives)
        display_dialog(game, inv->msg_bg, inv->full_life_err, 3000000);
    else {
        game->life_infos.remaining_lives += 1;
        remove_from_inventory(game, node);
    }
}

void hold_bomb(game_t *game, node_t *node)
{
    inv_msg_t *inv = game->inventory->inv_msg;

    if (game->hero->bomb != NULL) {
        display_dialog(game, inv->msg_bg, inv->hold_err, 3000000);
        return;
    }
    game->hero->bomb = create_bomb(game->hero);
    remove_from_inventory(game, node);
}

void raise_xp(game_t *game, node_t *node)
{
    inv_msg_t *inv = game->inventory->inv_msg;

    game->hero->xp += 20;
    display_dialog(game, inv->msg_bg, inv->gain_xp, 1000000);
    remove_from_inventory(game, node);
    check_level(game);
}