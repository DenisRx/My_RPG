/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** npc_events
*/

#include "global.h"
#include <SFML/Graphics.h>

void action_npc(game_t *game, mob_t *mob)
{
    display_dialog(game, game->msg_box, mob->current_msg, 0);
    sfText_setString(mob->current_msg, mob->msg_list->data);
    game->dialog->messages = mob->msg_list;
    game->dialog->current = 0;
    if (mob->type == 2 && game->quests->quest_list == NULL) {
        add_quest(game, "Kill Guitarmos");
        add_quest(game, "Kill Dobongo");
        add_quest(game, "Kill Wizzroboe");
    } else if (mob->type == 11) {
        game->hero->lives = game->life_infos.max_lives;
        game->life_infos.remaining_lives = game->hero->lives;
        return;
    }
}

void click_npc(__attribute__((unused))sfRenderWindow *window, sfEvent event,
game_t *game)
{
    sfMouseButtonEvent mouse_evt = event.mouseButton;
    sfFloatRect npc_bounds;
    sfSprite *hero = game->hero->animation->sprite;
    mob_t *mob;

    if (mouse_evt.button != sfMouseLeft || game->map->mobs == NULL)
        return;
    for (node_t *node = game->map->mobs; node->next; node = node->next) {
        mob = node->data;
        npc_bounds = sfSprite_getGlobalBounds(mob->animation->sprite);
        npc_bounds = get_bounds_with_ratio(npc_bounds, game->res_ratio);
        if (sfFloatRect_contains(&npc_bounds, mouse_evt.x, mouse_evt.y) &&
        sprite_in_reach(hero, mob->animation->sprite, NPC_REACH) &&
        mob->is_npc && !game->dialog->displayed) {
            action_npc(game, mob);
            return;
        }
    }
}