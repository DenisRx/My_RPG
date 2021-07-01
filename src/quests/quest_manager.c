/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** quests_manager
*/

#include "global.h"
#include <SFML/Graphics.h>

void show_quest_panel(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_drawSprite(window, game->quests->box_bg, NULL);
    sfRenderWindow_drawText(window, game->quests->box_title, NULL);
    for (node_t *node = game->quests->quest_list; node; node = node->next) {
        if (((quest_t*)(node->data))->status == 0) {
            sfRenderWindow_drawSprite(window,
            ((quest_t*)node->data)->in_progress, NULL);
        } else {
            sfRenderWindow_drawSprite(window,
            ((quest_t*)node->data)->done, NULL);
        }
        sfRenderWindow_drawText(window, ((quest_t*)node->data)->title, NULL);
    }
}

void check_quests(game_t *game)
{
    if (game->hero->is_moving && game->hero->position.y < 100 &&
    !quests_done(game, 3) && game->hero->movement.y < 0) {
        game->hero->is_moving = 0;
        game->hero->movement = (sfVector2f){0, 0};
        display_dialog(game, game->msg_box,
        get_final_quest_text(GANON_NOT_AVAILABLE), 2000000);
    }
}

int quests_done(game_t *game, int nb_quest)
{
    int count = 0;

    for (node_t *node = game->quests->quest_list; node; node = node->next) {
        if (((quest_t*)node->data)->status == 1)
            count++;
    }
    return (count == nb_quest);
}

sfText *get_final_quest_text(char *message)
{
    sfText *text = create_text(sfFont_createFromFile(MSG_FONT), MSG_SIZE);

    sfText_setString(text, message);
    sfText_setColor(text, sfWhite);
    return (text);
}

void handle_quest(sfRenderWindow *window, game_t *game)
{
    sfFloatRect hero_bounds = sfSprite_getGlobalBounds(game->hero->animation
    ->sprite);
    sfFloatRect box_bounds = sfSprite_getGlobalBounds(game->quests->box_bg);

    if (game->quests->quest_nb == 3 && quests_done(game, 3)) {
        display_dialog(game, game->msg_box,
        get_final_quest_text(GANON_AVAILABLE), 5000000);
        add_quest(game, "Kill Ganon");
        return;
    }
    if (game->quests->quest_nb > 0 &&
    !sfFloatRect_intersects(&hero_bounds, &box_bounds, NULL)) {
        show_quest_panel(window, game);
    }
}