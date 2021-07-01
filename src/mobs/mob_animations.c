/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** mob_animations
*/

#include "global.h"

named_animation_t *create_mob_anim(tag_t *anim)
{
    named_animation_t *animation = malloc(sizeof(named_animation_t));

    animation->name = get_property(anim, "name");
    animation->animation = create_animation(get_property(anim, "path"),
    get_property_int(anim, "sprite_count", 1), 1, (sfVector2f) {
        get_property_int(anim, "scale_x", 2),
        get_property_int(anim, "scale_y", 2)
    });
    animation->animation->delay = get_property_int(anim, "delay", 120000);
    return (animation);
}

node_t *create_mob_animation_list(tag_t *mob_tag)
{
    tag_t *anim_tag = mob_tag->children->data;
    node_t *start = malloc(sizeof(node_t));
    node_t *tmp = start;
    node_t *previous = NULL;

    start->next = NULL;
    for (node_t *node = anim_tag->children; node != NULL; node = node->next) {
        previous != NULL ? previous->next = tmp : (void)previous;
        tmp->data = create_mob_anim(node->data);
        tmp->next = NULL;
        previous = tmp;
        tmp = malloc(sizeof(node_t));
    }
    return (start);
}

node_t *add_mob(node_t *node, tag_t *mob_tag, sfVector2f indexes, game_t *game)
{
    node_t *tmp = node;

    tmp->data = get_mob_from_id(mob_tag, indexes, game);
    tmp->next = init_node();
    return (tmp->next);
}