/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** inventory.c
*/

#include "global.h"

sfVector2f get_box_position(int offset, int i)
{
    sfVector2f pos;

    pos.x = (i % 6) * 96 + offset + 430;
    pos.y = (i / 6) * 84 + offset + 140;
    return (pos);
}

box_t *create_box(int offset, int pos)
{
    box_t *box = malloc(sizeof(box_t));

    box->empty = 0;
    box->element = NULL;
    box->position = get_box_position(offset, pos);
    return (box);
}

node_t *init_boxes(int nb_boxes, int offset)
{
    node_t *start = malloc(sizeof(node_t));
    node_t *previous = NULL;
    node_t *tmp = start;

    start->next = NULL;
    for (int i = 0; i < nb_boxes; i++) {
        previous != NULL ? previous->next = tmp : (void)previous;
        tmp->data = create_box(offset, i);
        tmp->next = NULL;
        previous = tmp;
        tmp = malloc(sizeof(node_t));
    }
    return (start);
}

inv_msg_t *init_inv_msg(void)
{
    inv_msg_t *inv = malloc(sizeof(inv_msg_t));

    inv->msg_bg = load_sprite(MSG_INV);
    sfSprite_setScale(inv->msg_bg, (sfVector2f){1, 0.5});
    sfSprite_setPosition(inv->msg_bg, (sfVector2f){400, 700});
    inv->full_inv_err = init_inv_text(FULL_INV_ERR);
    inv->full_life_err = init_inv_text(FULL_LIFE_ERR);
    inv->hold_err = init_inv_text(HOLD_ERR);
    inv->level_up = init_inv_text(GAIN_LVL);
    inv->gain_xp = init_inv_text(GAIN_XP);
    inv->clock = sfClock_create();
    return (inv);
}

inventory_t *init_inventory(game_t *game)
{
    inventory_t *inv = malloc(sizeof(inventory_t));

    inv->displayed = 0;
    inv->sprite = load_sprite(INVENTORY);
    center_sprite(game, inv->sprite, 0);
    inv->total_elem = 24;
    inv->remaining = inv->total_elem;
    inv->offset = 100;
    inv->boxes = init_boxes(inv->total_elem, inv->offset);
    inv->inv_msg = init_inv_msg();
    inv->title = create_texts(TITLE_FONT, (sfVector2f){500, 150}, sfWhite);
    sfText_setString(inv->title, "INVENTORY");
    sfText_setCharacterSize(inv->title, 40);
    return (inv);
}