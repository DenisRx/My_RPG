/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** mobs_struct
*/

#include "game.h"
#include "protos.h"
#include "my.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

tag_t *get_mob_tag(int id, tag_t *head)
{
    tag_t *mobs = head->children->data;
    node_t *node = mobs->children;
    tag_t *data;

    while (node != NULL) {
        data = node->data;
        if (get_property_int(data, "id", -1) == id)
            return (data);
        node = node->next;
    }
    return (NULL);
}

void init_mob(mob_t *mob)
{
    mob->is_getting_damage = 0;
    mob->is_moving = 0;
    mob->state = 0;
    mob->displayed = 1;
    mob->is_attacking = 0;
    mob->movement_clock = sfClock_create();
    mob->invicibilty = sfClock_create();
    mob->dmg_clock = sfClock_create();
    mob->knockback_clock = sfClock_create();
    mob->idle_clock = sfClock_create();
    mob->jump_clock = sfClock_create();
    mob->movement = (sfVector2f) {0, 0};
    mob->projectile = NULL;
    mob->direction = BOT;
    mob->next_position = (sfVector2f) {0, 0};
    mob->velocity = (sfVector2f) {0, 0};
    mob->current_jump = (sfVector2f) {0, 0};
    mob->jump_down = 0;
    mob->gravity = 5;
    mob->misc = NULL;
}

void init_mob_property(mob_t *mob, tag_t *mob_tag)
{
    mob->type = get_property_int(mob_tag, "id", -1);
    mob->knockback = get_property_int(mob_tag, "knockback", 1);
    mob->is_npc = get_property_int(mob_tag, "is_npc", 1);
    mob->life = get_property_int(mob_tag, "health", 10);
    mob->quest_id = get_property_int(mob_tag, "quest_id", -1);
    mob->damage = get_property_int(mob_tag, "damage", 1);
    mob->reach = get_property_int(mob_tag, "reach", 10);
    mob->xp = get_property_int(mob_tag, "xp", 10);
}

mob_t *get_mob_from_id(tag_t *mob_tag, sfVector2f indexes, game_t *game)
{
    mob_t *mob = malloc(sizeof(mob_t));

    init_mob_property(mob, mob_tag);
    mob->start_indexes = indexes;
    mob->animation_list = create_mob_animation_list(mob_tag);
    mob->animation = get_animation_w_name(mob->animation_list,
    get_property(mob_tag, "default_anim"));
    mob->dying_animation = create_animation("assets/effects/dying.png", 7, 1,
    (sfVector2f) {1, 1});
    if (mob->is_npc) {
        mob->msg_list = get_msg_list(mob_tag);
        mob->current_msg = create_msg(game->msg_box, mob->msg_list->data);
    }
    init_mob(mob);
    return (mob);
}

node_t *generate_mobs(int map_id, game_t *game)
{
    node_t *node = NULL;
    node_t *start;
    tag_t *head = parse_xml("maps/mobs.xml");
    mob_layer_t *layer = generate_mobs_layer(head, map_id);
    int id = 0;

    if (layer == NULL || layer->map_id != map_id)
        return (NULL);
    node = malloc(sizeof(node_t));
    start = node;
    for (int i = 0; layer->ids[i]; i++) {
        for (int j = 0; layer->ids[i][j]; j++) {
            id = my_getnbr(layer->ids[i][j]);
            node = id != 0 ? add_mob(node, get_mob_tag(id, head),
        (sfVector2f){i, j}, game): node;
        }
    }
    return (start);
}