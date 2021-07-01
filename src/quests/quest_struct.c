/*
** EPITECH PROJECT, 2021
** B-MUL-200-BDX-2-1-myrpg-solene.lefeu
** File description:
** quest_struct
*/

#include "global.h"
#include <SFML/Graphics.h>

quests_t *init_quests(void)
{
    quests_t *quests = malloc(sizeof(quests_t));

    quests->box_title = create_texts(MSG_FONT, (sfVector2f){1370, 350},
    sfWhite);
    sfText_setString(quests->box_title, "QUESTS");
    sfText_setCharacterSize(quests->box_title, 30);
    sfText_setStyle(quests->box_title, sfTextUnderlined);
    quests->box_bg = load_sprite(QUEST_BOX);
    sfSprite_setRotation(quests->box_bg, 90);
    sfSprite_setScale(quests->box_bg, (sfVector2f){0.30, 1});
    sfSprite_setPosition(quests->box_bg, (sfVector2f){1580, 350});
    quests->quest_nb = 0;
    quests->quest_list = NULL;
    return (quests);
}

quest_t *create_quest(int id, char *title)
{
    quest_t *quest = malloc(sizeof(quest_t));
    sfVector2f status_pos = {1300, 400 + 50 * (id - 1)};
    sfVector2f title_pos = {1350, status_pos.y};

    quest->id = id;
    quest->title = create_texts(MSG_FONT, title_pos, sfWhite);
    sfText_setString(quest->title, title);
    sfText_setCharacterSize(quest->title, 20);
    quest->status = 0;
    quest->in_progress = load_sprite(EMPTY_CIRCLE);
    quest->done = load_sprite(TICK);
    sfSprite_setPosition(quest->in_progress, status_pos);
    sfSprite_setPosition(quest->done, status_pos);
    return (quest);
}

void add_quest(game_t *game, char *title)
{
    node_t *node = game->quests->quest_list;

    if (node == NULL) {
        game->quests->quest_list = malloc(sizeof(node_t));
        node = game->quests->quest_list;
    } else {
        while (node->next != NULL) {
            node = node->next;
        }
        node->next = malloc(sizeof(node_t));
        node = node->next;
    }
    node->data = create_quest(game->quests->quest_nb + 1, title);
    game->quests->quest_nb++;
    node->next = NULL;
}