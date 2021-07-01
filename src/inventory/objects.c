/*
** EPITECH PROJECT, 2020
** RPG
** File description:
** object.c
*/

#include "protos.h"
#include "global.h"

const char *item_list[] = {
    "POTION",
    "BOMB",
    "SCROLL"
};

const char *path_list[] = {
    "assets/hud/potion.png",
    "assets/hud/bomb.png",
    "assets/hud/scroll.png"
};

object_t *create_object(int type, sfVector2f position)
{
    object_t *infos = malloc(sizeof(object_t));

    infos->type = type;
    infos->name = (char *)item_list[type];
    infos->sprite = load_sprite(path_list[type]);
    sfSprite_setPosition(infos->sprite, position);
    return (infos);
}

node_t *add_in_ground_list(int type, sfVector2f position, game_t *game)
{
    node_t *node = malloc(sizeof(node_t));
    node_t *last;

    node->data = create_object(type, position);
    node->next = NULL;
    if (game->map->objects == NULL)
        game->map->objects = node;
    else {
        last = game->map->objects;
        while (last->next != NULL)
            last = last->next;
        last->next = node;
    }
    return (node);
}

node_t *remove_of_ground_list(game_t *game, node_t *obj_node)
{
    node_t *head = game->map->objects;
    node_t *node = head;
    node_t *previous;
    node_t *tmp;

    if (node != NULL && node == obj_node) {
        tmp = node->next;
        free(node);
        return tmp;
    }
    while (node != NULL && node != obj_node) {
        previous = node;
        node = node->next;
    }
    if (node == NULL)
        return (NULL);
    previous->next = node->next;
    return (head);
}