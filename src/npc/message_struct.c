/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** message_struct
*/

#include "global.h"

node_t *get_msg_list(tag_t *tag)
{
    tag_t *dialogs = tag->children->next->data;
    node_t *start = malloc(sizeof(node_t));
    node_t *tmp = start;
    node_t *previous = NULL;

    start->next = NULL;
    for (node_t *node = dialogs->children; node != NULL; node = node->next) {
        previous != NULL ? previous->next = tmp : (void)previous;
        tmp->data = my_strdup(((tag_t *)node->data)->inner);
        tmp->next = NULL;
        previous = tmp;
        tmp = malloc(sizeof(node_t));
    }
    return (start);
}

void center_text_on_sprite(sfSprite *sprite, sfText *text)
{
    sfVector2f sprite_pos = sfSprite_getPosition(sprite);
    sfFloatRect sprite_bounds = sfSprite_getGlobalBounds(sprite);
    sfFloatRect text_bounds = sfText_getGlobalBounds(text);
    sfVector2f text_pos;

    text_pos.x = sprite_pos.x + (sprite_bounds.width - text_bounds.width) / 2;
    text_pos.y = sprite_pos.y + sprite_bounds.height/2 - text_bounds.height;
    sfText_setPosition(text, text_pos);
}

sfText *create_msg(sfSprite *msg_box, char *msg)
{
    sfFont *font = sfFont_createFromFile(MSG_FONT);
    sfText *text = create_text(font, MSG_SIZE);

    sfText_setString(text, msg);
    sfText_setColor(text, sfWhite);
    center_text_on_sprite(msg_box, text);
    return (text);
}